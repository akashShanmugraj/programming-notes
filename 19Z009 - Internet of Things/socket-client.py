import socketio

# Create a Socket.IO client
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

@sio.event
def vehicle_count(data):
    print(f"Vehicle Count: {data['count']}, Congestion Level: {data['congestion_level']}, Timestamp: {data['timestamp']}")

@sio.on('vehicle_count')
def vehicle_count(data):
    print(f"🚗 Vehicle Count: {data['count']}, 🚦 Congestion Level: {data['congestion_level']}, 🕒 Timestamp: {data['timestamp']}")


sio.connect('http://127.0.0.1:5040', transports=['websocket', 'polling'])
sio.emit('message', 'Hello from client')
print("✅ Connected!")  # Debug message
sio.wait()
