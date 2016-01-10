//
// Created by misha on 10/01/16.
//

#include "WaveFunctions.h"
#include <math.h>

double WaveFunctions::jagged(double angle) {
  double modAngle = fmod(angle, M_PI);
  double scaledAngle = modAngle / M_PI;
  double mirroredAngle = scaledAngle < 0.5 ? scaledAngle : 1 - scaledAngle;

  if (angle < M_PI) {
    return mirroredAngle;
  } else {
    return -mirroredAngle;
  }
}
