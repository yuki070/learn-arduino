#include <stdio.h>
#include <stdlib.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>
#include <DHT_U.h>

DHT dht(4, DHT11);

Adafruit_SSD1306 display(128, 64, &Wire, -1);

void setup() {
  dht.begin();

  Serial.begin(115200); //打开串口通讯，设置传输速率为115200字节每秒

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }
  delay(2000);
  display.clearDisplay();
  display.setTextColor(WHITE);
}

int flag = 1;

void loop() {
  // 清空显示
  display.clearDisplay();
  display.setTextSize(2);

  if (dht.read()) {
    float temperature = dht.readTemperature();
    float humidity = dht.readHumidity();

    display.setCursor(0, 0);
    display.print("temp: ");
    display.setCursor(24, 15);
    display.print(temperature);
    display.print(" C");
    display.setCursor(0, 35);
    display.print("hum: ");
    display.setCursor(24, 50);
    display.print(humidity);
    display.print(" %");

    display.display();
  } else {
    Serial.println("Failed to read from DHT sensor!");
  }


  // 3秒刷新显示内容
  delay(1000);
}