/****************************************************************** 
My test examples for modern C++ to learn the latest changes in C++ 
https://en.wikipedia.org/wiki/C%2B%2B11 
https://en.wikipedia.org/wiki/C%2B%2B14 
****************************************************************/

#include <iostream>
#include <string>

using namespace std;

void test(int i){
	cout << "Value of i " <<i<<endl;
}

int main (){
	int *p = nullptr; // future of NULL
	test(NULL); //Works as NULL is zero 
	test(2);

	return 0;
}

/*

~/project/C++14$ g++ nullpointer.cpp 
nullpointer.cpp: In function ‘int main()’:
nullpointer.cpp:18:11: warning: passing NULL to non-pointer argument 1 of ‘void test(int)’ [-Wconversion-null]
  test(NULL); //Works as NULL is zero
           ^
~/project/C++14$ ./a.out 
Value of i 0
Value of i 2

*/

