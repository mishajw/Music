//
// Created by misha on 03/01/16.
//

#ifndef MUSIC_INTERACTIVECREATOR_H
#define MUSIC_INTERACTIVECREATOR_H


#include "MusicCreator.h"

class InteractiveCreator : MusicCreator {

public:
    InteractiveCreator(MusicCreator& _mc) : mc(_mc) {}

protected:
    virtual int getNext();

private:
    bool playing;
    MusicCreator mc;
};


#endif //MUSIC_INTERACTIVECREATOR_H
