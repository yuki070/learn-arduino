#include "matrix.h"
#include <Arduino.h>

// 行从上到下为 R0 到 R7
// 给低电平亮
static const int R0 = 6;
static const int R1 = 11;
static const int R2 = 2;
static const int R3 = 9;
static const int R4 = A0;
static const int R5 = 3;
static const int R6 = A1;
static const int R7 = 5;

// 列从左到右为 C0 到 C7
// 给高电平亮
static const int C0 = 10;
static const int C1 = A2;
static const int C2 = A3;
static const int C3 = 7;
static const int C4 = 4;
static const int C5 = 8;
static const int C6 = 12;
static const int C7 = 13;

static const int rows[] = {R0, R1, R2, R3, R4, R5, R6, R7};
static const int cols[] = {C0, C1, C2, C3, C4, C5, C6, C7};

void matrixInit() {
  for (int i = 0; i < 8; i++) {
    pinMode(rows[i], OUTPUT);
    pinMode(cols[i], OUTPUT);
  }
  allOff();
}

void allOff() {
  for (int i = 0; i < 8; i++) {
    digitalWrite(rows[i], HIGH);
    digitalWrite(cols[i], LOW);
  }
}

void lightOn(int row, int col) {
  digitalWrite(rows[row], LOW);
  digitalWrite(cols[col], HIGH);
}

void lightOff(int row, int col) {
  digitalWrite(rows[row], HIGH);
  digitalWrite(cols[col], LOW);
}

void render(int matrix[8][8]) {
  for (int r = 0; r < 8; r++) {
    digitalWrite(rows[r], LOW);
    for (int c = 0; c < 8; c++) {
      digitalWrite(cols[c], matrix[r][c] == 1 ? HIGH : LOW);
    }
    delay(1);
    allOff();
  }
}

void toMatrix(const byte data[8], int out[8][8]) {
  for (int r = 0; r < 8; r++) {
    for (int c = 0; c < 8; c++) {
      out[r][c] = (data[r] >> (7 - c)) & 0x01;
    }
  }
}
