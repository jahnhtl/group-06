#include <AFMotor.h>

const int sensorPin = A0;
const int motor1Pin1 = 3;
const int motor1Pin2 = 5;
const int motor2Pin1 = 6;
const int motor2Pin2 = 9;

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);

void setup() {
  Serial.begin(9600);
  motor1.setSpeed(200);
  motor2.setSpeed(200);
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
}

void loop() {
  int sensorValue = analogRead(sensorPin);
  float distance = (6787.0 / (sensorValue - 3.0)) - 4.0;

  Serial.print("Gemessene Entfernung: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  if (distance < 20) {
    // Motor 1 vorwärts, Motor 2 rückwärts
    analogWrite(motor1Pin1, 255);
    analogWrite(motor1Pin2, 0);
    analogWrite(motor2Pin1, 0);
    analogWrite(motor2Pin2, 0);
    motor1.run(FORWARD);
    motor2.run(BACKWARD);
    
  } else if (distance >= 20 && distance < 40) {
    // Motor 1 rückwärts, Motor 2 vorwärts
    analogWrite(motor1Pin1, 0);
    analogWrite(motor1Pin2, 255);
    analogWrite(motor2Pin1, 255);
    analogWrite(motor2Pin2, 0);
    motor1.run(BACKWARD);
    motor2.run(FORWARD);
    
  } else {
    // Alle Motoren stoppen
    analogWrite(motor1Pin1, 0);
    analogWrite(motor1Pin2, 0);
    analogWrite(motor2Pin1, 0);
    analogWrite(motor2Pin2, 0);
    motor1.run(RELEASE);
    motor2.run(RELEASE);
    
  }
  
 
}
