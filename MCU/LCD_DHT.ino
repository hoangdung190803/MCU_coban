#include <Wire.h>
#include <DHT.h>
#include <LiquidCrystal_I2C.h>

#define DHTPIN 4
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);

  Wire.begin(21, 22);      // ESP32 SDA=21, SCL=22
  dht.begin();

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("DHT11 & ESP32");
}

void loop() {
  float h = dht.readHumidity();      
  float t = dht.readTemperature();   

  if (isnan(h) || isnan(t)) {
    Serial.println("Sensor Error");
    lcd.setCursor(0, 1);
    lcd.print("Sensor Error    ");
    delay(2000);
    return;
  }

  // ----- Serial -----
  Serial.print("Nhiet do: ");
  Serial.print(t);
  Serial.print(" *C   Do am: ");
  Serial.print(h);
  Serial.println(" %");

  // ----- LCD -----
  lcd.setCursor(0, 0);
  lcd.print("Temp:");
  lcd.print(t);
  lcd.print("C   ");

  lcd.setCursor(0, 1);
  lcd.print("Humi:");
  lcd.print(h);
  lcd.print("%   ");

  delay(2000);
}
