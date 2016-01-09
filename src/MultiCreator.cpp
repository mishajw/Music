//
// Created by misha on 03/01/16.
//

#include "MultiCreator.h"
#include <iostream>

MultiCreator::MultiCreator() {}

MultiCreator::MultiCreator(std::set<MusicCreator *> &children) {
  this->children = children;
}

int MultiCreator::getNext() {
  int total = 0;

  for (auto const c : children) {
    total += c->getScaledNext() / children.size();
  }

  return total;
}

void MultiCreator::addChild(MusicCreator &mc) {
  children.insert(&mc);
}

void MultiCreator::removeChild(MusicCreator &mc) {
  children.erase(&mc);
}
