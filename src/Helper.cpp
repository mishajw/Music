//
// Created by misha on 03/01/16.
//

#include "Helper.h"
#include <chrono>

using namespace std;

void sinePlay(double frequency, int length) {
  double incr = M_PI / SAMPLE_RATE * frequency;
  double incred = 0;

  cerr << incr * SAMPLE_RATE << endl;

  for (int i = 0; i < length; i ++) {
    int toPlay = (int) (sin(fmod(incred, M_PI)) * INT_MAX);

    printInt(toPlay);

    incred += incr;
  }
}

void getFreqs(map<string, double> &freqs) {
  freqs["a"] = 440.00;
  freqs["b"] = 493.88;
  freqs["c"] = 523.25;
  freqs["d"] = 587.33;
  freqs["e"] = 659.25;
  freqs["f"] = 698.46;
  freqs["g"] = 783.99;
}

void printInt(int i) {
  cout <<
    (char) ((i >> 24) & 0xFF) <<
    (char) ((i >> 16) & 0xFF) <<
    (char) ((i >> 8)  & 0xFF) <<
    (char) ( i        & 0xFF);
}

long getTime() {
  return
    std::chrono::system_clock::now().time_since_epoch() /
    std::chrono::milliseconds(1);
}