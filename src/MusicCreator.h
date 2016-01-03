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

  protected:
    virtual int getNext() = 0;

    int timesCalled = 0;

  private:
    double volume = 1;
};

#endif //MUSIC_MUSICCREATOR_H
