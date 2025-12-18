#include <DHT.h>
#define DHTPIN 4 //chan duoc ket noi de truyen du lieu la chan 4
#define DHTTYPE DHT11

DHT dht (DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("DHT11 text");

  dht.begin(); // ham khoi tao camr bien dht
}

void loop() {
  delay(02000);
  float h = dht.readHumidity(); // doc do am
  float t = dht.readTemperature(); // doc nhiet do
  
  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));

  Serial.print(t);
  Serial.print(F("°C "));
}
