#include "display.h"
#include "matrix.h"
#include "fonts.h"
#include <Arduino.h>

static const int leftBtn = A4;
static const int rightBtn = A5;
static const int repeats = 100;
static int timer = repeats - 1;
static int alphabetIndex = 0;

static const int RIGHT[2] = {0, 1};
static const int LEFT[2] = {0, -1};
static const int UP[2] = {-1, 0};
static const int DOWN[2] = {1, 0};

int position[2] = {0, 0};
int direction[2] = {0, 1};

void displayInit() {
  pinMode(leftBtn, INPUT);
  pinMode(rightBtn, INPUT);
  timer = repeats - 1;
  alphabetIndex = alphabetCount - 1;
  Serial.begin(9600);
}

// static void renderCurrent() {
//   int tmp[8][8];
//   toMatrix(alphabets[alphabetIndex], tmp);
//   render(tmp);
// }

void displayLoop() {
//   timer = (timer + 1) % repeats;
//   if (timer > 0) {
//     renderCurrent();
//     return;
//   }
//   alphabetIndex = (alphabetIndex + 1) % alphabetCount;
//   renderCurrent();
  lightOn(position[0], position[1]);
  delay(600);
  lightOff(position[0], position[1]);
  delay(400);

  if (digitalRead(leftBtn) == HIGH) {
    if (direction[0] == 0 && direction[1] == 1) {
      direction[0] = UP[0];
      direction[1] = UP[1];
    } else if (direction[0] == -1 && direction[1] == 0) {
      direction[0] = LEFT[0];
      direction[1] = LEFT[1];
    } else if (direction[0] == 0 && direction[1] == -1) {
      direction[0] = DOWN[0];
      direction[1] = DOWN[1];
    } else if (direction[0] == 1 && direction[1] == 0) {
      direction[0] = RIGHT[0];
      direction[1] = RIGHT[1];
    }
  } else if (digitalRead(rightBtn) == HIGH) {
    if (direction[0] == 0 && direction[1] == 1) {
      direction[0] = DOWN[0];
      direction[1] = DOWN[1];
    } else if (direction[0] == 1 && direction[1] == 0) {
      direction[0] = LEFT[0];
      direction[1] = LEFT[1];
    } else if (direction[0] == 0 && direction[1] == -1) {
      direction[0] = UP[0];
      direction[1] = UP[1];
    } else if (direction[0] == -1 && direction[1] == 0) {
      direction[0] = RIGHT[0];
      direction[1] = RIGHT[1];
    }
  }

  int newPosition[2] = {
    (position[0] + direction[0]),
    (position[1] + direction[1])
  };
  position[0] = newPosition[0] >= 0 && newPosition[0] < 8 ? newPosition[0] : position[0];
  position[1] = newPosition[1] >= 0 && newPosition[1] < 8 ? newPosition[1] : position[1];
}
