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
const std::string fifoName("/tmp/music_fifo");
const std::string coreAplay("aplay -f S32_BE -r 96000");

void getFreqs(std::map<std::string, double> &freqs);
void printInt(int i, int fd);
long getTime();
int setupAplay();
void destroyAplay(int fd);

#endif //MUSIC_HELPER_H
