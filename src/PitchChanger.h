//
// Created by misha on 10/01/16.
//

#ifndef MUSIC_PITCHCHANGER_H
#define MUSIC_PITCHCHANGER_H


#include "MusicCreator.h"

class PitchChanger : public MusicCreator {
public:
    PitchChanger(MusicCreator &_child);
    virtual int getNext();
    virtual void keyPressed(int keyCode, bool pressed);
private:
    MusicCreator &child;
    double pitchScale = 1;
    int childsSyncedStep, mySyncedStep;

    const unsigned int UP_KEY = 13;
    const unsigned int DOWN_KEY = 12;
    const double PITCH_INCREMENT = 1.25;
};


#endif //MUSIC_PITCHCHANGER_H
