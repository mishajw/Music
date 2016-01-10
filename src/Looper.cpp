//
// Created by misha on 10/01/16.
//

#include "Looper.h"

using namespace std;

int Looper::getNext() {
  unsigned long index = (unsigned long) (getTimesCalled() % length);
  int childNext = child.getScaledNext();

  while (history.size() <= index) {
    history.push_back(0);
  }

  history.at(index) += childNext;

  return history.at(index);
}
