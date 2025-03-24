from flask import Flask, request, jsonify
import tensorflow as tf
import numpy as np
import pandas as pd
import pickle
import os
from datetime import datetime, timedelta
import calendar
import pttest

app = Flask(__name__)

# Load models and parameters on startup
models = {}
with open('./traffic_models/params/preprocessing_params.pkl', 'rb') as f:
    params = pickle.load(f)

for junction in ["junction_annaselai.keras", "junction_lakshmimills.keras", "junction_navaindia.keras", "junction_rmnpuran.keras"]:
    model_path = f'traffic_models/{junction}'
    try:
        if os.path.exists(model_path):
            models[junction] = tf.keras.models.load_model(model_path)
            print(f"✅ Loaded model for {junction}")
        else:
            print(f"❌ Model file not found: {model_path}")
    except Exception as e:
        print(f"❌ Error loading model {junction}: {str(e)}")

# Helper functions for preprocessing
def create_sequence(history_data, steps=32):
    """Create a sequence of the most recent data for prediction"""
    # Make sure history_data is the right length for your model input
    history_data = history_data[-steps:]
    return np.reshape(history_data, (1, len(history_data), 1))

def get_traffic_level(vehicle_count, junction):
    """Categorize traffic levels based on vehicle count thresholds"""
    # You may want to customize these thresholds based on your data
    thresholds = {
        '1': {'light': 10, 'moderate': 20, 'heavy': 30},
        '2': {'light': 15, 'moderate': 25, 'heavy': 35},
        '3': {'light': 12, 'moderate': 22, 'heavy': 32},
        '4': {'light': 8, 'moderate': 18, 'heavy': 28}
    }
    
    t = thresholds.get(junction, thresholds['1'])
    
    if vehicle_count < t['light']:
        return "Light traffic", "green"
    elif vehicle_count < t['moderate']:
        return "Moderate traffic", "yellow"
    elif vehicle_count < t['heavy']:
        return "Heavy traffic", "orange"
    else:
        return "Severe congestion", "red"

# function that actually predicts from the model that is loaded
def predict_traffic(junction, history_data):
    """Predict traffic for a junction based on historical data"""
    model = models.get(junction)
    if model is None:
        raise ValueError(f"No model found for junction {junction}")
    
    # Preprocess the data
    X = create_sequence(history_data, params['sequence_length'])
    
    # Make a prediction
    predicted_count = model.predict(X)[0][0]
    
    # Convert back to original scale
    predicted_vehicles = params['scaler'].inverse_transform([[predicted_count]])[0][0]
    
    return predicted_vehicles

@app.before_request
def log_request():
    app.logger.info(f"Request: {request.method} {request.path} from {request.remote_addr}")
    app.logger.info(f"Headers: {request.headers}")

@app.route('/')
def index():
    return "Welcome to the Traffic Prediction API!"

