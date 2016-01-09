//
// Created by misha on 03/01/16.
//

#include "TimedPlayer.h"
#include "Helper.h"

using namespace std;

void TimedPlayer::run() {
  cerr << "Starting timed player" << endl;

  long startTime = getTime();

  for (int i = 0; i < SAMPLE_RATE * 10; i ++) {
    // Wait to catch up
    while ((long) ((((double) getTime() - startTime) / 1000.0) * SAMPLE_RATE) < i);

    int toPlay = mc.getScaledNext();
    printInt(toPlay, fd);
  }

  cerr << "Finished timed player" << endl;
}
