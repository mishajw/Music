//
// Created by misha on 03/01/16.
//

#include "InteractiveCreator.h"
#include "Helper.h"
#include "SingleFrequency.h"
#include <iostream>

using namespace std;

InteractiveCreator::InteractiveCreator(MusicCreator * (*factory)(double)) {
  getFreqs(freqs);

  notes[30] = factory(freqs["c"]);
  notes[17] = factory(freqs["c#"]);
  notes[31] = factory(freqs["d"]);
  notes[18] = factory(freqs["d#"]);
  notes[32] = factory(freqs["e"]);
  notes[33] = factory(freqs["f"]);
  notes[20] = factory(freqs["f#"]);
  notes[34] = factory(freqs["g"]);
  notes[21] = factory(freqs["g#"]);
  notes[35] = factory(freqs["a"]);
  notes[22] = factory(freqs["a#"]);
  notes[36] = factory(freqs["b"]);

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
  for (auto const n : notes) {
    delete n.second;
  }
}
