//
// Created by misha on 03/01/16.
//

#ifndef MUSIC_KEYBOARDREADER_H
#define MUSIC_KEYBOARDREADER_H

#include <set>
#include <map>
#include <vector>
#include <linux/input.h>
#include <thread>
#include "MusicCreator.h"

class KeyboardReader {
public:
    static void runOnThread();
    static void run();
    static bool isPressed(int keyCode);
    static void registerListener(MusicCreator *mc, int keyCode);
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
    std::map<int, std::vector<MusicCreator*>> listeners;

    static void handleEvent(input_event& event);
    static void notifyListeners(int keyCode, bool pressed);
};


#endif //MUSIC_KEYBOARDREADER_H
