/****************************************************************** 
My test examples for modern C++ to learn the latest changes in C++ 
https://en.wikipedia.org/wiki/C%2B%2B11 
https://en.wikipedia.org/wiki/C%2B%2B14 
****************************************************************/

#include <tuple>
#include <iostream>
using namespace std;

int main()
{
	tuple <string,string, int> emp1 ("ABC", "XYZ", 72);
	cout << std::get<int>(emp1) << endl;
	cout << std::get<0>(emp1) << endl;
	cout << std::get<1>(emp1) << endl;
	cout << std::get<2>(emp1) << endl;

	std::get<1>(emp1) = "LASTNAME";
	cout << std::get<0>(emp1) << endl;
	cout << std::get<1>(emp1) << endl;
	cout << std::get<2>(emp1) << endl;
}
