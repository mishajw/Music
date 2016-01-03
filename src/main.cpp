#include <iostream>
#include "SoloCreator.h"
#include "MultiCreator.h"
#include "SingleFrequency.h"
#include "Helper.h"

using namespace std;

int main() {
  SingleFrequency* sc = new SingleFrequency(10);

  vector<MusicCreator*> children;
  children.push_back(sc);

  MultiCreator* mc = new MultiCreator(children);

  for (int i = 0; i < SAMPLE_RATE * 3; i ++) {
    int toPlay = mc->getScaledNext();
//    cout << toPlay << endl;
    printInt(toPlay);
  }

  delete mc;

  return 0;
}
