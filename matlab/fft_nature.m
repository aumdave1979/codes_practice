%% realtime_ecg_with_fft.m
% Real-time ECG streaming demo + live FFT of the current window.
clear; close all; clc

%% --- User settings ---
mode = "synthetic";    % "synthetic" or "file"
fs = 360;              % sampling rate (Hz) for synthetic
duration = 20;         % seconds of simulated data
chunk_ms = 100;        % how often new samples arrive (ms)
window_sec = 6;        % seconds shown in time-domain and used for FFT
show_freq_limit = 50;  % x-axis limit for FFT plot (Hz)
%% ----------------------

% (path to the earlier uploaded screenshot — kept here if you want to display it)
debug_image = '/mnt/data/bad956da-3b73-4881-933b-971ec2ee1f8f.png';

%% --- Generate or load ECG ---
if strcmp(mode,"file")
    if exist('ecg.mat','file')~=2
        error('Missing ecg.mat (must contain variables ecg, fs)');
    end
    data = load('ecg.mat');
    x = data.ecg(:);
    fs = data.fs;
    total_samples = length(x);
    duration = total_samples / fs;
else
    total_samples = round(fs * duration);
    t = (0:total_samples-1)'/fs;
    x = 0.01*randn(total_samples,1);
    hr_mean = 70/60;
    rr_interval = 1/hr_mean;
    beat_times = 0:rr_interval:duration;
    for bt = beat_times
        idx = round(bt*fs)+1;
        if idx <= total_samples
            % R-peak
            w = round(0.06*fs);
            gidx = max(1,idx-w):min(total_samples,idx+w);
            gauss = exp(-((gidx - idx)/(0.02*fs)).^2);
            x(gidx) = x(gidx) + 1.0 * gauss(:);
            % P-wave
            pidx = idx - round(0.18*fs);
            if pidx > 0
                pidxs = max(1,pidx-round(0.05*fs)):min(total_samples,pidx+round(0.05*fs));
                p_gauss = exp(-((pidxs - pidx)/(0.03*fs)).^2);
                x(pidxs) = x(pidxs) + 0.08 * p_gauss(:);
            end
            % T-wave
            tidx = idx + round(0.22*fs);
            if tidx <= total_samples
                tidxs = max(1,tidx-round(0.08*fs)):min(total_samples,tidx+round(0.08*fs));
                t_gauss = exp(-((tidxs - tidx)/(0.04*fs)).^2);
                x(tidxs) = x(tidxs) + 0.18 * t_gauss(:);
            end
        end
    end
    % baseline wander
    x = x + 0.15*sin(2*pi*0.33*t) + 0.03*sin(2*pi*0.07*t);
end

%% --- Streaming parameters ---
chunk_samples = max(1, round(chunk_ms * fs / 1000));
n_chunks = ceil(length(x) / chunk_samples);
window_samples = round(window_sec * fs);
deadlines = chunk_samples / fs;

%% --- Figure and axes (time + freq) ---
fig = figure('Name','Real-time ECG + FFT','NumberTitle','off','Position',[200 200 1000 500]);
% Time-domain plot (top)
ax1 = subplot(2,1,1);
hold(ax1,'on');
h_time = plot(ax1, nan(1,window_samples), nan(1,window_samples), 'LineWidth', 1);
xlabel(ax1,'Time (s)')
ylabel(ax1,'Amplitude')
title(ax1,'ECG (time domain)')
xlim(ax1,[0 window_sec])

% Frequency-domain plot (bottom)
ax2 = subplot(2,1,2);
hold(ax2,'on');
h_freq = plot(ax2, nan, nan, 'LineWidth', 1.2);
xlabel(ax2,'Frequency (Hz)')
ylabel(ax2,'Magnitude')
title(ax2,'FFT of last window')
xlim(ax2,[0 show_freq_limit])

% Text for showing dominant freq & timings
txtInfo = uicontrol('Style','text','Units','pixels','Position',[820 430 160 60],...
    'String','', 'BackgroundColor',[0.94 0.94 0.94], 'FontSize',10);

%% --- Buffers & stats ---
buffer_signal = zeros(0,1);
buffer_time = zeros(0,1);
start_sample = 1;
global_time = 0;
proc_times = zeros(n_chunks,1);
fft_times = zeros(n_chunks,1);

