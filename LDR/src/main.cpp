/*
 * LDR 实验概要
 * 本实验使用光敏电阻（LDR）检测环境光线强度，根据光线强度控制LED的开关。
 * 通过数字输入读取LDR的状态（高/低电平），并使用数字输出控制LED。
 * 实验目的：学习Arduino的数字输入（digitalRead）和数字输出（digitalWrite）的使用。
 * 注意：此版本使用数字模式，LDR需连接到数字引脚，并可能需要外部电路调整阈值。
 */

#include <Arduino.h>

int ledpin = 11;  // LED连接的数字引脚
int ldrpin = 8;   // LDR连接的数字引脚
int val = 0;      // 存储LDR读取的数字值（0或1）

void setup() {
  // 初始化设置，只运行一次
  pinMode(ledpin, OUTPUT);  // 设置LED引脚为输出模式
  pinMode(ldrpin, INPUT);   // 设置LDR引脚为输入模式
  Serial.begin(9600);       // 初始化串口通信，波特率9600
}

void loop() {
  // 主循环，重复执行
  val = digitalRead(ldrpin);  // 读取LDR的数字值（0或1）
  Serial.println(val);        // 通过串口输出LDR值
  digitalWrite(ledpin, val);  // 使用数字输出控制LED（val=1时亮，val=0时灭）
  delay(10);                  // 延时10ms，避免读取过于频繁
}