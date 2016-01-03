//
// Created by misha on 03/01/16.
//

#ifndef MUSIC_KEYBOARDREADER_H
#define MUSIC_KEYBOARDREADER_H

#include <set>
#include <linux/input.h>

class KeyboardReader {
public:
    void run();

private:
    std::set<int> pressedKeys;
    void handleEvent(input_event& event);
};


#endif //MUSIC_KEYBOARDREADER_H
