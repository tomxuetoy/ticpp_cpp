//: C15:Sizes.cpp
// From Thinking in C++, 2nd Edition
// Available at http://www.BruceEckel.com
// (c) Bruce Eckel 2000
// Copyright notice in Copyright.txt
// Object sizes with/without virtual functions
#include <iostream>
using namespace std;

class NoVirtual {
  int a;
public:
  void x() const {}
  int i() const { return 1; }
};

class OneVirtual {
  int a;
public:
  virtual void x() const {}
  int i() const { return 1; }
};

class TwoVirtuals {
  int a;
public:
  virtual void x() const {}
  virtual int i() const { return 1; }
};

int main() {
  cout << "int: " << sizeof(int) << endl;
  cout << "NoVirtual: "
       << sizeof(NoVirtual) << endl;
  cout << "void* : " << sizeof(void*) << endl;
  cout << "OneVirtual: "
       << sizeof(OneVirtual) << endl;
  cout << "TwoVirtuals: "
       << sizeof(TwoVirtuals) << endl;
} ///:~

//output is below:
/*
int: 4
NoVirtual: 4
void* : 4
OneVirtual: 8
TwoVirtuals: 8

说明：
如果有一个或多个虚函数，编译器都只在这个结构中插入一个单个指针(VPTR)。
因此OneVirtual和TwoVirtual的长度没有区别。
这个例子至少要求一个数据成员。如果没有数据成员，C++编译器会强制这个对象是非零长度，因为每个对象
必须有一个互相区别的地址。
*/
