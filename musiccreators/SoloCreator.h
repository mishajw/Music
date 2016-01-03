//
// Created by misha on 03/01/16.
//

#ifndef MUSIC_SOLOCREATOR_H
#define MUSIC_SOLOCREATOR_H

#include "MusicCreator.h"

class SoloCreator : public MusicCreator {
public:
    virtual int getNext();
};


#endif //MUSIC_SOLOCREATOR_H
