//
// Created by misha on 10/01/16.
//

#include "PitchChanger.h"
#include "KeyboardReader.h"
#include <iostream>
#include <math.h>

using namespace std;

PitchChanger::PitchChanger(MusicCreator &_child) : child(_child) {
  printf("Pitch changer starts\n");

  KeyboardReader::registerListener(this, UP_KEY);
  KeyboardReader::registerListener(this, DOWN_KEY);
}

int PitchChanger::getNext() {
  int myDiff = getTimesCalled() - mySyncedStep;
  int childDiff, scaledChildDiff;

  while(1) {
    childDiff = child.getTimesCalled() - childsSyncedStep;
    scaledChildDiff = (int) floor(childDiff / pitchScale);

    if (myDiff < scaledChildDiff) {
      break;
    } else {
      child.getScaledNext();
    }
  }

  return child.getLastValue();
}

void PitchChanger::keyPressed(int keyCode, bool pressed) {
  if (pressed) {
    return;
  }

  if (keyCode == UP_KEY) {
    pitchScale *= PITCH_INCREMENT;
  } else if (keyCode == DOWN_KEY) {
    pitchScale /= PITCH_INCREMENT;
  }

  mySyncedStep = getTimesCalled();
  childsSyncedStep = child.getTimesCalled();

  cout << pitchScale << endl;
}
