//
// Created by misha on 03/01/16.
//

#ifndef MUSIC_KEYBOARDREADER_H
#define MUSIC_KEYBOARDREADER_H

#include <set>
#include <linux/input.h>
#include <thread>

class KeyboardReader {
public:
    static void runOnThread();
    static void run();
    static bool isPressed(int keyCode);
    ~KeyboardReader();

    static KeyboardReader& getInstance() {
      static KeyboardReader instance;
      return instance;
    }

    KeyboardReader(KeyboardReader const&) = delete;
    void operator=(KeyboardReader const&) = delete;
private:
    KeyboardReader() {}
    std::thread listenThread;
    std::set<int> pressedKeys;
    static void handleEvent(input_event& event);
};


#endif //MUSIC_KEYBOARDREADER_H
