//
// Created by misha on 03/01/16.
//

#include "SingleFrequency.h"
#include <climits>
#include <math.h>
#include "Helper.h"

int SingleFrequency::getNext() {
  double angle = (M_PI / SAMPLE_RATE * frequency) * timesCalled;
  return (int) (sin(fmod(angle, M_PI)) * INT_MAX);
}

SingleFrequency::SingleFrequency(double frequency) {
  this->frequency = frequency;
}

double SingleFrequency::getFrequency() {
  return frequency;
}
