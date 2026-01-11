#include <Arduino.h>

int latchPin = 8;
int clockPin = 12;
int dataPin = 11;

unsigned char table[] = {0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80,
  0b10000001,
  0b10000010,
  0b10000100,
  0b10001000,
  0b10010000,
  0b10100000,
  0b11000000,
  0b11000001,
  0b11000010,
  0b11000100,
  0b11001000,
  0b11010000,
  0b11100000,
  0b11100001,
  0b11100010,
  0b11100100,
  0b11101000,
  0b11110000,
  0b11110001,
  0b11110010,
  0b11110100,
  0b11111000,
  0b11111001,
  0b11111010,
  0b11111100,
  0b11111101,
  0b11111110,
  0b11111111
};	//LED状态显示的变量

void setup() {
  pinMode(latchPin,OUTPUT);
  pinMode(clockPin,OUTPUT);
  pinMode(dataPin,OUTPUT);
}

void loop() {
  for(int i=0; i<36; i++)
  {
    digitalWrite(latchPin,LOW); //将ST_CP口上面加低电平让芯片准备好接收数据
    shiftOut(dataPin,clockPin,MSBFIRST,table[i]);
    														//串行数据输入引脚为dataPin，时钟引脚为clockPin，执行MSB有限发送，发送数据table[i]
    digitalWrite(latchPin,HIGH); //将ST_CP这个针脚恢复到高电平
    delay(500);				//延时500ms
  }
}
