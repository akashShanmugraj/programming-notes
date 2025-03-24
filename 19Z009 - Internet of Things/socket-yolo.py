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
    last_vehicle_count = 0  # Store the last valid count
    frame_skip_counter = 0  # Process every nth frame to reduce CPU load
    
    while True:
        try:
            ret, frame = cap.read()
            if not ret:
                print("❌ Error: Failed to grab frame")
                # Use the last known vehicle count instead of resetting
                current_vehicle_count = last_vehicle_count
            else:
                # Process frame and detect vehicles
                frame_skip_counter += 1
                
                # Only process every 3rd frame to reduce CPU load but keep connection active
                if frame_skip_counter >= 3:
                    frame_skip_counter = 0
                    results = model(frame)
                    
                    # Initialize counters for each vehicle type
                    cars = 0
                    trucks = 0
                    motorcycles = 0
                    buses = 0
                    pedestrians = 0
                    
                    # YOLO class mapping: car=2, motorcycle=3, bus=5, truck=7, person=0
                    for r in results:
                        for obj in r.boxes:
                            if obj.conf > confidence_threshold:
                                class_id = int(obj.cls)
                                if class_id == 2:
                                    cars += 1
                                elif class_id == 3:
                                    motorcycles += 1
                                elif class_id == 5:
                                    buses += 1
                                elif class_id == 7:
                                    trucks += 1
                                elif class_id == 0:
                                    pedestrians += 1
                    
                    # Calculate total vehicle count
                    current_vehicle_count = cars + trucks + motorcycles + buses
                    
                    # Store the counts in a dictionary
                    vehicle_data = {
                        'cars': cars,
                        'trucks': trucks,
                        'motorcycles': motorcycles,
                        'buses': buses,
                        'pedestrians': pedestrians,
                        'total': current_vehicle_count
                    }
                    
                    # Store the valid counts
                    last_vehicle_count = current_vehicle_count
                    last_vehicle_data = vehicle_data
                else:
                    # Use the last known counts for skipped frames
                    current_vehicle_count = last_vehicle_count
                    vehicle_data = last_vehicle_data if 'last_vehicle_data' in locals() else {
                        'cars': 0, 'trucks': 0, 'motorcycles': 0, 'buses': 0, 'pedestrians': 0, 'total': 0
                    }
            
            # Rest of the code to determine congestion level
            congestion_level = "L"
            if current_vehicle_count > 10:
                congestion_level = "H"
            elif current_vehicle_count > 5:
                congestion_level = "M"
            
            baseobj = { "id": "SIG001", "name": "Anna Silai", "status": "CONGESTED", "efficiency": "82", "vehicles": "430" }
            
            resobj = [
                { "id": "SIG002", "name": "Lakshmi Mills", "status": "CONGESTED", "efficiency": "62", "vehicles": "430" },
                { "id": "SIG003", "name": "Nava India", "status": "NORMAL", "efficiency": "78", "vehicles": "310" },
                { "id": "SIG004", "name": "Ramanathapuram", "status": "OPTIMAL", "efficiency": "91", "vehicles": "190" }
            ]
            
            detectiondata = [
    {
      "name": "Cars",
      "population": vehicle_data['cars'],
      "color": "#3B82F6",
      "legendFontColor": "#94A3B8"
    },
    {
      "name": "Trucks",
      "population": vehicle_data['trucks'],
      "color": "#8B5CF6",
      "legendFontColor": "#94A3B8"
    },
    {
      "name": "Motorcycles",
      "population": vehicle_data['motorcycles'],
      "color": "#10B981",
      "legendFontColor": "#94A3B8"
    },
    {
      "name": "Buses",
      "population": vehicle_data['buses'],
      "color": "#F59E0B",
      "legendFontColor": "#94A3B8"
    },
    {
      "name": "Pedestrians",
      "population": vehicle_data['pedestrians'],
      "color": "#EF4444",
      "legendFontColor": "#94A3B8"
    }
  ]
            
            baseobj["vehicles"] = current_vehicle_count
            if congestion_level == "H":
                baseobj["status"] = "CONGESTED"
                baseobj["efficiency"] = "62"
            elif congestion_level == "M":
                baseobj["status"] = "NORMAL"
                baseobj["efficiency"] = "78"
            else:
                baseobj["status"] = "OPTIMAL"
                baseobj["efficiency"] = "91"
                
            resobj.append(baseobj)
            
            print(f"📡 Emitting: {current_vehicle_count} vehicles, Congestion: {congestion_level}")
            socketio.emit('traffic_update', {'count': current_vehicle_count, 'congestion_level': congestion_level, 'timestamp': time.time()})
            socketio.emit('intersection', baseobj)
            socketio.emit('detection', detectiondata)

            eventlet.sleep(0.1)
            
        except Exception as e:
            print(f"Error in video processing: {e}")
            # Keep the last known count and continue
            eventlet.sleep(0.5)
if __name__ == '__main__':
    Thread(target=process_video_stream, daemon=True).start()
    socketio.run(app, port=6130, debug=False, host='0.0.0.0')