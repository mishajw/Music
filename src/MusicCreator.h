//
// Created by misha on 03/01/16.
//

#ifndef MUSIC_MUSICCREATOR_H
#define MUSIC_MUSICCREATOR_H

class MusicCreator {
  public:
    int getScaledNext();

    void setVolume(double volume);
    double getVolume();
    int getTimesCalled();
    virtual void keyPressed(int keyCode, bool pressed) {};
    int getLastValue();
  protected:
    virtual int getNext() = 0;
    int timesCalled = 0;

  private:
    double volume = 1;
    int lastValue;
};

#endif //MUSIC_MUSICCREATOR_H
