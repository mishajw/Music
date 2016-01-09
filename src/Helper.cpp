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

void printInt(int i, int fd) {
  char c1 = (char) ((i >> 24) & 0xFF);
  char c2 = (char) ((i >> 16) & 0xFF);
  char c3 = (char) ((i >> 8)  & 0xFF);
  char c4 = (char) ( i        & 0xFF);

  write(fd, &c1, sizeof(c1));
  write(fd, &c2, sizeof(c2));
  write(fd, &c3, sizeof(c3));
  write(fd, &c4, sizeof(c4));
}

long getTime() {
  return
    std::chrono::system_clock::now().time_since_epoch() /
    std::chrono::milliseconds(1);
}

int setupAplay() {
  // Make FIFO to put music output
  mkfifo(fifoName.c_str(), 0666);

  string aplayCommand;
  aplayCommand = coreAplay + " " + fifoName + " &";

  // Start aplay
  system(aplayCommand.c_str());

  return open(fifoName.c_str(), O_WRONLY);
}

void destroyAplay(int fd) {
  close(fd);
  unlink(fifoName.c_str());
}
