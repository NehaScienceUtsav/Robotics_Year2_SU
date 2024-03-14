#include <NewPing.h>

// Define the pins for the ultrasonic sensor
const int trigPin = 8;        // Trigger pin
const int echoPin = 9;        // Echo pin
const int buzzerPin = 2;      // Buzzer pin
const int redLedPin = 3;      // Red LED pin

// Define the threshold distances for activating the buzzer and LED
const int buzzerThreshold_cm = 15;    // Buzzer threshold distance in cm
const int ledLowerThreshold_cm = 15;  // Lower threshold for activating the LED
const int ledUpperThreshold_cm = 25;  // Upper threshold for activating the LED

// Create an instance of the NewPing library
NewPing sonar(trigPin, echoPin);

void setup() {
  // Initialize Serial communication
  Serial.begin(9600);

  // Set pin modes
  pinMode(buzzerPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
}

void loop() {
  // Measure distance using the NewPing library
  unsigned int distance_cm = sonar.ping_cm();

  // Convert distance from centimeters to inches
  float distance_in = distance_cm / 2.54;

  // Print the distance to the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance_cm);
  Serial.print(" cm, ");
  Serial.print(distance_in, 2);  // Print distance with 2 decimal places
  Serial.println(" inches");

  // Control the buzzer
  digitalWrite(buzzerPin, distance_cm <= buzzerThreshold_cm);

  // Control the LED
  digitalWrite(redLedPin, distance_cm > ledLowerThreshold_cm && distance_cm < ledUpperThreshold_cm);

  // Add a delay between measurements
  delay(1000);
}
