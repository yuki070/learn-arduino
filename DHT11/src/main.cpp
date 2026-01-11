#include <Arduino.h>
#include <DHT.h>
#include <DHT_U.h>

DHT dht(4, DHT11);

uint32_t delayMS;


void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  if (dht.read()) {
    float temperature = dht.readTemperature();
    float humidity = dht.readHumidity();

    Serial.print("温度: ");
    Serial.print(temperature);
    Serial.print(" °C, 湿度: ");
    Serial.print(humidity);
    Serial.println(" %");
  } else {
    Serial.println("Failed to read from DHT sensor!");
  }
  delay(2000);
}
