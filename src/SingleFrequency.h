//
// Created by misha on 03/01/16.
//

#ifndef MUSIC_SINGLEFREQUENCY_H
#define MUSIC_SINGLEFREQUENCY_H


#include <math.h>
#include "MusicCreator.h"

class SingleFrequency : public MusicCreator {
public:
    SingleFrequency(double frequency, double (*)(double) = sin);
    double getFrequency();
private:
    virtual int getNext();

    double frequency;
    double (*waveFunction)(double);
};


#endif //MUSIC_SINGLEFREQUENCY_H
