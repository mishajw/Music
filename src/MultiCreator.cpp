//
// Created by misha on 03/01/16.
//

#include "MultiCreator.h"
#include <iostream>

MultiCreator::MultiCreator(std::vector<MusicCreator *> &children) {
  this->children = children;
}

int MultiCreator::getNext() {
  int total = 0;

  for (unsigned int i = 0; i < children.size(); i++) {
    total += children.at(i)->getScaledNext();
  }

  return total;
}

MultiCreator::~MultiCreator() {
  std::cout << "Died multi" << std::endl;

  while(!children.empty()) delete children.back(), children.pop_back();
}
