#include <Arduino.h>
#include "DS1302.h"
bool Flag_KEY_Set = 0;

// put function declarations here:
void Display_RTCC();
// void PrintRawRegisters();

void setup() {
  DS1302_Init();
	Serial.begin(9600);	//设置通讯的波特率为9600
	Serial.println("Welcome to use!");  //发送的内容
	Serial.println("Made by Beetle Electronic Technology!");  //发送的内容
}

void loop() {
	// 调试：先打印原始寄存器值
	// PrintRawRegisters();

	DS1302_GetTime(&DS1302Buffer);            //获取当前RTCC值
	Display_RTCC();

	delay(2000);
}

void Display_RTCC()
{

	if(DS1302Buffer.Year < 10)
	{
		Serial.print("200");
	}
	else
	{
		Serial.print("20");
	}
	Serial.print(DS1302Buffer.Year);
	Serial.print('-');
	Serial.print(DS1302Buffer.Month);
	Serial.print('-');
	Serial.print(DS1302Buffer.Day);

	Serial.print("   ");

	switch(DS1302Buffer.Week)
	{
		case 1:
				Serial.println("Mon");				 //显示星期一
				break;
		case 2:
				Serial.println("Tue");				 //显示星期二
				break;
		case 3:
				Serial.println("Wed");				 //显示星期三
				break;
		case 4:
				Serial.println("Thu");				 //显示星期四
				break;
		case 5:
				Serial.println("Fri");				 //显示星期五
				break;
		case 6:
				Serial.println("Sat");				 //显示星期六
				break;
		case 7:
				Serial.println("Sun");				 //显示星期日
				break;
		default : break;						
	}

	Serial.print(DS1302Buffer.Hour);
	Serial.print(':');
	Serial.print(DS1302Buffer.Minute);
	Serial.print(':');
	Serial.println(DS1302Buffer.Second);
}

// 调试：打印原始寄存器值，便于定位是否为硬件/通信问题
void PrintRawRegisters()
{
	Serial.print("SEC: 0x");
	if(DS1302_Read(DS1302_SECOND) < 16) Serial.print('0');
	Serial.println(DS1302_Read(DS1302_SECOND), HEX);

	Serial.print("MIN: 0x");
	if(DS1302_Read(DS1302_MINUTE) < 16) Serial.print('0');
	Serial.println(DS1302_Read(DS1302_MINUTE), HEX);

	Serial.print("HOUR:0x");
	if(DS1302_Read(DS1302_HOUR) < 16) Serial.print('0');
	Serial.println(DS1302_Read(DS1302_HOUR), HEX);

	Serial.print("DAY: 0x");
	if(DS1302_Read(DS1302_DAY) < 16) Serial.print('0');
	Serial.println(DS1302_Read(DS1302_DAY), HEX);

	Serial.print("MON: 0x");
	if(DS1302_Read(DS1302_MONTH) < 16) Serial.print('0');
	Serial.println(DS1302_Read(DS1302_MONTH), HEX);

	Serial.print("WEEK:0x");
	if(DS1302_Read(DS1302_WEEK) < 16) Serial.print('0');
	Serial.println(DS1302_Read(DS1302_WEEK), HEX);

	Serial.print("YEAR:0x");
	if(DS1302_Read(DS1302_YEAR) < 16) Serial.print('0');
	Serial.println(DS1302_Read(DS1302_YEAR), HEX);

}
