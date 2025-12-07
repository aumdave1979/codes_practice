% realtime_image_proof_local.m
% Demonstrates "real-time" feasibility for an image signal (simulated frame stream)
% using a single local image: measures per-frame processing time vs. frame period,
% marks missed deadlines and prints a summary.
%
% Save and run in MATLAB. Replace target_fps to test different acquisition rates.

clear; close all; clc

%% ---------- User configuration ----------
imgPath = 'C:\wallpaper\spiderman\5825619.jpg';  % exact image path on local laptop
target_fps = 15;        % desired acquisition frame-rate (Hz)
frame_period = 1/target_fps;
duration_sec = 15;      % total simulation duration in seconds
process_heavy = true;   % true -> heavier processing to test limits
show_text = true;       % overlay text on display
resize_factor = 0.7;    % scale frames for processing/display
%% ----------------------------------------

% Validate image file
if exist(imgPath,'file') ~= 2
    error('Image not found at: %s', imgPath);
end

base_img = imread(imgPath);
if ndims(base_img) == 2
    base_img = repmat(base_img, [1 1 3]);
end

total_frames = round(duration_sec * target_fps);

% Create figure for live display
fig = figure('Name','Real-time Image Proof (Local)','NumberTitle','off','Color',[0 0 0]);
ax = axes('Parent',fig);
axis(ax,'off');
hImg = imshow(zeros(100,100,3,'uint8'),'Parent',ax);
title(ax, sprintf('Local image: %s | target FPS = %d', imgPath, target_fps), 'Color','w', 'Interpreter','none');

% Stats preallocation
proc_times = zeros(total_frames,1);
missed = false(total_frames,1);

% Main loop: simulate frame stream by applying small transforms per frame
global_time = 0;
for k = 1:total_frames
    % Acquire frame (simulate small motion/brightness change)
    I = simulate_frame_from_image(base_img, k);

    % Start processing timer
    tstart = tic;

    % Processing pipeline (resize -> grayscale -> denoise -> edge -> overlay)
    Iproc = imresize(I, resize_factor);
    Igray = rgb2gray(Iproc);

    if process_heavy
        % heavier processing (may be slower on low-power machines)
        Ifilt = imbilatfilt(Igray, 12, 8);    % bilateral filter
        Iedge = edge(Ifilt, 'Canny');
        se = strel('disk',2);
        Iedge = imclose(Iedge, se);
        Iout = imoverlay(im2uint8(mat2gray(Igray)), Iedge, [1 0 0]);
    else
        Iedge = edge(Igray, 'Sobel');
        Iout = imoverlay(im2uint8(mat2gray(Igray)), Iedge, [0 1 0]);
    end

    % Measure processing time
    proc_time = toc(tstart);
    proc_times(k) = proc_time;

    % Deadline check
    if proc_time > frame_period
        missed(k) = true;
    end

    % Update display
    set(hImg, 'CData', Iout);
    if show_text
        status = 'OK';
        if missed(k), status = 'MISSED'; end
        info = sprintf('Frame: %d/%d\nproc=%.3fs (deadline=%.3fs)\nstatus: %s', ...
            k, total_frames, proc_time, frame_period, status);
        title(ax, info, 'Color','w', 'FontSize', 10, 'Interpreter','none');
    end
    drawnow limitrate;

    % Simulate acquisition timing: pause only if processing finished early
    pause_time = frame_period - proc_time;
    if pause_time > 0
        pause(pause_time);
    end

    % advance time (for simulated transforms)
    global_time = global_time + frame_period;

    % early exit if figure closed
    if ~ishandle(fig)
        total_frames = k;
        break;
    end
end

% Summary
valid_frames = min(total_frames, numel(proc_times));
avg_proc = mean(proc_times(1:valid_frames));
max_proc = max(proc_times(1:valid_frames));
n_missed = sum(missed(1:valid_frames));

fprintf('\n--- Real-time image proof summary ---\n');
fprintf('Image path: %s\n', imgPath);
fprintf('Target FPS: %d (frame period = %.4f s)\n', target_fps, frame_period);
fprintf('Frames processed: %d\n', valid_frames);
fprintf('Average processing time per frame: %.4f s\n', avg_proc);
fprintf('Maximum processing time per frame: %.4f s\n', max_proc);
fprintf('Missed deadlines: %d (%.2f%%)\n', n_missed, 100 * n_missed / max(1,valid_frames));
if n_missed == 0
    fprintf('Conclusion: processing met acquisition deadlines -> real-time feasible at this FPS.\n');
else
    fprintf('Conclusion: processing exceeded deadlines for some frames -> reduce load or lower FPS.\n');
end

%% Helper functions

function F = simulate_frame_from_image(img, k)
    % Apply small rotation + brightness jitter + tiny noise to simulate a live frame stream
    ang = 2 * sin(2*pi*(k/30));                 % oscillation in degrees
    J = imrotate(img, ang, 'bilinear', 'crop'); % keep same size
    % small periodic brightness change
    gamma = 1 - 0.02 * abs(sin(k/10));
    J = imadjust(J, [], [], gamma);
    % add tiny Gaussian noise
    noise = uint8(2 * randn(size(J)));
    F = J + noise;
end

function out = imoverlay(Igray_uint8, mask, color)
    % Overlay binary mask onto grayscale uint8 image using RGB color (values range 0..1)
    if ~isa(Igray_uint8,'uint8')
        Igray_uint8 = im2uint8(Igray_uint8);
    end
    rgb = repmat(Igray_uint8, [1 1 3]);
    mask = logical(mask);
    for c = 1:3
        plane = rgb(:,:,c);
        plane(mask) = uint8(255 * color(c));
        rgb(:,:,c) = plane;
    end
    out = rgb;
end
