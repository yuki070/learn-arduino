#include <Arduino.h>

int reapin = 11;
int greenpin = 10;
int bluepin = 9;
int redval, greenval, blueval;
int i = 0;
// put function declarations here:
int myFunction(int, int);

void setup() {
  // put your setup code here, to run once:
  pinMode(reapin, OUTPUT);
  pinMode(greenpin, OUTPUT);
  pinMode(bluepin, OUTPUT);
  pinMode(redval, INPUT);
  pinMode(greenval, INPUT);
  pinMode(blueval, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  i++;
  // if (i < 200) {
  //   redval += 1;
  //   greenval -= 1;
  //   blueval = 1;
  // } else if (i < 400) {
  //   redval -= 1;
  //   greenval = 1;
  //   blueval += 1;
  // } else if (i < 600) {
  //   redval = 1;
  //   greenval += 1;
  //   blueval -= 1;
  // } else {
  //   i = 0;
  // }
  // analogWrite(reapin, redval);
  // analogWrite(greenpin, greenval);
  // analogWrite(bluepin, blueval);
  // Serial.print(i, DEC);
  // Serial.print(" R:");
  // Serial.print(redval, DEC);
  // Serial.print(" G:");
  // Serial.print(greenval, DEC);
  // Serial.print(" B:");
  // Serial.println(blueval, DEC);

  if (i % 3 == 0) {
    analogWrite(reapin, 255);
    analogWrite(greenpin, 0);
    analogWrite(bluepin, 0);
  } else if (i % 3 == 1) {
    analogWrite(reapin, 0);
    analogWrite(greenpin, 255);
    analogWrite(bluepin, 0);
  } else {
    analogWrite(reapin, 0);
    analogWrite(greenpin, 0);
    analogWrite(bluepin, 255);
  }
  delay(1000);
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}