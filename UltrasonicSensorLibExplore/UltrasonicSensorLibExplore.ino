#include <NewPing.h>

// Define the pins for the ultrasonic sensor
const int trigPin = 8;  // Trigger pin
const int echoPin = 9;  // Echo pin
const int buzzerPin = 2; // Buzzer pin

// Define the threshold distance for activating the buzzer
const int thresholdDistance_cm = 15; // Threshold distance in cm

// Create an instance of the NewPing library
NewPing sonar(trigPin, echoPin);

void setup() {
  // Initialize Serial communication
  Serial.begin(9600);

  // Set the buzzer pin as an output
  pinMode(buzzerPin, OUTPUT);
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

    // Check if the distance is less than or equal to the threshold distance
    if (distance_cm <= thresholdDistance_cm) {
      // Beep the buzzer
      digitalWrite(buzzerPin, HIGH);
    } else {
      // Turn off the buzzer
      digitalWrite(buzzerPin, LOW);
    }
  } else {
    Serial.println("Error: No echo received");
  }

  // Add a delay between measurements (adjust as needed)
  delay(1000);
}
