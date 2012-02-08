class demo{
public:
	demo(){};	//或者和下面第15行一同注释掉
    demo(int i){x=i;}
    int print(){return x;}
private:
    int x;
};
 
#include <iostream>
using namespace std;
 
int main()
{
    demo *a=new demo;	//注释
    demo *b=new demo(1);
    cout<<b->print()<<endl;
}
