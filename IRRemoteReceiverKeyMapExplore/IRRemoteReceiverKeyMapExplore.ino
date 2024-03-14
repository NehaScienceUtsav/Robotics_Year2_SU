#include <IRremote.h>

const int IR_RECEIVE_PIN = 2;

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK); // Start the receiver
}

void loop() {
  if (IrReceiver.decode()) {
    IrReceiver.printIRResultShort(&Serial);
    IrReceiver.resume(); // Enable receiving of the next value
  }
}
