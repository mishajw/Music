//
// Created by misha on 03/01/16.
//

#ifndef MUSIC_MULTICREATOR_H
#define MUSIC_MULTICREATOR_H

#include <vector>
#include "MusicCreator.h"

class MultiCreator : public MusicCreator {
public:
    MultiCreator(std::vector<MusicCreator*> &children);
private:
    virtual int getNext();
    std::vector<MusicCreator*> children;
};

#endif //MUSIC_MULTICREATOR_H
