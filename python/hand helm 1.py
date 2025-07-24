import cv2
import mediapipe as mp
import numpy as np
import os

# Initialize MediaPipe Hands and drawing utilities
mp_hands = mp.solutions.hands
mp_drawing = mp.solutions.drawing_utils

# Configure MediaPipe Hands
hands = mp_hands.Hands(static_image_mode=False,
                       max_num_hands=4,
                       min_detection_confidence=0.5,
                       min_tracking_confidence=0.5)

# Define the folder containing the images
stored_images_folder = r"E:\\College\\helmet\\images"  # Replace with your folder path

# Load all images in the folder
stored_images = []
for file_name in os.listdir(stored_images_folder):
    file_path = os.path.join(stored_images_folder, file_name)
    image = cv2.imread(file_path, cv2.IMREAD_GRAYSCALE)
    if image is not None:
        stored_images.append((file_name, image))
    else:
        print(f"Warning: Unable to load image '{file_name}'.")

if not stored_images:
    print("Error: No valid images found in the folder!")
    exit()

# Start video capture
cap = cv2.VideoCapture(0)  # 0 is the default camera index

if not cap.isOpened():
    print("Error: Could not open the camera.")
    exit()

print("Press 'q' to exit")

while cap.isOpened():
    success, frame = cap.read()
    if not success:
        print("Ignoring empty frame.")
        continue

    # Flip the image horizontally for a later selfie-view display
    frame = cv2.flip(frame, 1)
    frame_rgb = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
    gray_frame = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

    hand_detected = False
    image_detected = False

    # Process the frame and detect hands
    results = hands.process(frame_rgb)

    # Draw hand landmarks and connections on the frame
    if results.multi_hand_landmarks:
        hand_detected = True
        for hand_landmarks in results.multi_hand_landmarks:
            mp_drawing.draw_landmarks(frame, hand_landmarks, mp_hands.HAND_CONNECTIONS)

    # Perform template matching for each stored image
    for file_name, stored_image in stored_images:
        result = cv2.matchTemplate(gray_frame, stored_image, cv2.TM_CCOEFF_NORMED)
        min_val, max_val, min_loc, max_loc = cv2.minMaxLoc(result)

        # Define a threshold for a match
        threshold = 0.69  # Adjust this value based on your requirements
        if max_val >= threshold:
            image_detected = True
            top_left = max_loc
            h, w = stored_image.shape
            bottom_right = (top_left[0] + w, top_left[1] + h)

            # Draw a rectangle around the matched region
            cv2.rectangle(frame, top_left, bottom_right, (0, 255, 0), 2)
            cv2.putText(frame, f"Match: {file_name}", 
                        (top_left[0], top_left[1] - 10), 
                        cv2.FONT_HERSHEY_SIMPLEX, 0.6, (0, 255, 0), 2)

    # Check if both hand and image are detected simultaneously
    if hand_detected and image_detected:
        cv2.putText(frame, "Hand detected while driving, stop", 
                    (50, 50), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 0, 255), 3)

    # Display the frame
    cv2.imshow('Hand and Helmet Detection', frame)

    # Exit loop if 'q' is pressed
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

# Release resources
cap.release()
cv2.destroyAllWindows()
hands.close()
