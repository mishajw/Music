//
// Created by misha on 03/01/16.
//

#include "InteractiveCreator.h"
#include "Helper.h"
#include "SingleFrequency.h"
#include <iostream>

using namespace std;

InteractiveCreator::InteractiveCreator() {
  kr.runOnThread();
  getFreqs(freqs);

  notes[30] = new SingleFrequency(freqs["c"]);
  notes[31] = new SingleFrequency(freqs["d"]);
  notes[32] = new SingleFrequency(freqs["e"]);
  notes[33] = new SingleFrequency(freqs["f"]);
  notes[34] = new SingleFrequency(freqs["g"]);
  notes[35] = new SingleFrequency(freqs["a"]);
  notes[36] = new SingleFrequency(freqs["b"]);
}

int InteractiveCreator::getNext() {
  for(std::map<int, MusicCreator*>::iterator iter = notes.begin(); iter != notes.end(); ++iter) {
    if (kr.isPressed(iter->first)) {
      mc.addChild(*(iter->second));
    } else {
      mc.removeChild(*(iter->second));
    }
  }

  if (playing) {
    return mc.getScaledNext();
  } else {
    return 0;
  }
}

InteractiveCreator::~InteractiveCreator() {
  // todo delete children
}
