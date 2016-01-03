//
// Created by misha on 03/01/16.
//

#ifndef MUSIC_SINGLEFREQUENCY_H
#define MUSIC_SINGLEFREQUENCY_H


#include "MusicCreator.h"

class SingleFrequency : public MusicCreator {
public:
    SingleFrequency(double frequency);
    double getFrequency();
private:
    virtual int getNext();

    double frequency;
};


#endif //MUSIC_SINGLEFREQUENCY_H
