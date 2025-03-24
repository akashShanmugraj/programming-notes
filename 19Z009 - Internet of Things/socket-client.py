import socketio
import traceback

sio = socketio.Client(logger=True, engineio_logger=True)

@sio.event
def connect():
    print('Connected to server')

@sio.event
def disconnect():
    print('Disconnected from server')

@sio.event
def message(data):
    print(f'Received message: {data}')

# Remove the duplicate event handler, keep only one:
@sio.event
def vehicle_count(data):
    print(f"🚗 Vehicle Count: {data['count']}, 🚦 Congestion Level: {data['congestion_level']}, 🕒 Timestamp: {data['timestamp']}")

# Add error handling for connection issues
try:
    sio.connect('http://127.0.0.1:6130', wait_timeout=30)
    sio.emit('message', 'Hello from client')
    print("✅ Connected!")
    sio.wait()
except Exception as e:
    print(f"❌ Connection error: {e}")
    print(f"Error type: {type(e).__name__}")
    print(f"Error details:\n{traceback.format_exc()}")