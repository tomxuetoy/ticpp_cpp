#include <iostream>

using namespace std; 

int main () 
{ 
int a=5;               // initial value = 5
int b(2);              // initial value = 2
int result;            // initial value undetermined
  a = a + 3;
  cout << result << endl;	//local variable is in stack, so its content is random each time the program runs
  result = a - b; 
  cout << result << endl; 

  return 0;
}

/*
Running result:

maemo@maemo-desktop:~/windows/mycode/trial_cpp_local-varial-in-stack$ ./a.out 
9388020
6
maemo@maemo-desktop:~/windows/mycode/trial_cpp_local-varial-in-stack$ ./a.out 
10842100
6
maemo@maemo-desktop:~/windows/mycode/trial_cpp_local-varial-in-stack$ ./a.out 
2654196
6
maemo@maemo-desktop:~/windows/mycode/trial_cpp_local-varial-in-stack$ ./a.out 
4968436
6
*/
