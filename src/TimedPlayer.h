//
// Created by misha on 03/01/16.
//

#ifndef MUSIC_TIMEDPLAYER_H
#define MUSIC_TIMEDPLAYER_H

#include "MusicCreator.h"

class TimedPlayer {
public:
  TimedPlayer(MusicCreator& _mc) : mc(_mc) {}
  void run();
private:
  MusicCreator& mc;
};


#endif //MUSIC_TIMEDPLAYER_H
