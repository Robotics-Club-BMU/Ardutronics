#include <SoftwareSerial.h>

#define LED 3
#define KNOB 0

void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int val = analogRead(KNOB);
  int ledPower = map(val, 1, 1024, 1, 255);

  String stringOne = "Sensor value: ";
  Serial.println(stringOne + ledPower);
  analogWrite(LED, ledPower);
}
