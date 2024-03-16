#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Define the message to be displayed
String message = "ScienceUtsav";

void setup() {
  // initialize the LCD
  lcd.init();

  // Turn on the backlight and print a message.
  lcd.backlight();
}

void loop() {
  // set the cursor to (0,0) and turn on cursor:
  lcd.setCursor(0, 0);
  lcd.cursor();

  // print each character of the message with cursor
  for (int i = 0; i < message.length(); i++) {
    lcd.print(message[i]);
    delay(500);
  }

  // clear screen and turn off cursor for the next loop:
  lcd.clear();
  lcd.noCursor();
}
