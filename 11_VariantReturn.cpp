//: C15:VariantReturn.cpp
// From Thinking in C++, 2nd Edition
// Available at http://www.BruceEckel.com
// (c) Bruce Eckel 2000
// Copyright notice in Copyright.txt
// Returning a pointer or reference to a derived
// type during ovverriding
#include <iostream>
#include <string>
using namespace std;

class PetFood {
public:
  virtual string foodType() const = 0; //no return, by Tom Xue
};

class Pet {
public:
  virtual string type() const = 0;
  virtual PetFood* eats() = 0; //so there will exist eat()->foodType(), by Tom Xue
};

class Bird : public Pet {
public:
  string type() const { return "Bird"; }
  class BirdFood : public PetFood { //has return, by Tom Xue
  public:
    string foodType() const {
      return "Bird food"; 
    }
  };
  // Upcast to base type:
  PetFood* eats() { return &bf; } //eats() return type not changed (PetFood*)
private:
  BirdFood bf;
};

class Cat : public Pet {
public:
  string type() const { return "Cat"; }
  class CatFood : public PetFood {
  public:
    string foodType() const { return "Birds"; }
  };
  // Return exact type instead:
  CatFood* eats() { return &cf; } //eats() return type changed, but derived
private:
  CatFood cf;
};

int main() {
  Bird b; 
  Cat c;
  Pet* p[] = { &b, &c, }; //must be pointer to object, by Tom Xue
  for(int i = 0; i < sizeof p / sizeof *p; i++) //calculate the size of array
    cout << p[i]->type() << " eats "
         << p[i]->eats()->foodType() << endl;
  cout << "***\n";

  // Can return the exact type:
  Cat::CatFood* cf = c.eats();
  cout << cf->foodType() << endl;

  Bird::BirdFood* bf;
  // Cannot return the exact type: //this is because the b.eats() is derived from PetFood class, by Tom xue
  //! bf = b.eats(); //error: invalid conversion from ‘PetFood*’ to ‘Bird::BirdFood*’
  // Must downcast:
  
  //  bf = dynamic_cast<Bird::BirdFood*>(b.eats()); or bf = (Bird::BirdFood*)(b.eats()); has the same result here
  bf = (Bird::BirdFood*)(b.eats());
  cout << bf->foodType() << endl;
} ///:~

/* 
output is below:
Bird eats Bird food
Cat eats Birds
***
Birds
Bird food
*/
