#include <iostream>
#include <string.h>

using namespace std;

class Fruit
{
public:
    virtual void peel() {
        cout << "peeling a base class fruit" << endl;
    }
    void slice();
    void juice();
private:
    int weight, calories_per_oz;
};

class Apple: public Fruit
{
public:
    void peel() {
        cout << "peeling an apple" << endl;
    }
    void make_candy_apple(float weight);
    void bob_for(int tub_id, int number_of_attempts);
};

main()
{
    Apple apple;
    Fruit orange;

    Fruit *p;

    p = &apple;
    p->peel();

    p = &orange;
    p->peel();
}
/*
$ ./a.out 
peeling an apple
peeling a base class fruit
*/
