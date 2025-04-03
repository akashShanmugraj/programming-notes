import cv2
import torch
import serial
import time
from ultralytics import YOLO
from serial import Serial  # Correct import for Serial

# Connect to Arduino (Update COM port accordingly)
arduino = Serial(port="/dev/tty.usbmodem14101", baudrate=9600, timeout=1)  # Change to your actual port

# Load YOLOv8 model
try:
    model = YOLO("yolov8n.pt")  
except Exception as e:
    print(f"❌ Error: Could not load YOLO model. {e}")
    exit()

# IP Camera stream (Update with actual IP)
camera_url = "http://192.168.234.226:4747/mjpegfeed"
cap = cv2.VideoCapture(camera_url, cv2.CAP_FFMPEG)

if not cap.isOpened():
    print(f"❌ Error: Could not open video stream at {camera_url}.")
    exit()
else:
    print(f"✅ Successfully opened video stream at {camera_url}.")

vehicle_classes = [2, 3, 5, 7]  
confidence_threshold = 0.4  

while True:
    ret, frame = cap.read()
    if not ret:
        print("❌ Error: Failed to grab frame")
        break

    results = model(frame)

    current_vehicle_count = sum(
        1 for r in results for obj in r.boxes 
        if int(obj.cls) in vehicle_classes and obj.conf > confidence_threshold
    )

    congestion_level = "L"  # Default: Low
    if current_vehicle_count > 10:
        congestion_level = "H"  # High
    elif current_vehicle_count > 5:
        congestion_level = "M"  # Medium

    # Send congestion level to Arduino
    arduino.write(congestion_level.encode())

    # Display results
    annotated_frame = results[0].plot()
    cv2.putText(annotated_frame, f"Current Vehicles: {current_vehicle_count}", (20, 40),
                cv2.FONT_HERSHEY_SIMPLEX, 1, (255, 0, 0), 2)
    cv2.putText(annotated_frame, f"Congestion: {congestion_level}", (20, 80),
                cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 0, 255), 2)

    cv2.imshow("🚦 Traffic AI - Detection & Counting", annotated_frame)

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()
arduino.close()