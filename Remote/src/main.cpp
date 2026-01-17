#include <Arduino.h>
#include <IRremote.hpp>
#define IR_RECEIVE_PIN 11

const uint32_t btn1 = 0xBA45FF00;
const uint32_t btn2 = 0xB946FF00;
const uint32_t btn3 = 0xB847FF00;
const uint32_t btn4 = 0xBB44FF00;
const uint32_t btn5 = 0xBF40FF00;
const uint32_t btn6 = 0xBC43FF00;
const uint32_t btn7 = 0xF807FF00;
const uint32_t btn8 = 0xEA15FF00;
const uint32_t btn9 = 0xF609FF00;
const uint32_t btn10 = 0xE916FF00;
const uint32_t btn11 = 0xE619FF00;
const uint32_t btn12 = 0xF20DFF00;
const uint32_t btn13 = 0xF30CFF00;
const uint32_t btn14 = 0xE718FF00;
const uint32_t btn15 = 0xA15EFF00;
const uint32_t btn16 = 0xF708FF00;
const uint32_t btn17 = 0xE31CFF00;
const uint32_t btn18 = 0xA55AFF00;
const uint32_t btn19 = 0xBD42FF00;
const uint32_t btn20 = 0xAD52FF00;
const uint32_t btn21 = 0xB54AFF00;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // // Establish serial communication
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK); // Start the receiver
}

void loop() {
  // put your main code here, to run repeatedly:
  if (IrReceiver.decode()) {
      // Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX); // Print "old" raw data
      // IrReceiver.printIRResultShort(&Serial); // Print complete received data in one line
      // IrReceiver.printIRSendUsage(&Serial);   // Print the statement required to send this data
      if (IrReceiver.decodedIRData.decodedRawData == btn1) {
        Serial.println("CH-");
      } else if (IrReceiver.decodedIRData.decodedRawData == btn2) {
        Serial.println("CH");
      } else if (IrReceiver.decodedIRData.decodedRawData == btn3) {
        Serial.println("CH+");
      } else if (IrReceiver.decodedIRData.decodedRawData == btn4) {
        Serial.println("|<<");
      } else if (IrReceiver.decodedIRData.decodedRawData == btn5) {
        Serial.println(">>|");
      } else if (IrReceiver.decodedIRData.decodedRawData == btn6) {
        Serial.println(">>||");
      } else if (IrReceiver.decodedIRData.decodedRawData == btn7) {
        Serial.println("-");
      } else if (IrReceiver.decodedIRData.decodedRawData == btn8) {
        Serial.println("+");
      } else if (IrReceiver.decodedIRData.decodedRawData == btn9) {
        Serial.println("EQ");
      } else if (IrReceiver.decodedIRData.decodedRawData == btn10) {
        Serial.println("0");
      } else if (IrReceiver.decodedIRData.decodedRawData == btn11) {
        Serial.println("100+");
      } else if (IrReceiver.decodedIRData.decodedRawData == btn12) {
        Serial.println("200+");
      } else if (IrReceiver.decodedIRData.decodedRawData == btn13) {
        Serial.println("1");
      } else if (IrReceiver.decodedIRData.decodedRawData == btn14) {
        Serial.println("2");
      } else if (IrReceiver.decodedIRData.decodedRawData == btn15) {
        Serial.println("3");
      } else if (IrReceiver.decodedIRData.decodedRawData == btn16) {
        Serial.println("4");
      } else if (IrReceiver.decodedIRData.decodedRawData == btn17) {
        Serial.println("5");
      } else if (IrReceiver.decodedIRData.decodedRawData == btn18) {
        Serial.println("6");
      } else if (IrReceiver.decodedIRData.decodedRawData == btn19) {
        Serial.println("7");
      } else if (IrReceiver.decodedIRData.decodedRawData == btn20) {
        Serial.println("8");
      } else if (IrReceiver.decodedIRData.decodedRawData == btn21) {
        Serial.println("9");
      } else {
        Serial.println("Other button pressed");
      }
      
      IrReceiver.resume(); // Enable receiving of the next value
  }
  delay(500);
}
