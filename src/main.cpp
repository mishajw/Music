#include <iostream>
#include "MultiCreator.h"
#include "SingleFrequency.h"
#include "Helper.h"
#include "TimedPlayer.h"

using namespace std;

int main() {
  map<string, double> freqs;
  getFreqs(freqs);

  SingleFrequency sc1(freqs["c"]);
  SingleFrequency sc2(freqs["e"]);
  SingleFrequency sc3(freqs["g"]);

  vector<MusicCreator*> children;
  children.push_back(&sc1);
  children.push_back(&sc2);
  children.push_back(&sc3);

  MultiCreator mc(children);

  TimedPlayer tp(mc);
  tp.run();

  return 0;
}
