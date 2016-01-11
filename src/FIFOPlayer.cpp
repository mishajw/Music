//
// Created by misha on 11/01/16.
//

#include "FIFOPlayer.h"
#include <chrono>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string>

using namespace std;

FIFOPlayer::FIFOPlayer() {
  setupAplay();
}

void FIFOPlayer::playValue(int value) {
  char c1 = (char) ((value >> 24) & 0xFF);
  char c2 = (char) ((value >> 16) & 0xFF);
  char c3 = (char) ((value >> 8) & 0xFF);
  char c4 = (char) (value & 0xFF);

  write(fd, &c1, sizeof(c1));
  write(fd, &c2, sizeof(c2));
  write(fd, &c3, sizeof(c3));
  write(fd, &c4, sizeof(c4));
}

void FIFOPlayer::setupAplay() {
  // Make FIFO to put music output
  mkfifo(fifoName.c_str(), 0666);

  string aplayCommand;
  aplayCommand = coreAplay + " " + fifoName + " &";

  // Start aplay
  system(aplayCommand.c_str());

  fd = open(fifoName.c_str(), O_WRONLY);
}

void FIFOPlayer::destroyAplay() {
  close(fd);
  unlink(fifoName.c_str());
}

FIFOPlayer::~FIFOPlayer() {
  destroyAplay();
}
