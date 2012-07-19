#include <iostream> 
#include <vector> 

using namespace std;  
class array  
{  
    public:  
	    array(int lowbound, int highbound);  
    	vector<int> data;  
    	int size;  
    	int lbound, hbound;  
};  

array::array(int lowbound, int highbound):  
size(highbound-lowbound+1),  
lbound(lowbound),hbound(highbound),  
data(size){}  

int main()  
{  
    array a(0,10);  
    cout <<  a.size <<  '\n';  
    cout <<  a.data.size() <<  '\n';  
} 
