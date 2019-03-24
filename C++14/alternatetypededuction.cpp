/****************************************************************** 
My test examples for modern C++ to learn the latest changes in C++ 
https://en.wikipedia.org/wiki/C%2B%2B11 
https://en.wikipedia.org/wiki/C%2B%2B14 
****************************************************************/
#include <iostream>
#include <typeinfo>
#include <string>

using namespace std;

int main(){
	int a =10;
	auto b= 2.5;
	decltype(a) c;
	char d;
	auto e = 'z';
	string f = "test";
	decltype(f) g;
	float h;
	bool i;
	cout << "Variable type of a is " << typeid(a).name() <<endl;
	cout << "Variable type of b is " << typeid(b).name() <<endl;
	cout << "Variable type of c is " << typeid(c).name() <<endl;
	cout << "Variable type of d is " << typeid(d).name() <<endl;
	cout << "Variable type of e is " << typeid(e).name() <<endl;
	cout << "Variable type of f is " << typeid(f).name() <<endl;
	cout << "Variable type of g is " << typeid(g).name() <<endl;
	cout << "Variable type of h is " << typeid(h).name() <<endl;
	cout << "Variable type of i is " << typeid(i).name() <<endl;

	return 0;
}
