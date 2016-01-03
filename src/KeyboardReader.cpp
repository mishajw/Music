//
// Created by misha on 03/01/16.
//

#include "KeyboardReader.h"

#include <unistd.h>
#include <fcntl.h>
#include <iostream>

using namespace std;

void KeyboardReader::run() {
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

  cerr << keyCode << endl;

  switch (type) {
    case 0:
      pressedKeys.erase(keyCode);
      break;
    case 1:
      pressedKeys.insert(keyCode);
      break;
    default:
      break;
  }
}
