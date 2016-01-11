//
// Created by misha on 11/01/16.
//

#ifndef MUSIC_FIFOPLAYER_H
#define MUSIC_FIFOPLAYER_H

#include "Player.h"
#include <iostream>

class FIFOPlayer : public Player {
public:
    FIFOPlayer();
    ~FIFOPlayer();

    virtual void playValue(int value);
private:
    int fd;
    const std::string fifoName = "/tmp/music_fifo";
    const std::string coreAplay = "aplay -f S32_BE -r 96000";

    void setupAplay();
    void destroyAplay();
};


#endif //MUSIC_FIFOPLAYER_H
