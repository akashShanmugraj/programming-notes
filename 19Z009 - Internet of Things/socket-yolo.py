import cv2
from ultralytics import YOLO
from flask import Flask
from flask_socketio import SocketIO
import random
import time
import eventlet
import signal
import sys
from threading import Thread

app = Flask(__name__)
app.config['SECRET_KEY'] = "akashhhs"
eventlet.monkey_patch()
socketio = SocketIO(app, cors_allowed_origins="*", transports=['websocket', 'polling'])

@socketio.on('message')
def handle_message(data):
    print(f'Received message: {data}')
    socketio.send(f'Server received: {data}')
    
@socketio.on('connect')
def random_message():
    print('Client connected')
    socketio.send(f'Random message: {random.randint(1, 100)}')


# Load YOLOv8 model
try:
    model = YOLO("yolov8n.pt")  
except Exception as e:
    print(f"❌ Error: Could not load YOLO model. {e}")
    exit()

# IP Camera stream (Update with actual IP)
camera_url = "http://192.168.29.89:4747/mjpegfeed"
cap = cv2.VideoCapture(camera_url, cv2.CAP_FFMPEG)

if not cap.isOpened():
    print(f"❌ Error: Could not open video stream at {camera_url}.")
    exit()
else:
    print(f"✅ Successfully opened video stream at {camera_url}.")

vehicle_classes = [2, 3, 5, 7]  
confidence_threshold = 0.4  

def signal_handler(sig, frame):
    print("Shutting down server...")
    cap.release()
    cv2.destroyAllWindows()
    socketio.stop()
    sys.exit(0)

signal.signal(signal.SIGINT, signal_handler)
signal.signal(signal.SIGTERM, signal_handler)


def process_video_stream():
    print("🔄 Video processing started!")
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

        congestion_level = "L"
        if current_vehicle_count > 10:
            congestion_level = "H"
        elif current_vehicle_count > 5:
            congestion_level = "M"

        print(f"📡 Emitting: {current_vehicle_count} vehicles, Congestion: {congestion_level}")
        socketio.emit('vehicle_count', {'count': current_vehicle_count, 'congestion_level': congestion_level, 'timestamp': time.time()})
        
        eventlet.sleep(0)  # Yield control back to the event loop

    cap.release()
    cv2.destroyAllWindows()

if __name__ == '__main__':
    Thread(target=process_video_stream, daemon=True).start()
    socketio.run(app, port=6130, debug=False)