#include <iostream>

using namespace std;

template <class T> 	//classҲ����typename�滻
T mymax(T a, T b) 	//�����ͷ���ֵ����T����
{
 return a > b? a: b;
}

int main()
{
 cout << mymax(1, 2) << endl; 			//��ʽ����int���͵�mymax
 cout << mymax(1.1f, 2.2f) << endl; 	//��ʽ����float���͵�mymax
 cout << mymax(1.11l, 2.22l) << endl; 	//��ʽ����double���͵�mymax
 cout << mymax('A', 'C') << endl; 		//��ʽ����char���͵�mymax
 cout << mymax<int>(1, 2.0) << endl; 	//����ָ��int����

 return 0;
}
