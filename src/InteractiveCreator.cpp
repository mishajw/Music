//
// Created by misha on 03/01/16.
//

#include "InteractiveCreator.h"
#include "Helper.h"
#include "SingleFrequency.h"
#include <iostream>

using namespace std;

InteractiveCreator::InteractiveCreator() {
  getFreqs(freqs);
  notes[30] = new SingleFrequency(freqs["c"]);
  notes[17] = new SingleFrequency(freqs["c#"]);
  notes[31] = new SingleFrequency(freqs["d"]);
  notes[18] = new SingleFrequency(freqs["d#"]);
  notes[32] = new SingleFrequency(freqs["e"]);
  notes[33] = new SingleFrequency(freqs["f"]);
  notes[20] = new SingleFrequency(freqs["f#"]);
  notes[34] = new SingleFrequency(freqs["g"]);
  notes[21] = new SingleFrequency(freqs["g#"]);
  notes[35] = new SingleFrequency(freqs["a"]);
  notes[22] = new SingleFrequency(freqs["a#"]);
  notes[36] = new SingleFrequency(freqs["b"]);

  for (auto const k : notes) {
    KeyboardReader::registerListener(this, k.first);
  }
}

int InteractiveCreator::getNext() {
  return mc.getScaledNext();
}

void InteractiveCreator::keyPressed(int keyCode, bool pressed) {
  if (pressed) {
    mc.addChild(*notes[keyCode]);
  } else {
    mc.removeChild(*notes[keyCode]);
  }
}

InteractiveCreator::~InteractiveCreator() {
  // todo delete children
}
