import cv2
from ultralytics import YOLO
from flask import Flask
from flask_socketio import SocketIO
import random
import time
import eventlet

app = Flask(__name__)
app.config['SECRET_KEY'] = "akashhhs"
eventlet.monkey_patch()
socketio = SocketIO(app, cors_allowed_origins="*", async_mode='eventlet')

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

def process_video_stream():
    print("🔄 Video processing started!")  # Debug log
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

if __name__ == '__main__':
    socketio.start_background_task(target=process_video_stream)
    socketio.run(app, port=5040, debug=False)