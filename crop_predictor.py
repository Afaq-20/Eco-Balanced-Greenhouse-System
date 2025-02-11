import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.ensemble import RandomForestClassifier
from sklearn.metrics import accuracy_score, classification_report
import joblib

class CropPredictor:
    def __init__(self):
        self.model = None
        self.scaler = StandardScaler()
        
    def load_data(self, file_path):
        self.data = pd.read_csv(file_path)
        return self.data
    
    def preprocess_data(self):
        X = self.data.drop('label', axis=1)
        y = self.data['label']
        
        # Scale the features
        X_scaled = self.scaler.fit_transform(X)
        
        return train_test_split(X_scaled, y, test_size=0.2, random_state=42)
    
    def train_model(self):
        X_train, X_test, y_train, y_test = self.preprocess_data()
        
        self.model = RandomForestClassifier(n_estimators=100, random_state=42)
        self.model.fit(X_train, y_train)
        
        # Evaluate model
        y_pred = self.model.predict(X_test)
        accuracy = accuracy_score(y_test, y_pred)
        print(f"Model Accuracy: {accuracy:.2f}")
        print("\nClassification Report:")
        print(classification_report(y_test, y_pred))
        
    def save_model(self, model_path='crop_predictor_model.pkl'):
        if self.model is not None:
            joblib.dump(self.model, model_path)
            joblib.dump(self.scaler, 'scaler.pkl')
            print(f"Model saved to {model_path}")
    
    def predict_crop(self, features):
        if self.model is None:
            raise Exception("Model not trained yet!")
        
        # Scale features
        features_scaled = self.scaler.transform(features)
        prediction = self.model.predict(features_scaled)
        probabilities = self.model.predict_proba(features_scaled)
        
        return prediction[0], probabilities[0]

def main():
    predictor = CropPredictor()
    
    # Load and train model
    data = predictor.load_data('Crop_recommendation.csv')
    predictor.train_model()
    predictor.save_model()
    
    # Example prediction
    sample_features = np.array([[26,73,21,31.33170829,57.97429171,4.946263888,161.7820226]])
    prediction, probabilities = predictor.predict_crop(sample_features)
    print(f"\nPredicted crop: {prediction}")
    print("Prediction probabilities:")
    for crop, prob in zip(predictor.model.classes_, probabilities):
        print(f"{crop}: {prob:.2f}")

if __name__ == "__main__":
    main()