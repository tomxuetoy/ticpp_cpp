//: C15:OStack.h
// From Thinking in C++, 2nd Edition
// Available at http://www.BruceEckel.com
// (c) Bruce Eckel 2000
// Copyright notice in Copyright.txt
// Using a singly-rooted hierarchy
#ifndef OSTACK_H
#define OSTACK_H

class Object {
public:
  virtual ~Object() = 0;
};

// Required definition:
inline Object::~Object() {}

class Stack {
  struct Link {
    Object* data;
    Link* next; // a different pointer from head, by tomxue
    Link(Object* dat, Link* nxt) :
      data(dat), next(nxt) {}
  }* head;

public:
  Stack() : head(0) {}

  ~Stack(){ 
    while(head)
      delete pop();
  }

  void push(Object* dat) {
    head = new Link(dat, head);
  }

  Object* peek() const {
    return head ? head->data : 0;
  }

  void* peek_current_head() const {
    return head;
  }

  void* peek_current_next() const {
    return head->next;
  }

  Object* pop() {
    if(head == 0) return 0;
    Object* result = head->data;
    Link* oldHead = head;
    head = head->next;
    delete oldHead; // no matter keep it or remove it, by tomxue
    return result;
  }
};
#endif // OSTACK_H ///:~
