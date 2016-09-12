
#include <LiquidCrystal.h>

//                RS EN D4 D5  D6  D7
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() {
  lcd.begin(16, 2);
  lcd.print("Electronics");
  lcd.setCursor(0, 1);
  lcd.print("Cookbook");
}

void loop() {
  lcd.setCursor(10, 1);
  lcd.print(millis() / 1000);
}

