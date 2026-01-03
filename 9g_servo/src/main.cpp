#include <Arduino.h>
#include <Servo.h>

/*
 * 实验概要：本实验使用Arduino和9g舵机，实现舵机的往复旋转。
 * 舵机从0度旋转到180度，然后从180度旋转回0度，循环往复。
 * 使用Servo库控制舵机位置，并通过延时控制旋转速度。
 */

Servo myServo;  // 创建舵机对象，用于控制舵机
int pos = 0;    // 舵机位置变量，存储当前角度

void setup() {
  myServo.attach(8); // 将舵机信号线连接到数字引脚8
}

void loop() {
  // 从0度旋转到180度
  for (pos = 0; pos <= 180; pos += 1) {
    myServo.write(pos); // 设置舵机位置为pos度
    delay(15);          // 延时15毫秒，让舵机到达位置
  }
  // 从180度旋转回0度
  for (pos = 180; pos >= 0; pos -= 1) {
    myServo.write(pos); // 设置舵机位置为pos度
    delay(15);          // 延时15毫秒，让舵机到达位置
  }
}
