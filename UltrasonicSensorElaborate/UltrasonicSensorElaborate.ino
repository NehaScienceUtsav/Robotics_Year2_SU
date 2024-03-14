#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Initialize the I2C LCD library with the I2C address
LiquidCrystal_I2C lcd(0x27, 16, 2); // Set the LCD I2C address (0x27 for most displays)

// Define pins for the ultrasonic sensor
const int trigPin = 9; // Trigger pin
const int echoPin = 8; // Echo pin

// Variables for calculating distance
long duration;
int distanceCm;

void setup() {
  // Initialize I2C LCD
  lcd.init();
  lcd.backlight();

  // Set the initial position on the LCD
  lcd.setCursor(0, 0);
  lcd.print("Distance (cm):");

  // Set up the ultrasonic sensor pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Start serial communication for debugging (optional)
  Serial.begin(9600);
}

void loop() {
  // Trigger the ultrasonic sensor to send a pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the pulse duration on the echo pin
  duration = pulseIn(echoPin, HIGH);

  // Calculate the distance in centimeters
  distanceCm = duration / 58.2; // Divide by 58.2 to convert to cm

  // Display the distance on the I2C LCD
  lcd.setCursor(0, 1);
  lcd.print("               "); // Clear previous distance
  lcd.setCursor(0, 1);
  lcd.print(distanceCm);

  // Print the distance to the serial monitor (optional)
  Serial.print("Distance: ");
  Serial.print(distanceCm);
  Serial.println(" cm");

  delay(500); // Delay between measurements
}
