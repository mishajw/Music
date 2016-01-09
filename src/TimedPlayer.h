//
// Created by misha on 03/01/16.
//

#ifndef MUSIC_TIMEDPLAYER_H
#define MUSIC_TIMEDPLAYER_H

#include "MusicCreator.h"

class TimedPlayer {
public:
  TimedPlayer(MusicCreator& _mc, int _fd) : mc(_mc), fd(_fd) {}
  void run();
private:
  MusicCreator& mc;
  int fd;
};


#endif //MUSIC_TIMEDPLAYER_H
