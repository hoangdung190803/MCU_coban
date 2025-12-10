#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define I2C_ADDR 0x27
#define LCD_COLS 16
#define LCD_ROWS 2

LiquidCrystal_I2C lcd(I2C_ADDR, LCD_COLS, LCD_ROWS);

void setup() {
  Wire.begin(21, 22);   // SDA=21, SCL=22 (ESP32)
  lcd.init();
  lcd.backlight();

  lcd.setCursor(0,0);
  lcd.print("ESP32 + LCD");
  lcd.setCursor(0,1);
  lcd.print("Hello World");
}

void loop() {
}
