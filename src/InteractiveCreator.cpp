//
// Created by misha on 03/01/16.
//

#include "InteractiveCreator.h"

int InteractiveCreator::getNext() {
  if (playing) {
    return mc.getNext();
  } else {
    return 0;
  }
}
