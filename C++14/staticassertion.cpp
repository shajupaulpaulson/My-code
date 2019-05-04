/****************************************************************** 
My test examples for modern C++ to learn the latest changes in C++ 
https://en.wikipedia.org/wiki/C%2B%2B11 
https://en.wikipedia.org/wiki/C%2B%2B14 
****************************************************************/

#include <iostream>
template <typename T>
struct sum{
	const static T i;
	const static T j;
	const static auto value=i+j;
	sum ( T a, T b) 
	{
		mutable
		i=a;j=b;
	}
};
template <typename T>
struct sub{
	T i;
	T j;
	T value;
	sub ( T a, T b) : i(a), j(b)
	{
		value=i-j;
	}
};

template <typename T>
struct mul{
	T i;
	T j;
	T value;
	mul ( T a, T b) : i(a), j(b)
	{
		value=i-j;
	}
};

template <typename T>
struct division{
	T i;
	T j;
	T value;
	division ( T a, T b) : i(a), j(b)
	{
		if (j != 0)
			value= (i/j);
		else 
			value= 0;
	}
};

int main(){
	sum<int> Sum(10,5);
	//static_assert(Sum::value==15,"Sum incorrect"); //Doesnt work as the value is not constant
	//static_assert(sub(10,5)==5,"sub incorrect");
	//static_assert(mul(10,5)==50,"mul incorrect");
	//static_assert(division(10,5)==2,"div incorrect");
	//static_assert(sum(10,5)==12,"Sum incorrect");//compiler error
	std::cout << Sum.value << std::endl;

}


