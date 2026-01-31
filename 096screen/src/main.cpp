#include <stdio.h>
#include <stdlib.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "Screen.h"
#include <DHT.h>
#include <DHT_U.h>

DHT dht(4, DHT11);

Screen screen;

void setup() {
  dht.begin();

  Serial.begin(115200); //打开串口通讯，设置传输速率为115200字节每秒

  if (!screen.begin(0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }
}

void loop() {
  if (dht.read()) {
    float temperature = dht.readTemperature();
    float humidity = dht.readHumidity();
    screen.showTempHum(temperature, humidity);
  } else {
    Serial.println("Failed to read from DHT sensor!");
  }

  // 1秒刷新显示内容
  delay(1000);
}