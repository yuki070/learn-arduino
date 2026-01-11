#ifndef MATRIX_H
#define MATRIX_H
#include <Arduino.h>

void matrixInit();
void allOff();
void render(int matrix[8][8]);
void lightOn(int row, int col);
void lightOff(int row, int col);
void toMatrix(const byte data[8], int out[8][8]);

#endif
