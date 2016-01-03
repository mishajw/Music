#include <iostream>
#include <map>
#include <math.h>

#define SAMPLE_RATE 96000.0

using namespace std;

double defaultLength = SAMPLE_RATE * 0.5;
unsigned int maxInt = (unsigned int) pow(2, 32);

void sinePlay(double frequency);

int main() {
  map<string, double> freqs;
  freqs["a"] = 440.00;
  freqs["b"] = 493.88;
  freqs["c"] = 523.25;
  freqs["d"] = 587.33;
  freqs["e"] = 659.25;
  freqs["f"] = 698.46;
  freqs["g"] = 783.99;

  sinePlay(freqs["a"]);
  sinePlay(freqs["b"]);
  sinePlay(freqs["c"]);
  sinePlay(freqs["d"]);
  sinePlay(freqs["e"]);
  sinePlay(freqs["f"]);
  sinePlay(freqs["g"]);

  return 0;
}

/**
 * Play a frequency
 */
void sinePlay(double frequency) {
  double incr = M_PI / SAMPLE_RATE * frequency;
  double incred = 0;

  cerr << incr * SAMPLE_RATE << endl;

  for (int i = 0; i < defaultLength; i ++) {
    int toPlay = (int) (sin(fmod(incred, M_PI)) * maxInt * 0.1);

    cout << (char) ((toPlay >> 24) & 0xFF) <<
    (char) ((toPlay >> 16) & 0xFF) <<
    (char) ((toPlay >> 8)  & 0xFF) <<
    (char) ( toPlay        & 0xFF);

    incred += incr;
  }
}
