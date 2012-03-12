#include <iostream>

using namespace std;

template <class T> 	//class也可用typename替换
T mymax(T a, T b) 	//参数和返回值都是T类型
{
 return a > b? a: b;
}

int main()
{
 cout << mymax(1, 2) << endl; 			//隐式调用int类型的mymax
 cout << mymax(1.1f, 2.2f) << endl; 	//隐式调用float类型的mymax
 cout << mymax(1.11l, 2.22l) << endl; 	//隐式调用double类型的mymax
 cout << mymax('A', 'C') << endl; 		//隐式调用char类型的mymax
 cout << mymax<int>(1, 2.0) << endl; 	//必须指定int类型

 return 0;
}
