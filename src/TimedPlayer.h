//
// Created by misha on 03/01/16.
//

#ifndef MUSIC_TIMEDPLAYER_H
#define MUSIC_TIMEDPLAYER_H

#include "MusicCreator.h"
#include "Player.h"

class TimedPlayer {
public:
  TimedPlayer(MusicCreator& _mc, Player& _pl) : mc(_mc), pl(_pl) {}
  void run();
private:
  MusicCreator& mc;
  Player& pl;
  int fd;
};


#endif //MUSIC_TIMEDPLAYER_H
