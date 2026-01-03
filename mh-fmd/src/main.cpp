/*
 * MH-FMD 实验概要
 * 本实验使用蜂鸣器（buzzer）模块产生7个标准的音符（do re mi fa sol la si）。
 * 通过精确控制蜂鸣器的开关频率，实现C4到B4的音调。
 * 实验目的：学习Arduino的数字输出控制和音符频率的使用。
 * 修改：程序将依次播放7个音符（C4到B4），每个音符播放1秒。
 * 注意：蜂鸣器为低电平触发，低电平时发声，高电平时静音。
 */

#include <Arduino.h>

int buzzer = 8;  // 定义蜂鸣器连接的引脚号
int button = 7;

// 定义7个音符的半周期延时（微秒），对应标准频率
unsigned int noteHalfPeriods[7] = {1915, 1703, 1520, 1433, 1276, 1136, 1012};  // C4, D4, E4, F4, G4, A4, B4
int val;

void setup() {
  // 初始化设置，只运行一次
  pinMode(buzzer, OUTPUT);  // 设置蜂鸣器引脚为输出模式
  pinMode(button, INPUT); // 设置按钮引脚为输入模式
}

void loop() {
  val = digitalRead(button);
  // 按钮按下才播放，否则跳过
  if (val == LOW) {
    delay(100); // 消抖延时
    digitalWrite(buzzer, HIGH);  // 确保静音
    return;
  }
  // 主循环，重复执行
  // 播放7个音符
  for (int k = 0; k < 7; k++) {
    unsigned int halfPeriod = noteHalfPeriods[k];  // 当前音符的半周期（微秒）
    unsigned long startTime = millis();  // 记录开始时间
    while (millis() - startTime < 1000) {  // 播放1秒
      digitalWrite(buzzer, LOW);   // 蜂鸣器发声（低电平触发）
      delayMicroseconds(halfPeriod);
      digitalWrite(buzzer, HIGH); // 蜂鸣器静音（高电平）
      delayMicroseconds(halfPeriod);
    }
    digitalWrite(buzzer, HIGH);  // 确保静音
    delay(100);  // 音符间间隔100ms
  }

  // 播放完毕后，等待一段时间再重复
  delay(2000);  // 等待2秒后重新播放
}