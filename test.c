#include <iostream>
using namespace std;

class Test
{
public:
    Test(int i):identifier(i)//冒号初始化列表, identifier=i
    {
        cout<<"Hello "<<identifier<<"\n";
    } 
    ~Test()
    {
        cout<<"Googbye "<<identifier<<endl;
    }
private:
    const int identifier;
};

int main()
{
    Test theWorld(4);
    return 0;
}
