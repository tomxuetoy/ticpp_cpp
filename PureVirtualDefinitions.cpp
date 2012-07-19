//: C15:PureVirtualDefinitions.cpp
// From Thinking in C++, 2nd Edition
// Available at http://www.BruceEckel.com
// (c) Bruce Eckel 2000
// Copyright notice in Copyright.txt
// Pure virtual base definitions
#include <iostream>
using namespace std;

class Pet {
public:
  virtual void speak() const = 0;
  virtual void eat() const = 0;
  // Inline pure virtual definitions illegal: //inline: 内嵌
  //!  virtual void sleep() const = 0 {}
};

// OK, not defined inline
void Pet::eat() const {
  cout << "Pet::eat()" << endl;
}

void Pet::speak() const { 
  cout << "Pet::speak()" << endl;
}

class Dog : public Pet {
public:
  // Use the common Pet code: //changed like below by Tom Xue
  void speak() const { cout << "Dog::speak()" << endl; }
  void eat() const { cout << "Dog::eat()" << endl; }
};

int main() {
  //! Pet a;
  //error: cannot create object 'a' of abstract type 'Pet'
  Dog simba;  // Richard's dog
  simba.speak();
  simba.eat();
} ///:~

/* output is below:
Dog::speak()
Dog::eat()
 */
