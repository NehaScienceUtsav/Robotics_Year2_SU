// Define the pins for the ultrasonic sensor
const int trigPin = 8;  // Trigger pin
const int echoPin = 9; // Echo pin
const int buzzerPin = 2; // Buzzer pin

// Define the threshold distance for activating the buzzer
const float thresholdDistance_cm = 15.0; // Threshold distance in cm

void setup() {
  // Initialize Serial communication
  Serial.begin(9600);

  // Set the trigger pin as an OUTPUT
  pinMode(trigPin, OUTPUT);
  // Set the echo pin as an INPUT
  pinMode(echoPin, INPUT);
  
  // Set the buzzer pin as an OUTPUT
  pinMode(buzzerPin, OUTPUT);
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

  // Calculate the distance in centimeters (you can also calculate it in inches)
  int distance_cm = duration / 58.2;

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

  // Add a delay between measurements (adjust as needed)
  delay(1000);
}
