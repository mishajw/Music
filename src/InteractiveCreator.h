//
// Created by misha on 03/01/16.
//

#ifndef MUSIC_INTERACTIVECREATOR_H
#define MUSIC_INTERACTIVECREATOR_H


#include "MusicCreator.h"
#include "KeyboardReader.h"
#include "ChangableFrequency.h"
#include "MultiCreator.h"
#include <map>

class InteractiveCreator : public MusicCreator {

public:
    InteractiveCreator();
    virtual void keyPressed(int keyCode, bool pressed);
    ~InteractiveCreator();

protected:
    virtual int getNext();

private:
    bool playing;
    std::map<std::string, double> freqs;
    std::map<int, MusicCreator*> notes;
    MultiCreator mc;
};


#endif //MUSIC_INTERACTIVECREATOR_H
