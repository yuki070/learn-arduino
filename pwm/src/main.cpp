/*
 * 实验名称：PWM控制LED亮度
 * 实验目的：通过电位器控制LED的亮度，使用Arduino的PWM功能。
 * 硬件连接：
 * - 电位器中间引脚连接到A0 (模拟输入0)
 * - LED阳极连接到引脚11 (PWM输出)，阴极接地
 * 功能描述：
 * - 读取电位器的模拟值 (0-1023)
 * - 将值映射到PWM输出 (0-255)，控制LED亮度
 * - 通过串口输出当前值，便于调试
 */

#include <Arduino.h>

// 定义引脚和变量
int potpin = 0;    // 电位器连接的模拟输入引脚
int ledpin = 11;   // LED连接的PWM输出引脚
int val = 0;       // 存储从电位器读取的值

void setup() {
  // 初始化设置，只运行一次
  pinMode(ledpin, OUTPUT);  // 设置LED引脚为输出模式
  Serial.begin(9600);       // 初始化串口通信，波特率9600
}

void loop() {
  // 主循环，重复执行
  val = analogRead(potpin);        // 从电位器读取模拟值 (0-1023)
  Serial.println(val);             // 将值输出到串口监视器
  analogWrite(ledpin, val / 4);    // 将值映射到PWM输出 (0-255)，控制LED亮度
  delay(10);                       // 延迟10毫秒，避免读取过快
}