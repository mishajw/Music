//
// Created by misha on 10/01/16.
//

#ifndef MUSIC_WAVEFUNCTIONS_H
#define MUSIC_WAVEFUNCTIONS_H


class WaveFunctions {
public:
    static double jagged(double angle);

    static WaveFunctions& getInstance() {
      static WaveFunctions instance;
      return instance;
    }

    WaveFunctions(WaveFunctions const&) = delete;
    void operator=(WaveFunctions const&) = delete;
private:
    WaveFunctions() {}
};


#endif //MUSIC_WAVEFUNCTIONS_H
