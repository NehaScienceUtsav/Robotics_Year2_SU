#include <IRremote.h>

const int IR_RECEIVE_PIN = 2;
const int redPin = 5;
const int greenPin = 3;

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK); // Start the receiver
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}

void loop() {
  if (IrReceiver.decode()) {
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
    IrReceiver.printIRResultShort(&Serial);

    // Combine cases for the same action
    switch (IrReceiver.decodedIRData.decodedRawData) {
      case 0xBF40FF00: // Keypad button "5"
        Serial.println("5");
        analogWrite(redPin, 255);
        break;

      case 0xBA45FF00: // Keypad button "1"
        Serial.println("1");
        analogWrite(redPin, 150);
        break;

      case 0xB946FF00: // Keypad button "2"
        Serial.println("2");
        analogWrite(redPin, 200);
        break;

      default:
        break;
    }

    IrReceiver.resume(); // Enable receiving of the next value
  }
}
