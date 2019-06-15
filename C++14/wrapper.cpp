/****************************************************************** 
My test examples for modern C++ to learn the latest changes in C++ 
https://en.wikipedia.org/wiki/C%2B%2B11 
https://en.wikipedia.org/wiki/C%2B%2B14 
****************************************************************/

#include <iostream>
#include <functional>

using namespace std;

void incby2 ( int &r)
{ r+=2;}

template<class F, class P> void callinc(F f, P r)
{ f(r); }

int main(){
	int i=0;
	callinc(incby2,i);
	cout << "i = " << i << endl;
	callinc(incby2,ref(i));
	cout << "i = " << i << endl;
	callinc(incby2,i);
	cout << "i = " << i << endl;
	callinc(incby2,ref(i));
	cout << "i = " << i << endl;

	return 0;
}
