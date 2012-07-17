#include "iostream"
 
using namespace std;
 
class Test
{
public:
    void Hello()
    {
        cout << "Hello world!" << endl;
    }
};
 
int main()
{
    Test test;
    test.Hello();
}
