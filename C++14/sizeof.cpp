/****************************************************************** 
My test examples for modern C++ to learn the latest changes in C++ 
https://en.wikipedia.org/wiki/C%2B%2B11 
https://en.wikipedia.org/wiki/C%2B%2B14 
****************************************************************/

#include <iostream>
#include <string>

struct test{

	char a;
	int b;
	float c;
	std::string d;

};

class xyz{
	public:	
		xyz(){}
		int k;
		float l;
	private:
		int m;
		std::string n;
		char o;

};

struct test2{
	char a;
	int b;
	float c;
	std::string d;
	void print4(){
		std::cout <<"test"<<std::endl;}
};

union test3{

	char a;
	int b;
	float c;
};

union alignas(128) test4{

	char a;
	int b;
	float c;
};


using namespace std;
int main(){
	cout << "size of without object : \n"\
	"test " << sizeof(test) << "\n" \
	"test2 " << sizeof(test2) << "\n" \
	"test3 " << sizeof(test3) << "\n" \
	"test4 " << sizeof(test4) << "\n" \
	"xyz " << sizeof(xyz) << "\n"; 


	return 0;
}

