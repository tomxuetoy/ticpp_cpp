//vector µÄ±éÀúÊä³ö

#include <iostream>
#include <vector>

using namespace std;

int main()
{
 int a[7]={1,2,3,4,5,6,7};
  vector<int> va(a,a+7);
  vector<int> va2(10,42);
   for(int i=0;i<va.size();i++)
     {
	 	cout<<va[i]<<" ";
		cout<<va.size()<<endl;

		cout<<va2[i]<<" ";
		cout<<va2.size()<<endl;
	 }
}
