//
// Created by misha on 09/01/16.
//

#include "ChangableFrequency.h"
#include "Helper.h"
#include <math.h>

int ChangableFrequency::getNext() {
  runningAngle += (M_PI / SAMPLE_RATE * frequency);

  return (int) (sin(fmod(runningAngle, M_PI)) * INT_MAX);
}

double ChangableFrequency::getFrequency() {
  return frequency;
}

void ChangableFrequency::setFrequency(double frequency) {
  this->frequency = frequency;
}
