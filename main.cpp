#include <iostream>
#include <math.h>

#define SAMPLE_RATE 8000.0

using namespace std;

double defaultLength = SAMPLE_RATE;
unsigned int maxInt = (unsigned int) pow(2, 32);

void sinePlay(double frequency);

int main() {
//    for (double i = 440; i < 500; i += 10) {
//        sinePlay(i);
//    }

    sinePlay(440);

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
        double scaledSin = sin(fmod(incred, M_PI));
        unsigned int toPlay = (unsigned int) (scaledSin * maxInt * 0.1);

        cout << (char) ((toPlay >> 24) & 0xFF) <<
                (char) ((toPlay >> 16) & 0xFF) <<
                (char) ((toPlay >> 8)  & 0xFF) <<
                (char) ( toPlay        & 0xFF);

        incred += incr;
    }
}
