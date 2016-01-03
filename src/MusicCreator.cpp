//
// Created by misha on 03/01/16.
//

#include "MusicCreator.h"

int MusicCreator::getScaledNext() {
  timesCalled ++;

  return (int) (volume * getNext());
}

void MusicCreator::setVolume(double volume) {
  this->volume = volume;

  if (this->volume < 0) this->volume = 0;
  if (this->volume > 1) this->volume = 1;
}

double MusicCreator::getVolume() {
  return this->volume;
}

int MusicCreator::getTimesCalled() {
  return timesCalled;
}
