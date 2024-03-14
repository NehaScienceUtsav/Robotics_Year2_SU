// Define the pins for the ultrasonic sensor
const int trigPin = 8;      // Trigger pin
const int echoPin = 9;      // Echo pin
const int buzzerPin = 2;    // Buzzer pin
const int ledPin = 3;       // Red LED pin

// Define the threshold distances for activating the buzzer and LED
const float buzzerThreshold_cm = 15.0;  // Threshold distance for buzzer activation in cm
const float ledMinThreshold_cm = 15.0;   // Minimum threshold distance for LED activation in cm
const float ledMaxThreshold_cm = 25.0;   // Maximum threshold distance for LED activation in cm

void setup() {
  // Initialize Serial communication
  Serial.begin(9600);

  // Set pin modes
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Trigger the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the pulse duration on the echo pin
  long duration = pulseIn(echoPin, HIGH);

  // Calculate the distance in centimeters and inches
  float distance_cm = duration / 58.2;
  float distance_inches = duration / 148.0;

  // Print the distance to the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance_cm);
  Serial.print(" cm / ");
  Serial.print(distance_inches);
  Serial.println(" inches");

  // Control the buzzer
  digitalWrite(buzzerPin, distance_cm < buzzerThreshold_cm);

  // Control the LED
  digitalWrite(ledPin, distance_cm > ledMinThreshold_cm && distance_cm < ledMaxThreshold_cm);

  // Add a delay between measurements
  delay(1000);
}
