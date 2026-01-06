#Skeleton CV
"""
Reads video frames one by one
Uses MediaPipe to detect:
    body joints(pose)
    hands & fingers
Draws skeleton overlay
Displays the video in real time
"""
import cv2
import mediapipe as mp

# Use the direct paths to avoid the AttributeError
from mediapipe.python.solutions import drawing_utils as mp_drawing
from mediapipe.python.solutions import pose as mp_pose
from mediapipe.python.solutions import hands as mp_hands

# Initialize webcam
cap = cv2.VideoCapture(0)

# Initialize pose and hand detectors
# These names now match the direct imports above
pose_tracker = mp_pose.Pose(min_detection_confidence=0.5, min_tracking_confidence=0.5)
hands_tracker = mp_hands.Hands(min_detection_confidence=0.5, min_tracking_confidence=0.5)

while cap.isOpened():
    ret, frame = cap.read()
    if not ret:
        break

    frame = cv2.flip(frame, 1)  # Mirror image for natural movement
    rgb_frame = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)

    # Detect pose
    pose_results = pose_tracker.process(rgb_frame)
    if pose_results.pose_landmarks:
        mp_drawing.draw_landmarks(
            frame, pose_results.pose_landmarks, mp_pose.POSE_CONNECTIONS)

    # Detect hands
    hand_results = hands_tracker.process(rgb_frame)
    if hand_results.multi_hand_landmarks:
        for hand_landmarks in hand_results.multi_hand_landmarks:
            mp_drawing.draw_landmarks(
                frame, hand_landmarks, mp_hands.HAND_CONNECTIONS)

    cv2.imshow("MediaPipe Multi-Tracker", frame)
    
    # Press 'q' to exit
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()
