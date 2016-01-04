//
// Created by misha on 03/01/16.
//

#ifndef MUSIC_INTERACTIVECREATOR_H
#define MUSIC_INTERACTIVECREATOR_H


#include "MusicCreator.h"
#include "KeyboardReader.h"

class InteractiveCreator : public MusicCreator {

public:
    InteractiveCreator(MusicCreator& _mc);

protected:
    virtual int getNext();

private:
    KeyboardReader kr;
    bool playing;
    MusicCreator& mc;
};


#endif //MUSIC_INTERACTIVECREATOR_H
