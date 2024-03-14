const int trigPin = 9;  // Trigger pin of ultrasonic sensor
const int echoPin = 10; // Echo pin of ultrasonic sensor
const int relayPin = 7; // Relay pin to control water flow

const int dispensingThreshold = 10;  // Threshold distance for dispensing water (adjust as needed)
const int dispensingDuration = 5000; // Dispensing duration in milliseconds (adjust as needed)
const int delayBetweenMeasurements = 2000; // Delay between measurements in milliseconds (adjust as needed)

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(relayPin, OUTPUT);
}

void loop() {
  long duration, distance;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration * 0.034 / 2);

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance < dispensingThreshold) {
    Serial.println("Dispensing water...");
    digitalWrite(relayPin, HIGH); // Turn on relay to dispense water
    delay(dispensingDuration); // Dispense water for the specified duration
    digitalWrite(relayPin, LOW); // Turn off relay
    Serial.println("Water dispensed.");
    delay(delayBetweenMeasurements); // Wait for the specified delay before checking again
  }
}
