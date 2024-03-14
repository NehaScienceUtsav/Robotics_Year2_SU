#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // initialize the LCD
  lcd.init();

  // Turn on the backlight and print a message.
  lcd.backlight();

  // Display "ScienceUtsav" on the LCD
  lcd.print("ScienceUtsav");
}

void loop() {
  // Do nothing here...
}
