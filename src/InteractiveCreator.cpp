//
// Created by misha on 03/01/16.
//

#include "InteractiveCreator.h"
#include <iostream>

using namespace std;

InteractiveCreator::InteractiveCreator(MusicCreator &_mc) : mc(_mc) {
  kr.runOnThread();
}

int InteractiveCreator::getNext() {
  playing = kr.isPressed(57);

  if (playing) {
    return mc.getScaledNext();
  } else {
    return 0;
  }
}
