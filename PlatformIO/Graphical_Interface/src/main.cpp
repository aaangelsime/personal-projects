#include <Arduino.h>
#include <Wire.h>
#include "LiquidCrystal_I2C.h"

//I2C address 0x27
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  
  Wire.begin(); // uno r4 I2C sda/scl
  lcd.init(); // initialize lcd object
  lcd.backlight(); //turn backlight on

  lcd.setCursor(0, 0);
  lcd.print("Be a Good Boi");

}

void loop() {
  // put your main code here, to run repeatedly:
}

// // put function definitions here:
// int myFunction(int x, int y) {
//   return x + y;
// }