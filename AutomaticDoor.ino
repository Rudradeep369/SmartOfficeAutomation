#include <Servo.h>  // Include the Servo library to control the servo motor
Servo myservo;      // Create a Servo object named myservo

int pir = 7;        // Digital pin connected to the PIR motion sensor

void setup() {
  pinMode(pir, INPUT);  // Set the PIR pin as an input
  myservo.attach(8);    // Attach the servo to digital pin 8
  Serial.begin(9600);  // Initialize serial communication at 9600 baud rate
}

void loop() {
  int motionDetected = digitalRead(pir);  // Read the PIR sensor's state (HIGH or LOW)
  Serial.println(motionDetected);         // Print the sensor state to the serial monitor

  if (motionDetected == HIGH) {
    // If motion is detected (PIR sensor reads HIGH), do the following:
    myservo.write(180);   // Rotate the servo to 180 degrees
    delay(1000);          // Wait for 3 seconds
  } else {
    // If no motion is detected (PIR sensor reads LOW), do the following:
    myservo.write(0);     // Rotate the servo to 0 degrees (or any other desired position)
  }
}