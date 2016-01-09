//
// Created by misha on 03/01/16.
//

#include "KeyboardReader.h"

#include <unistd.h>
#include <fcntl.h>
#include <iostream>

using namespace std;

void KeyboardReader::runOnThread() {
  getInstance().listenThread = thread(&run);
}

void KeyboardReader::run() {
  cerr << "Starting to listen to keyboard..." << endl;

  struct input_event ev[64];
  int fd, size = sizeof (struct input_event);
  string device = "/dev/input/event0";

  //Open Device
  if ((fd = open (device.c_str(), O_RDONLY)) == -1) {
    cerr << "Is not a vaild device." << endl;
    return;
  }

  while (true) {
    if (read (fd, ev, (size_t) (size * 64)) < size) {
      cerr << "Couldn't read from device" << endl;
    }

    input_event event = ev[1];
    handleEvent(event);

    if (event.code == 1) {
      break;
    }
  }
}

void KeyboardReader::handleEvent(input_event &event) {
  int type = event.value;
  int keyCode = event.code;

  switch (type) {
    case 0:
      getInstance().pressedKeys.erase(keyCode);
      notifyListeners(keyCode, false);
      break;
    case 1:
      getInstance().pressedKeys.insert(keyCode);
      notifyListeners(keyCode, true);
      break;
    default:
      break;
  }
}

bool KeyboardReader::isPressed(int keyCode) {
  return getInstance().pressedKeys.find(keyCode) != getInstance().pressedKeys.end();
}

KeyboardReader::~KeyboardReader() {
  listenThread.join();
}

void KeyboardReader::registerListener(MusicCreator *mc, int keyCode) {
  getInstance().listeners[keyCode].push_back(mc);
}

void KeyboardReader::notifyListeners(int keyCode, bool pressed) {
  auto ls = getInstance().listeners[keyCode];

  for (unsigned int i = 0; i < ls.size(); i++) {
    ls.at(i)->keyPressed(keyCode, pressed);
  }
}
