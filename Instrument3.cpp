//: C15:Instrument3.cpp
// From Thinking in C++, 2nd Edition
// Available at http://www.BruceEckel.com
// (c) Bruce Eckel 2000
// Copyright notice in Copyright.txt
// Late binding with the virtual keyword
#include <iostream>
using namespace std;
enum note { middleC, Csharp, Cflat }; // Etc.

class Instrument {
public:
  virtual void play(note) const {     //virtual function
    cout << "Instrument::play" << endl;
  }
};

// Wind objects are Instruments
// because they have the same interface:
class Wind : public Instrument {
public:
  // Override interface function:
  void play(note) const {
    cout << "Wind::play" << endl;
  }
};

void tune(Instrument& i) { //address is passed for late binding, by Tom Xue
  // ...
  i.play(middleC);	   //concrete value should be input, by Tom Xue
}

int main() {
  Wind flute;
  tune(flute); // Upcasting
} ///:~

//output is below:
//Wind::play
