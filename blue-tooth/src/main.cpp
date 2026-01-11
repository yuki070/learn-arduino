#include <Arduino.h>


void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    byte data = Serial.read();
    Serial.print(data);
  }
  Serial.print("DATA");
  Serial.write("DATA");
}