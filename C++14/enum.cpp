/****************************************************************** 
My test examples for modern C++ to learn the latest changes in C++ 
https://en.wikipedia.org/wiki/C%2B%2B11 
https://en.wikipedia.org/wiki/C%2B%2B14 
****************************************************************/
#include <iostream>

enum class Enum1 : bool{
	wrong,
	right
};

enum class Enum2 : unsigned int{
	Valintial=0,
	Val1=20,
	Val2,
	Val3,
	Val4
};

enum class Enum3 : unsigned long{
	Val1,
	Val2,
	Val3,
	Val4
};


enum struct Enum4 : unsigned long{
	Val1=10,
	Val2,
	Val3,
	Val4
};

enum Enum5 : unsigned long{
	Val1,
	Val2,
	Val3,
	Val4
};


int main(){

	std::cout << "Enum1 : " << (int)Enum1::wrong << "\n" \
	"Enum2 : " << (int)Enum2::Val2 << "\n" \
	"Enum3 : " << (int)Enum3::Val2 << "\n" \
	"Enum4 : " << (int)Enum4::Val2 << "\n" \
	"Enum5 : " << (int)Enum5::Val2 << "\n" ;
	
	return 0;
}
