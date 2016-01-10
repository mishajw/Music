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

SingleFrequency::SingleFrequency(double frequency, double (*waveFunction)(double)) {
  this->frequency = frequency;
  this->waveFunction = waveFunction;
}

double SingleFrequency::getFrequency() {
  return frequency;
}
