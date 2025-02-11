# IoT-Based Eco-Balanced Greenhouse System

### Overview

The IoT-Based Eco-Balanced Greenhouse System is an intelligent and automated solution designed to enhance agricultural efficiency by integrating real-time monitoring, crop recommendations, and energy consumption estimation. This system utilizes Arduino-based hardware for sensor data collection and machine learning models for crop prediction and electricity cost analysis, providing farmers with data-driven insights for sustainable farming.

### Features

**Real-Time Monitoring:** Sensors collect data on soil nutrients (NPK), pH levels, temperature, and moisture.

**Automated Actuation:** Controls water pumps, fans, and motors based on environmental conditions.

**Crop Recommendation:** A machine learning model predicts the best crops based on soil and climate parameters.

**Energy Consumption Estimation:** Predicts the electricity cost for cultivating specific crops.

**Web-Based Dashboard:** Displays real-time sensor readings, recommendations, and analytics (Planned Feature).

### Technologies Used

**Hardware:** Arduino Mega (R3), NPK Sensor, Soil Moisture Sensor, Temperature Sensor, H-Bridge, DC Motors

**Software:** Python, Scikit-Learn, Pandas, NumPy, Joblib

**Machine Learning:** Random Forest Classifier for crop prediction

**IoT & Automation:** Arduino-based control of actuators

###Installation & Usage

#### 1. Hardware Setup

-Connect the sensors and actuators to the Arduino Mega.

-Upload the greenhouse.ino sketch to the board.

-Open the Serial Monitor to view real-time data.

#### 2. Crop Prediction Model

##### Install dependencies:

-pip install pandas numpy scikit-learn joblib

##### Train the model:

-python crop_prediction.py

-Save the trained model (crop_predictor_model.pkl) for future predictions.

#### 3. Energy Consumption Estimator

##### Run the estimator script:

-python energy_estimator.py

-Enter the crop name to get the estimated electricity consumption.

####Future Enhancements

-Integration with a Web Dashboard for real-time monitoring.

-AI-driven Crop Disease Detection.

-Smart Irrigation Scheduling based on weather forecasts.

####Contributors

**Afaq Ahmad** – Project Developer

Open for Contributions! Feel free to fork and improve the project.

**License**

This project is licensed under the MIT License.

Feel free to Star ⭐ this repository if you find it useful!

