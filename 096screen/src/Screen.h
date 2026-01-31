#ifndef SCREEN_H
#define SCREEN_H

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

class Screen {
public:
  Screen();
  bool begin(uint8_t addr = 0x3C);
  void clear();
  void showTempHum(float temperature, float humidity);

private:
  Adafruit_SSD1306 display;
};

#endif // SCREEN_H
