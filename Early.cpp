//: C15:Early.cpp
// From Thinking in C++, 2nd Edition
// Available at http://www.BruceEckel.com
// (c) Bruce Eckel 2000
// Copyright notice in Copyright.txt
// Early binding & virtual functions
#include <iostream>
#include <string>
using namespace std;

class Pet {
public:
  virtual string speak() const { return "..."; }
};

class Dog : public Pet {
public:
  string speak() const { return "Bark!"; }
};

int main() {
  Dog ralph;
  Pet* p1 = &ralph;
  Pet& p2 = ralph;
  Pet p3;
  // Late binding for both:
  cout << "p1->speak() = " << p1->speak() <<endl;
  cout << "p2.speak() = " << p2.speak() << endl;
  // Early binding (probably):
  cout << "p3.speak() = " << p3.speak() << endl;
} ///:~

//output is below:
/*
p1->speak() = Bark!
p2.speak() = Bark!
p3.speak() = ... 

说明：
在p1->speak()和p2.speak()中，使用地址，就意味着信息不完全：p1和p2可能表示Pet的地址，
也可能表示其派生对象的地址，所以必须使用虚函数。
而当调用p3.speak时不存在含糊，编译器知道确切的类型且知道它是一个对象，所以它不可能
是由Pet派生的对象，而确切的只是一个Pet。这样，可以使用早捆绑。
*/
