#include <iostream>
#include "MultiCreator.h"
#include "SingleFrequency.h"
#include "Helper.h"
#include "TimedPlayer.h"
#include "InteractiveCreator.h"

using namespace std;

int main() {
  int fd = setupAplay();

  map<string, double> freqs;
  getFreqs(freqs);

  SingleFrequency sc1(freqs["c"]);
  SingleFrequency sc2(freqs["e"]);
  SingleFrequency sc3(freqs["g"]);

  sc1.setVolume(0.3);
  sc2.setVolume(0.3);
  sc3.setVolume(0.3);

  vector<MusicCreator*> children;
  children.push_back(&sc1);
  children.push_back(&sc2);
  children.push_back(&sc3);
  MultiCreator mc(children);

  InteractiveCreator ic(mc);

  TimedPlayer tp(ic, fd);
  tp.run();

  destroyAplay(fd);

  return 0;
}
