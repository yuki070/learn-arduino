#include <Arduino.h>
#include "matrix.h"
#include "display.h"

void setup() {
  matrixInit();
  displayInit();
}

void loop() {
  displayLoop();
}