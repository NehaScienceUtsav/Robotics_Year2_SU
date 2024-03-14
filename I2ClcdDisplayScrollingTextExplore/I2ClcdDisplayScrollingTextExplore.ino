#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // Initialize the LCD
  lcd.init();

  // Turn on the backlight
  lcd.backlight();

  // Set the initial position for scrolling
  lcd.setCursor(0, 0);

  // Print the initial text
  lcd.print("Science is Awesome");
}

void loop() {
  // Scroll the text to the left
  for (int i = 0; i < 16; i++) {
    lcd.scrollDisplayLeft();
    delay(500); // Adjust the scrolling speed here
  }

  // Pause at the end of the scroll
  delay(1000);

  // Reset the display position
  lcd.home();

  // Pause before starting the next scroll
  delay(1000);
}
