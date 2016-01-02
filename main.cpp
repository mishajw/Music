#include <iostream>
#include <math.h>

#define SAMPLE_RATE 8000.0

using namespace std;

double defaultLength = SAMPLE_RATE;
unsigned int maxInt = (unsigned int) pow(2, 8);

void sinePlay(double frequency);

int main() {
    for (double i = 440; i < 5000; i *= 2) {
        sinePlay(i);
    }

    return 0;
}

/**
 * Play a frequency
 */
void sinePlay(double frequency) {
    double incr = M_PI / SAMPLE_RATE * frequency;
    double incred = 0;

    cerr << incr * SAMPLE_RATE << endl;

    for (int i = 0; i < defaultLength; i ++) {
        double scaledSin = (sin(fmod(incred, M_PI)) + 1) / 2;
        unsigned int toPlay = (unsigned int) (scaledSin * maxInt * 0.5);

        cout << (uint8_t) toPlay;

        incred += incr;
    }
}
