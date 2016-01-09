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

//  for (unsigned int i = 0; i < children.size(); i++) {
//    total += children.at(i)->getScaledNext();
//  }

  for (auto const c : children) {
    total += c->getScaledNext() / children.size();
  }

//  std::cout << total << std::endl;
//  if (children.size() > 0) {
//    total /= children.size();
//  }
//  std::cout << total << std::endl;

  return total;
}

void MultiCreator::addChild(MusicCreator &mc) {
  children.insert(&mc);
}

void MultiCreator::removeChild(MusicCreator &mc) {
  children.erase(&mc);
}
