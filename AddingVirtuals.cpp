//: C15:AddingVirtuals.cpp
// From Thinking in C++, 2nd Edition
// Available at http://www.BruceEckel.com
// (c) Bruce Eckel 2000
// Copyright notice in Copyright.txt
// Adding virtuals in derivation
#include <iostream>
#include <string>
using namespace std;

class Pet {
  string pname;
public:
  Pet(const string& petName) : pname(petName) {}
  virtual string name() const { return pname; }
  virtual string speak() const { return ""; }
};

class Dog : public Pet {
  string name;
public:
  Dog(const string& petName) : Pet(petName) {}
  // New virtual function in the Dog class:
  virtual string sit() const {	//virtual function, only defined in the derived class
    return Pet::name() + " sits";
  }
  string speak() const { // Override
    return Pet::name() + " says 'Bark!'";
  }
};

int main() {
  Pet* p[] = {new Pet("generic"),new Dog("bob")}; //p[i] points to base class
  cout << "p[0]->speak() = "
       << p[0]->speak() << endl;
  cout << "p[1]->speak() = "
       << p[1]->speak() << endl;	
  cout << "p[1]->sit() = "
       << ((Dog*)p[1])->sit() << endl;  /* ! p[1]->sit(), this way is illegal because base class pointer doesn't point to sit(). So explicitly 'type cast' is needed */
} ///:~

//output is below:
/*
p[0]->speak() = 
p[1]->speak() = bob says 'Bark!'
p[1]->sit() = bob sits
*/
