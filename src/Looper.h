//
// Created by misha on 10/01/16.
//

#ifndef MUSIC_LOOPER_H
#define MUSIC_LOOPER_H

#include "MusicCreator.h"
#include "Helper.h"
#include <vector>

class Looper : public MusicCreator {
public:
    Looper(MusicCreator &_child, int _length) : child(_child), length((int) ((_length / 1000) * SAMPLE_RATE)) {}
    virtual int getNext();
private:
    MusicCreator &child;
    int length;
    std::vector<int> history;
};


#endif //MUSIC_LOOPER_H
