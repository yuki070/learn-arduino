#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// 0x27 0x3F are the I2C addresses for the LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);

// put function declarations here:

void setup() {
  // put your setup code here, to run once:
  lcd.init();                      // initialize the lcd
  lcd.backlight();
  Serial.begin(9600);
  // Wire.begin();
  // Serial.begin(115200);
  // Serial.println("I2C 地址扫描开始...");
}

void loop() {
  // byte count = 0;
  // for (byte i = 8; i < 120; i++) {
  //   Wire.beginTransmission(i);
  //   if (Wire.endTransmission() == 0) {
  //     Serial.print("找到 I2C 设备，地址：0x");
  //     Serial.println(i, HEX);
  //     count++;
  //   }
  // }
  // if (count == 0) {
  //   Serial.println("未找到任何 I2C 设备，请检查连接。");
  // }
  // delay(5000);

  // if (Serial.available()) {
  //   // wait a bit for the entire message to arrive
  //   delay(100);
  //   // clear the screen
  //   lcd.clear();
  //   // read all the available characters
  //   while (Serial.available() > 0) {
  //     // display each character to the LCD
  //     lcd.write(Serial.read());
  //   }
  // }
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Hello, World!");
  lcd.setCursor(0, 1);
  lcd.print("LCD I2C Test");
  delay(2000);
}
