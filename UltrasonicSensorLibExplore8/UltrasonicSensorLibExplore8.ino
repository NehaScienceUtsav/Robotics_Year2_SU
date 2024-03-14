#include <NewPing.h>

// Define the pins for the ultrasonic sensor
const int trigPin = 8;   // Trigger pin
const int echoPin = 9;   // Echo pin
const int buzzerPin = 2; // Buzzer pin
const int redLedPin = 3; // Red LED pin

// Define the threshold distances for activating the buzzer and LED
const int buzzerThreshold_cm = 15; // Buzzer threshold distance in cm
const int ledLowerThreshold_cm = 15; // Lower threshold for activating the LED
const int ledUpperThreshold_cm = 25; // Upper threshold for activating the LED

// Create an instance of the NewPing library
NewPing sonar(trigPin, echoPin);

void setup() {
  // Initialize Serial communication
  Serial.begin(9600);

  // Set the buzzer pin as an output
  pinMode(buzzerPin, OUTPUT);
  
  // Set the red LED pin as an output
  pinMode(redLedPin, OUTPUT);
}

void loop() {
  // Measure distance using the NewPing library
  unsigned int distance_cm = sonar.ping_cm();

  // Check if the distance measurement is valid
  if (distance_cm != 0) {
    // Print the distance to the Serial Monitor
    Serial.print("Distance: ");
    Serial.print(distance_cm);
    Serial.println(" cm");

    // Check if the distance is less than or equal to the buzzer threshold distance
    if (distance_cm <= buzzerThreshold_cm) {
      // Beep the buzzer
      digitalWrite(buzzerPin, HIGH);
    } else {
      // Turn off the buzzer
      digitalWrite(buzzerPin, LOW);
    }
    
    // Check if the distance is within the range to activate the red LED
    if (distance_cm > ledLowerThreshold_cm && distance_cm < ledUpperThreshold_cm) {
      // Turn on the red LED
      digitalWrite(redLedPin, HIGH);
    } else {
      // Turn off the red LED
      digitalWrite(redLedPin, LOW);
    }
  } else {
    Serial.println("Error: No echo received");
  }

  // Add a delay between measurements (adjust as needed)
  delay(1000);
}

