#include <iostream>
#include "MultiCreator.h"
#include "SingleFrequency.h"
#include "Helper.h"
#include "TimedPlayer.h"
#include "InteractiveCreator.h"
#include "WaveFunctions.h"
#include "PitchChanger.h"
#include "Looper.h"
#include "FIFOPlayer.h"

using namespace std;

MusicCreator* factory(double freq) {
  return new SingleFrequency(freq / 2, sin);
}

int main() {
  KeyboardReader::runOnThread();
  Player* pl = new FIFOPlayer();

  InteractiveCreator ic(factory);

  Looper l(ic, 2000);
  PitchChanger pc(l);

  TimedPlayer tp(pc, *pl);
  tp.run();

  delete pl;

  return 0;
}
