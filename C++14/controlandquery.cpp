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
	cout << "Aligment of : \n"\
	"Char " << alignof(char) << "\n" \
	"int " << alignof(int) << "\n" \
	"double " << alignof(float) << "\n" \
	"Bool " << alignof(bool) << "\n" \
	"test " << alignof(test) << "\n" \
	"test2 " << alignof(test2) << "\n" \
	"test3 " << alignof(test3) << "\n" \
	"test4 " << alignof(test4) << "\n" \
	"xyz " << alignof(xyz) << "\n"; 


	return 0;
}
