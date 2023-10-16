#include<iostream>
#include<string>
#include <bits/stdc++.h>
using namespace std;
class myClass{
public:
const char * const myFunction(const string &input) const
{
	char *a = new char[input.length()];
	for ( int i =0; i< input.length(); i++){
		*(a+i) = input[i];
	}
	return a;
	}
};
int main()
{
	myClass temp;
	string test="myname";
	const char *c = temp.myFunction(test);

	return 0;
}
