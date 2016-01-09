#include <iostream>
#include "MultiCreator.h"
#include "SingleFrequency.h"
#include "Helper.h"
#include "TimedPlayer.h"
#include "InteractiveCreator.h"

using namespace std;

int main() {
  KeyboardReader::runOnThread();

  int fd = setupAplay();

  map<string, double> freqs;
  getFreqs(freqs);

  SingleFrequency sc1(freqs["c"]);
  SingleFrequency sc2(freqs["e"]);
  SingleFrequency sc3(freqs["g"]);

  set<MusicCreator*> children;
  children.insert(&sc1);
  children.insert(&sc2);
  children.insert(&sc3);
  MultiCreator mc(children);

  InteractiveCreator ic;

  TimedPlayer tp(ic, fd);
  tp.run();

  destroyAplay(fd);

  return 0;
}
