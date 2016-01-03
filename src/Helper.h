//
// Created by misha on 03/01/16.
//

#ifndef MUSIC_HELPER_H
#define MUSIC_HELPER_H

#include <math.h>
#include <iostream>
#include <climits>
#include <map>

const double SAMPLE_RATE = 96000.0;

void sinePlay(double frequency, int length = (int) SAMPLE_RATE);
void getFreqs(std::map<std::string, double> &freqs);
void printInt(int i);

#endif //MUSIC_HELPER_H
