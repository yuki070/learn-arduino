/*
 * 实验名称：LCD显示屏实验
 * 实验目的：学习使用LiquidCrystal库控制LCD显示屏，显示静态文本和动态时间。
 * 硬件连接：
 * - LCD RS引脚连接到Arduino引脚12
 * - LCD EN引脚连接到Arduino引脚11
 * - LCD D4-D7引脚连接到Arduino引脚5,4,3,2
 * 功能描述：
 * - 初始化LCD显示屏（16列2行）
 * - 第一行显示"Hello, World!"
 * - 第二行显示Arduino运行时间（秒）
 */

#include <Arduino.h>
#include <LiquidCrystal.h>

// 定义LCD引脚连接
int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;

// 创建LiquidCrystal对象，指定引脚
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // 初始化设置，只运行一次
  lcd.begin(16, 2);              // 初始化LCD，16列2行
  lcd.print("Hello, World!");     // 在第一行显示"Hello, World!"
}

void loop() {
  // 主循环，重复执行
  lcd.setCursor(0, 1);            // 设置光标到第二行第一列
  lcd.print(millis() / 1000);     // 显示运行时间（秒）
  lcd.print(" sec");              // 添加单位
}