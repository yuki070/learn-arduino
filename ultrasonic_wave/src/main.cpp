#include <Arduino.h>

/*
 * 实验概要：本实验使用Arduino和HC-SR04超声波模块，实现距离测量功能。
 * 通过Trig引脚发送超声波信号，Echo引脚接收回波，计算脉冲时间转换为距离。
 * 距离数据通过串口输出，每500毫秒测量一次。
 */

// Trig引脚，用于发送超声波信号
const int trig = 8;
// Echo引脚，用于接收超声波回波
const int echo = 9;

void setup() {
  pinMode(trig, OUTPUT); // 设置Trig引脚为输出模式
  pinMode(echo, INPUT);  // 设置Echo引脚为输入模式
  Serial.begin(9600);    // 初始化串口通信，波特率9600
}

void loop() {
  int interval = 0; // 存储脉冲持续时间（微秒）
  while (1) { // 无限循环进行测量
    digitalWrite(trig, HIGH);     // 发送高电平触发信号
    delayMicroseconds(15);        // 保持15微秒
    digitalWrite(trig, LOW);      // 结束触发信号
    interval = pulseIn(echo, HIGH); // 测量Echo引脚的高电平持续时间
    float s = interval / 58.00;   // 将时间转换为距离（厘米），公式：距离 = 时间 / 58
                                  // 解释：超声波速度约340m/s=34000cm/s，往返时间需除以2，
                                  // 转换为微秒：34000 / 2 / 1000000 = 0.017 cm/μs，
                                  // 所以距离 ≈ interval * 0.017，即 interval / (1/0.017) ≈ interval / 58
    Serial.print("Distance: ");
    Serial.print(s);              // 输出距离值
    Serial.println(" cm");        // 添加单位
    s = 0; interval = 0;          // 重置变量（可选）
    delay(500);                   // 延时500毫秒
  }
}