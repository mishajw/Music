//
// Created by misha on 03/01/16.
//

#include "Helper.h"
#include <chrono>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


using namespace std;

void getFreqs(map<string, double> &freqs) {
  freqs["c"] = 523.25;
  freqs["c#"] = 554.37;
  freqs["d"] = 587.33;
  freqs["d#"] = 622.25;
  freqs["e"] = 659.25;
  freqs["f"] = 698.46;
  freqs["f#"] = 739.99;
  freqs["g"] = 783.99;
  freqs["g#"] = 830.61;
  freqs["a"] = 880.00;
  freqs["a#"] = 932.33;
  freqs["b"] = 978.77;
}



long getTime() {
  return
    std::chrono::system_clock::now().time_since_epoch() /
    std::chrono::milliseconds(1);
}
