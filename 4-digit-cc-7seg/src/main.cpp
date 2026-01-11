#include <Arduino.h>

/**
 * 4位共阴极数码管
 * 连线：13,12,11,10号引脚连接com1,com2,com3,com4
 *       2~9号引脚分别连接a,b,c,d,e,f,g,dp段
 */

#define SEG_A 2
#define SEG_B 3
#define SEG_C 4
#define SEG_D 5
#define SEG_E 6
#define SEG_F 7
#define SEG_G 8
#define SEG_H 9

#define COM1 13
#define COM2 12
#define COM3 11
#define COM4 10

void Display(unsigned char com,unsigned char num, bool dp = false);

unsigned char table[10][8] =
{
	{0,	0,	1,	1,	1,	1,	1,	1},			//0
	{0,	0,	0,	0,	0,	1,	1,	0},			//1
	{0,	1,	0,	1,	1,	0,	1,	1},			//2
	{0,	1,	0,	0,	1,	1,	1,	1},			//3
	{0,	1,	1,	0,	0,	1,	1,	0},			//4
	{0,	1,	1,	0,	1,	1,	0,	1},			//5
	{0,	1,	1,	1,	1,	1,	0,	1},			//6
	{0,	0,	0,	0,	0,	1,	1,	1},			//7
	{0,	1,	1,	1,	1,	1,	1,	1},			//8
	{0,	1,	1,	0,	1,	1,	1,	1}			//9
};

float value = 0.001;
float increment = 0.001;
bool running = true;

void setup() {
  pinMode(SEG_A,OUTPUT);		//设置为输出引脚
	pinMode(SEG_B,OUTPUT);
	pinMode(SEG_C,OUTPUT);
	pinMode(SEG_D,OUTPUT);
	pinMode(SEG_E,OUTPUT);
	pinMode(SEG_F,OUTPUT);
	pinMode(SEG_G,OUTPUT);
	pinMode(SEG_H,OUTPUT);

	pinMode(COM1,OUTPUT);
	pinMode(COM2,OUTPUT);
	pinMode(COM3,OUTPUT);
	pinMode(COM4,OUTPUT);
  Serial.begin(9600);
}

void displayFloat(float val) {
  int decimalPlaces;
  if (val < 10.0) {
    decimalPlaces = 3;
  } else if (val < 100.0) {
    decimalPlaces = 2;
  } else if (val < 1000.0) {
    decimalPlaces = 1;
  } else {
    decimalPlaces = 0;
  }

  long displayVal;
  if (decimalPlaces == 3) {
    displayVal = round(val * 1000);
  } else if (decimalPlaces == 2) {
    displayVal = round(val * 100);
  } else if (decimalPlaces == 1) {
    displayVal = round(val * 10);
  } else {
    displayVal = round(val);
  }

  int digits[4];
  digits[0] = (displayVal / 1000) % 10;
  digits[1] = (displayVal / 100) % 10;
  digits[2] = (displayVal / 10) % 10;
  digits[3] = displayVal % 10;

	int dp_com = 0;
	if (decimalPlaces > 0) {
		dp_com = 4 - decimalPlaces; // 小数点应位于左侧的位：3位小数 -> 小数点在第1位
	}

  Serial.print("Value: ");
  Serial.println(val, 4);
	for (int i = 0; i < 4; i++) {
		bool dp = (dp_com == i + 1);
		Display(i + 1, digits[i], dp);
		delay(3); // 快速刷新每位，减少可见切换
	}
}

unsigned long lastIncMillis = 0;
const unsigned long incInterval = 300; // 300ms 增量间隔

void loop() {
	// 持续刷新显示（每次 displayFloat 会快速扫描四位）
	displayFloat(value);

	// 非阻塞地每 incInterval 增加一次值
	unsigned long now = millis();
	if (running && (now - lastIncMillis >= incInterval)) {
		lastIncMillis = now;
		value += increment;
		if (value >= 10.0 && increment == 0.001) {
			increment = 0.01;
		} else if (value >= 100.0 && increment == 0.01) {
			increment = 0.1;
		} else if (value >= 1000.0 && increment == 0.1) {
			increment = 1.0;
		}
		if (value >= 9999.0) {
			running = false; // 到达上限后停止更新
		}
	}
}

void Display(unsigned char com,unsigned char num, bool dp)			//显示函数，com可选数值范围1-4，num可选数值范围0-9
{
	// 先清除段位，避免上一位残影
	digitalWrite(SEG_A,LOW);
	digitalWrite(SEG_B,LOW);
	digitalWrite(SEG_C,LOW);
	digitalWrite(SEG_D,LOW);
	digitalWrite(SEG_E,LOW);
	digitalWrite(SEG_F,LOW);
	digitalWrite(SEG_G,LOW);
	digitalWrite(SEG_H,LOW);

	// 默认都灭位（共阴极：HIGH 非选中）
	digitalWrite(COM1,HIGH);
	digitalWrite(COM2,HIGH);
	digitalWrite(COM3,HIGH);
	digitalWrite(COM4,HIGH);

	// 选通当前位（拉低）
	switch(com)                        //选通位选
	{
		case 1:
			digitalWrite(COM1,LOW);     //选择位1
			break;
		case 2:
			digitalWrite(COM2,LOW);     //选择位2
			break;
		case 3:
			digitalWrite(COM3,LOW);     //选择位3
			break;
		case 4:
			digitalWrite(COM4,LOW);     //选择位4
			break;
		default:break;
	}

	digitalWrite(SEG_A,table[num][7]);			//a查询码值表
	digitalWrite(SEG_B,table[num][6]);
	digitalWrite(SEG_C,table[num][5]);
	digitalWrite(SEG_D,table[num][4]);
	digitalWrite(SEG_E,table[num][3]);
	digitalWrite(SEG_F,table[num][2]);
	digitalWrite(SEG_G,table[num][1]);
	digitalWrite(SEG_H,dp ? HIGH : LOW);  // 小数点
}
