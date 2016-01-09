//
// Created by misha on 09/01/16.
//

#ifndef MUSIC_CHANGABLEFREQUENCY_H
#define MUSIC_CHANGABLEFREQUENCY_H


#include "MusicCreator.h"

class ChangableFrequency : public MusicCreator {
public:
    ChangableFrequency(double _frequency) : frequency(_frequency) {}
    double getFrequency();
    void setFrequency(double frequency);
private:
    double runningAngle;
    virtual int getNext();

    double frequency;
};


#endif //MUSIC_CHANGABLEFREQUENCY_H
