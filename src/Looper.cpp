//
// Created by misha on 10/01/16.
//

#include "Looper.h"

using namespace std;

int Looper::getNext() {
  unsigned long index = (unsigned long) (getTimesCalled() % length);
  int childNext = child.getScaledNext();

  while (history.size() <= index) {
    history.push_back(vector<int>());
  }

  vector<int> &current = history.at(index);

  if (childNext != 0) {
    current.push_back(childNext);
  }

  int total = 0;
  for (unsigned int i = 0; i < current.size(); i++) {
    total += current.at(i) / current.size();
  }

  return total;
}
