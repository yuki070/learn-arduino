#include <Arduino.h>

/*
 * 实验概要：本实验使用Arduino和4x4膜键盘，实现按键检测功能。
 * 通过扫描行列引脚，检测按键按下，并将对应的字符输出到串口。
 * 键盘布局：
 * 1 2 3 A
 * 4 5 6 B
 * 7 8 9 C
 * * 0 # D
 *
 * 引脚顺序（左到右）：行引脚为11,10,9,8；列引脚为7,6,5,4
 */

// 定义键盘的行和列数量
const int numRows = 4;
const int numCols = 4;
// 去抖延时时间（毫秒）
const int debounceTime = 20;
// 键盘映射表，对应每个按键的字符
const char keymap[numRows][numCols] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

// 行引脚数组（输入引脚）
const int rowPins[numRows] = {11,10,9,8};
// 列引脚数组（输出引脚）
const int colPins[numCols] = {7,6,5,4};

// 检测按键并返回对应的字符
char getKey() {
  char key = 0; // 初始化按键值为0
  // 扫描每一列
  for (int col = 0; col < numCols; col++) {
    digitalWrite(colPins[col], LOW); // 将当前列设置为低电平，激活该列
    // 检查每一行
    for (int row = 0; row < numRows; row++) {
      if (digitalRead(rowPins[row]) == LOW) { // 检测到按键按下
        delay(debounceTime); // 去抖延时
        if (digitalRead(rowPins[row]) == LOW) { // 再次确认按键按下
          key = keymap[row][col]; // 获取对应的字符
          while (digitalRead(rowPins[row]) == LOW); // 等待按键释放
        }
      }
    }
    digitalWrite(colPins[col], HIGH); // 将当前列设置为高电平，停用该列
  }
  return key; // 返回检测到的按键字符
}

void setup() {
  Serial.begin(9600); // 初始化串口通信，波特率9600
  // 设置行引脚为输入模式，并上拉
  for (int row = 0; row < numRows; row++) {
    pinMode(rowPins[row], INPUT);
    digitalWrite(rowPins[row], HIGH); // 启用内部上拉电阻
  }
  // 设置列引脚为输出模式，并初始化为高电平
  for (int col = 0; col < numCols; col++) {
    pinMode(colPins[col], OUTPUT);
    digitalWrite(colPins[col], HIGH); // 初始为高电平
  }
}

void loop() {
  char key = getKey(); // 获取按键
  if (key != 0) { // 如果有按键按下
    Serial.print("Key Pressed: ");
    Serial.println(key); // 输出按键字符
  }
}