% Precompute HANN window function for FFT (updated size each iteration)
for k = 1:n_chunks
    % Acquire next chunk
    s = start_sample;
    e = min(start_sample + chunk_samples - 1, length(x));
    chunk = x(s:e);
    ns = length(chunk);
    t_chunk = (0:ns-1)'/fs + global_time;

    % Start processing timer
    tic;
    % simple baseline removal
    chunk_processed = chunk - movmean(chunk, round(0.2*fs));
    proc_time = toc;
    proc_times(k) = proc_time;

    % Update buffers (keep last window_samples)
    buffer_signal = [buffer_signal; chunk_processed];
    buffer_time = [buffer_time; t_chunk];
    if length(buffer_signal) > window_samples
        keep = length(buffer_signal) - window_samples + 1;
        buffer_signal = buffer_signal(keep:end);
        buffer_time = buffer_time(keep:end);
    end

    % Update time-domain plot
    newest_time = buffer_time(end);
    xdata = buffer_time - newest_time + window_sec; % map so rightmost is newest (window_sec)
    set(h_time, 'XData', xdata, 'YData', buffer_signal);

    % Compute FFT of current window (zero-pad to next pow2)
    N = length(buffer_signal);
    if N < 4
        % not enough data yet: skip FFT
        set(h_freq,'XData',[], 'YData',[]);
        dominant_freq = NaN;
        fft_proc_time = 0;
    else
        tic;
        Nfft = 2^nextpow2(N);
        win = hann(N);
        % apply window and compute FFT
        Y = fft(buffer_signal .* win, Nfft);
        P2 = abs(Y)/N;
        P1 = P2(1:Nfft/2+1);
        P1(2:end-1) = 2*P1(2:end-1);
        f = fs*(0:(Nfft/2))/Nfft;
        % update plot (limit to show_freq_limit)
        idx_lim = f <= show_freq_limit;
        set(h_freq, 'XData', f(idx_lim), 'YData', P1(idx_lim));
        % find dominant frequency (peak excluding DC)
        [~, idx_peak] = max(P1(2:end));
        dominant_freq = f(idx_peak+1); % +1 because skipped DC
        fft_proc_time = toc;
    end
    fft_times(k) = fft_proc_time;

    % Update info text (processing times and dominant freq)
    info_str = sprintf('Chunk %d/%d\nproc=%.3f s\nfft=%.3f s\npeak=%.2f Hz', ...
        k, n_chunks, proc_time, fft_proc_time, dominant_freq);
    set(txtInfo,'String',info_str);

    drawnow limitrate

    % Check deadlines: show red vertical line on time plot if miss
    if (proc_time + fft_proc_time) > deadlines
        % missed deadline: visual marker at right edge
        y = ylim(ax1);
        delete(findobj(ax1,'Tag','deadline'));
        line(ax1,[window_sec window_sec], y, 'Color','r', 'LineStyle','--', 'Tag','deadline');
    else
        delete(findobj(ax1,'Tag','deadline'));
    end

    % Simulate acquisition delay (sleep for remainder)
    pause_time = deadlines - (proc_time + fft_proc_time);
    if pause_time > 0
        pause(pause_time);
    end

    % Advance
    global_time = global_time + ns/fs;
    start_sample = e + 1;

    if ~ishandle(fig)
        break; % closed by user
    end
end

%% --- Summary ---
avg_proc = mean(proc_times(proc_times>0));
avg_fft = mean(fft_times(fft_times>0));
missed = sum((proc_times+fft_times) > deadlines);
fprintf('\nReal-time + FFT summary:\n');
fprintf('Total chunks: %d\n', n_chunks);
fprintf('Avg processing time (per chunk): %.4f s\n', avg_proc);
fprintf('Avg FFT time (per chunk): %.4f s\n', avg_fft);
fprintf('Chunk interval (deadline): %.4f s\n', deadlines);
fprintf('Missed deadlines: %d (%.2f%%)\n', missed, 100*missed/max(1,n_chunks));

% Optional: show spectrogram at end (uncomment to view)
% figure; spectrogram(x, hann(256), 200, 1024, fs, 'yaxis'); title('Spectrogram of Full Signal');

%% End of script
