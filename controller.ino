// Sensor pins
#define NPK_SENSOR_PIN A0
#define MOISTURE_SENSOR_PIN A1
#define TEMP_SENSOR_PIN A2

// Actuator pins
#define FAN_PIN 8
#define WATER_PUMP_PIN 9
#define MOTOR_IN1 4
#define MOTOR_IN2 5
#define MOTOR_EN 6

// Thresholds (can be adjusted based on crop requirements)
float MOISTURE_THRESHOLD = 50.0;
float TEMP_THRESHOLD = 25.0;

// Sensor values
float npk_values[3];  // N, P, K values
float pH_value;
float moisture_value;
float temperature;

void setup() {
  Serial.begin(9600);
  
  // Initialize pins
  pinMode(FAN_PIN, OUTPUT);
  pinMode(WATER_PUMP_PIN, OUTPUT);
  pinMode(MOTOR_IN1, OUTPUT);
  pinMode(MOTOR_IN2, OUTPUT);
  pinMode(MOTOR_EN, OUTPUT);
  
  // Initial state: all actuators OFF
  digitalWrite(FAN_PIN, LOW);
  digitalWrite(WATER_PUMP_PIN, LOW);
  digitalWrite(MOTOR_IN1, LOW);
  digitalWrite(MOTOR_IN2, LOW);
}

void loop() {
  readSensors();
  controlActuators();
  sendDataToSerial();
  delay(1000);
}

void readSensors() {
  // Simulate NPK sensor readings
  npk_values[0] = random(0, 140);  // N
  npk_values[1] = random(5, 145);  // P
  npk_values[2] = random(5, 205);  // K
  pH_value = random(4.0, 8.0);
  
  // Read actual sensors
  moisture_value = analogRead(MOISTURE_SENSOR_PIN);
  temperature = analogRead(TEMP_SENSOR_PIN);
  
  // Convert analog readings to actual values
  moisture_value = map(moisture_value, 0, 1023, 0, 100);
  temperature = (analogRead(TEMP_SENSOR_PIN) * 0.48875);
}

void controlActuators() {
  // Water pump control
  if (moisture_value < MOISTURE_THRESHOLD) {
    digitalWrite(WATER_PUMP_PIN, HIGH);
  } else {
    digitalWrite(WATER_PUMP_PIN, LOW);
  }
  
  // Temperature control
  if (temperature > TEMP_THRESHOLD) {
    digitalWrite(FAN_PIN, HIGH);
  } else {
    digitalWrite(FAN_PIN, LOW);
  }
}

void sendDataToSerial() {
  // Format: N,P,K,pH,moisture,temperature
  Serial.print(npk_values[0]); Serial.print(",");
  Serial.print(npk_values[1]); Serial.print(",");
  Serial.print(npk_values[2]); Serial.print(",");
  Serial.print(pH_value); Serial.print(",");
  Serial.print(moisture_value); Serial.print(",");
  Serial.println(temperature);
}