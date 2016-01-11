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

void getFreqs(std::map<std::string, double> &freqs);
long getTime();

#endif //MUSIC_HELPER_H
