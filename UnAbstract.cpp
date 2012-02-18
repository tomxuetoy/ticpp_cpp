//: C15:UnAbstract.cpp
// From Thinking in C++, 2nd Edition
// Available at http://www.BruceEckel.com
// (c) Bruce Eckel 2000
// Copyright notice in Copyright.txt
// Pure virtual destructors 
// seem to behave strangely

class AbstractBase {
public:
  virtual ~AbstractBase() = 0;
};

AbstractBase::~AbstractBase() {} //pure virtual function must have a function entity

class Derived : public AbstractBase {}; //no need to provide definition of pure virtual function in derived class
// No overriding of destructor necessary?

int main() { Derived d; } ///:~
