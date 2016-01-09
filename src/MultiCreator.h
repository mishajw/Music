//
// Created by misha on 03/01/16.
//

#ifndef MUSIC_MULTICREATOR_H
#define MUSIC_MULTICREATOR_H

#include <set>
#include "MusicCreator.h"

class MultiCreator : public MusicCreator {
public:
    MultiCreator();
    MultiCreator(std::set<MusicCreator*> &children);
    void addChild(MusicCreator &mc);
    void removeChild(MusicCreator &mc);
private:
    virtual int getNext();
    std::set<MusicCreator*> children;
};

#endif //MUSIC_MULTICREATOR_H
