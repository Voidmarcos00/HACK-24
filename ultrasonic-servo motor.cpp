#include <Servo.h>  /

// Create Servo objects
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;  
const int trigPin = 8;
const int echoPin = 7;

void setup() {
  Serial.begin(9600);  
  servo1.attach(9);
  servo2.attach(10);
  servo3.attach(11);
  servo4.attach(12);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // Check ultrasonic sensor and control servo4
  checkUltrasonicSensor();

  int fastDelay = 5; 
  for (int angle = 120; angle >= 0; angle--) {
    servo1.write(angle);
    delay(fastDelay);  
    checkUltrasonicSensor();
  }
  delay(200);  /
  for (int angle = 0; angle <= 120; angle++) {
    servo1.write(angle);
    delay(fastDelay);  
    checkUltrasonicSensor();
  }
  delay(200);  
  for (int angle = 120; angle >= 0; angle--) {
    servo2.write(angle);
    delay(fastDelay);  
    checkUltrasonicSensor();
  }
  delay(200);  
  for (int angle = 0; angle <= 120; angle++) {
    servo2.write(angle);
    delay(fastDelay);  
    checkUltrasonicSensor();
  }
  delay(200); 

  for (int angle = 120; angle >= 0; angle--) {
    servo3.write(angle);
    delay(fastDelay); 
    checkUltrasonicSensor();
  }
  delay(200);  
  for (int angle = 0; angle <= 120; angle++) {
    servo3.write(angle);
    delay(fastDelay);  
    checkUltrasonicSensor();
  }
  delay(200);  
}

// Function to check the ultrasonic sensor and control servo4
void checkUltrasonicSensor() {
  long duration, distance;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echoPin, pulseIn() returns the duration (time) in microseconds
  duration = pulseIn(echoPin, HIGH);

  // Calculate the distance
  distance = (duration / 2) / 29.1;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Control the servo4 based on the distance to turn the camera ON/OFF
  if (distance > 0 && distance <= 10) {  
    servo4.write(90);                           // Set servo4 to 90 degrees (Camera ON)
    Serial.println("CAMERA_ON");
  } else {
    servo4.write(0);                           // Set servo4 to 0 degrees (Camera OFF)
    Serial.println("CAMERA_OFF");
  }
}