@app.route('/predict', methods=['GET'])
def predict_traffic():
    try:
        # Get parameters from request
        junction_param = request.args.get('junction', '1')
        date_str = request.args.get('date')
        time_str = request.args.get('time') 
        
        junction_mapping = {
            '1': 'junction_annaselai.keras',
            '2': 'junction_lakshmimills.keras',
            '3': 'junction_navaindia.keras',
            '4': 'junction_rmnpuran.keras'
        }
        
        # Keep track of both model name and junction ID
        if junction_param in junction_mapping:
            junction_model = junction_mapping[junction_param]
            junction_id = junction_param  # Keep the numeric ID for base_traffic lookup
        else:
            junction_model = junction_param
            # Reverse lookup to find junction ID
            junction_id = next((k for k, v in junction_mapping.items() if v == junction_param), '1')
        
        
        if not date_str or not time_str:
            # Use current date/time if not provided
            now = datetime.now()
            date_str = now.strftime('%Y-%m-%d')
            time_str = now.strftime('%H:%M')
        
        # Create datetime object
        dt = datetime.strptime(f"{date_str} {time_str}", '%Y-%m-%d %H:%M')
        
        # Round to nearest hour for prediction
        hour = dt.hour
        day_of_week = calendar.day_name[dt.weekday()]
        
        # Check if we have model for this junction
        if junction not in models:
            return jsonify({
                "error": f"No model available for Junction {junction}"
            }), 404
        
        # Get historical data for the requested junction
        # In production, you would load this from a database
        # For this example, we'll use synthetic data based on patterns
        
        # This is where you'd implement the logic to:
        # 1. Get historical data for this junction
        # 2. Preprocess it using the same transforms from training
        # 3. Create the right input sequence for the model
        # 4. Make prediction and convert back to original scale
        
        # Placeholder for actual prediction logic
        # In a real implementation, you'd use your actual historical data
        # and preprocessing pipeline from the notebook
        
        # Simulate a prediction based on time patterns
        # Replace this with actual model prediction in production
        base_traffic = {
            '1': 15 + (5 if 7 <= hour <= 9 or 16 <= hour <= 18 else 0),
            '2': 20 + (8 if 7 <= hour <= 9 or 16 <= hour <= 18 else 0),
            '3': 12 + (6 if 7 <= hour <= 9 or 16 <= hour <= 18 else 0),
            '4': 10 + (4 if 7 <= hour <= 9 or 16 <= hour <= 18 else 0)
        }
        
        # Adjust for weekends
        weekend_factor = 0.7 if day_of_week in ['Saturday', 'Sunday'] else 1.0
        
        # Get traffic level and color
        predicted_vehicles = int(base_traffic[junction_id] * weekend_factor)
        traffic_level, color = get_traffic_level(predicted_vehicles, junction_id)
        
        return jsonify({
            "junction": junction_model,
            "junction_id": junction_id,
            "datetime": f"{date_str} {time_str}",
            "day": day_of_week,
            "predicted_vehicles": predicted_vehicles,
            "traffic_level": traffic_level,
            "status_color": color
        })
        
    except Exception as e:
        return jsonify({"error": str(e)}), 500

@app.get('/trafficdata')
def getalltrafficdata():
    signalptmap = {
        'SIG001': 'traffic_models/junction_annaselai.keras',
        'SIG002': 'traffic_models/junction_lakshmimills.keras',
        'SIG003': 'traffic_models/junction_navaindia.keras',
        'SIG004': 'traffic_models/junction_rmnpuran.keras'
    }
    
    signalnamemap = {
        'SIG001': 'Anna Salai',
        'SIG002': 'Lakshmi Mills',
        'SIG003': 'Nava India',
        'SIG004': 'Ramanathapuram'
    }
    
    timeintervals = ['8:00', '9:00', '10:00', '11:00', '12:00', '13:00', '14:00']
    
    # use the pre-trained model to predict traffic for each signal
    # target output format is below
    '''
    {
    'SIG001': {
      labels: ['8:00', '9:00', '10:00', '11:00', '12:00', '13:00', '14:00'],
      datasets: [{ data: [65, 78, 82, 75, 68, 71, 85] }],
      title: 'Main St & 5th Ave Traffic'
    },
    'SIG002': {
      labels: ['8:00', '9:00', '10:00', '11:00', '12:00', '13:00', '14:00'],
      datasets: [{ data: [85, 92, 88, 95, 90, 92, 98] }],
      title: 'Broadway & 42nd St Traffic'
    },
    'SIG003': {
      labels: ['8:00', '9:00', '10:00', '11:00', '12:00', '13:00', '14:00'],
      datasets: [{ data: [72, 75, 68, 70, 74, 76, 80] }],
      title: 'Park Ave & 34th St Traffic'
    },
    'SIG004': {
      labels: ['8:00', '9:00', '10:00', '11:00', '12:00', '13:00', '14:00'],
      datasets: [{ data: [60, 65, 62, 58, 64, 70, 72] }],
      title: 'Lexington & 59th St Traffic'
    }
  }
    '''
    
    trafficdata = {}
    for signal in signalptmap:
        junction = signalptmap[signal]
        junctionname = signalnamemap[signal]
        trafficdata[signal] = {
            "labels": timeintervals,
            "datasets": [],
            "title": f"{junctionname}"
        }
        predictions = []
        for time in timeintervals:
            predicted_vehicles = pttest.load_and_predict(junction, f"2025-03-24 {time}", 100, signal)
            predictions.append(predicted_vehicles)

        trafficdata[signal]['datasets'].append({"data": predictions})
    
    return jsonify(trafficdata)
        
if __name__ == '__main__':
    app.run(host='0.0.0.0', debug=True, port=5081)