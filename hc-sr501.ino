#define LED_PIN 4
#define PIR_PIN 14



void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(PIR_PIN, INPUT);
  Serial.begin(9600);
}

void loop() {
    int pirState = digitalRead(PIR_PIN);

  if (pirState == 1) {
    digitalWrite(LED_PIN, HIGH);
    Serial.println("co chuyen dong");
  }

  else if (pirState == 0) {
    digitalWrite(LED_PIN, LOW);
    Serial.println("khong co chuyen dong");
  }
  delay (500);
}
