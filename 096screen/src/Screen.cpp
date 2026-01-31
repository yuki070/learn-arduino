#include "Screen.h"

Screen::Screen()
  : display(128, 64, &Wire, -1)
{
}

bool Screen::begin(uint8_t addr) {
  if (!display.begin(SSD1306_SWITCHCAPVCC, addr)) {
    return false;
  }
  delay(2000);
  display.clearDisplay();
  display.setTextColor(WHITE);
  return true;
}

void Screen::clear() {
  display.clearDisplay();
}

void Screen::showTempHum(float temperature, float humidity) {
  display.clearDisplay();
  display.setTextSize(2);

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
}

void Screen::showSensorValue(int analogInput)
{
  display.clearDisplay();
  display.setTextSize(2);

  display.setCursor(0, 0);
  display.print("value: ");
  display.setCursor(24, 15);
  display.print(analogInput);

  display.display();
}
