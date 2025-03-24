import pickle
import os

# Path to the saved parameters file
params_path = os.path.join(os.getcwd(), "traffic_models", "params", "preprocessing_params.pkl")

# Load the preprocessing parameters
with open(params_path, "rb") as f:
    preprocessing_params = pickle.load(f)

# Extract parameters for all models
params_model_1 = preprocessing_params['1']
params_model_2 = preprocessing_params['2']
params_model_3 = preprocessing_params['3']
params_model_4 = preprocessing_params['4']

# Example usage:
print("Model 1 Params:", params_model_1)
print("Model 2 Params:", params_model_2)
print("Model 3 Params:", params_model_3)
print("Model 4 Params:", params_model_4)

import numpy as np
import tensorflow as tf
import pickle
import os
from sklearn.preprocessing import LabelEncoder
from datetime import datetime

# Load preprocessing parameters
params_path = os.path.join(os.getcwd(), "traffic_models", "params", "preprocessing_params.pkl")
with open(params_path, "rb") as f:
    preprocessing_params = pickle.load(f)

# Load parameters for a specific model (e.g., '1')
params = preprocessing_params['1']  # Change this based on which model you're using

MEAN = params['mean']
STD = params['std']
DIFF_INTERVAL = params['diff_interval']

# Encode weekday names
day_encoder = LabelEncoder()
day_encoder.fit(["Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"])

def process_datetime(user_datetime):
    dt = datetime.strptime(user_datetime, "%Y-%m-%d %H:%M")  
    features = [
        dt.year,
        dt.month,
        dt.day,
        dt.hour,
        day_encoder.transform([dt.strftime("%A")])[0],
    ]
    return np.array(features).reshape(1, -1)

def load_and_predict(model_path, user_input, last_known_value):
    model = tf.keras.models.load_model(model_path)
    
    input_data = process_datetime(user_input)  

    # Predict the differenced value
    diff_prediction = model.predict(input_data)

    # Inverse transform (denormalization)
    actual_diff = (diff_prediction * STD) + MEAN

    # Reconstruct the actual vehicle count using the last known value
    predicted_count = last_known_value + (actual_diff * DIFF_INTERVAL)

    # print("Predicted Vehicle Count:", round(predicted_count.flatten()[0]))
    return abs(round(predicted_count.flatten()[0]))


# load_and_predict("traffic_models/junction_annaselai.keras", "2025-03-24 08:00", 1000) 
# load_and_predict("traffic_models/junction_annaselai.keras", "2025-03-24 09:00", 1000) 
# load_and_predict("traffic_models/junction_annaselai.keras", "2025-03-24 10:00", 1000) 
# load_and_predict("traffic_models/junction_annaselai.keras", "2025-03-24 11:00", 1000) 
# load_and_predict("traffic_models/junction_annaselai.keras", "2025-03-24 12:00", 1000) 
# load_and_predict("traffic_models/junction_annaselai.keras", "2025-03-24 13:00", 1000) 
# load_and_predict("traffic_models/junction_annaselai.keras", "2025-03-24 14:00", 1000) 
