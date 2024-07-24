#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

int x = 0;
int input = A0;  // Analog input pin for the counter
int state = 0;
int counter = 0;

LiquidCrystal_I2C lcd(0x27, 16, 2); // Set the LCD address to 0x27 for a 16 chars and 2 line display

void setup() {
  lcd.init(); // Initialize the LCD
  lcd.backlight(); // Turn on the backlight

  // Print a message to the LCD.
  lcd.setCursor(0, 0);
  lcd.print("  Turn counter ");
  lcd.setCursor(0, 1);
  lcd.print(x);
  lcd.print("     =turn  ");

  pinMode(input, INPUT); // Set the input pin
}

void loop() {
  counter = digitalRead(input); // Read the input from the analog pin

  if (state == 0) {
    if (counter == HIGH) {
      state = 1;
      x = x + 1;
      lcd.setCursor(0, 1);
      lcd.print("                "); // Clear the previous count
      lcd.setCursor(0, 1);
      lcd.print(x);
      lcd.print("     =turn  ");
    }
  }

  if (counter == LOW) {
    state = 0;
  }

  delay(50); // Add a small delay to debounce the input
}
