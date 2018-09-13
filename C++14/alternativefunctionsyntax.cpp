/****************************************************************** 
My test examples for modern C++ to learn the latest changes in C++ 
https://en.wikipedia.org/wiki/C%2B%2B11 
https://en.wikipedia.org/wiki/C%2B%2B14 
****************************************************************/
#include <iostream>

using namespace std;
template <typename T> //typename is important
auto sum(T a, T b) -> decltype(a+b){
	return(a+b);
}
template <typename T> //Template to be defined after every function
auto sub(T a, T b) -> decltype(a-b){
	return(a-b);
}


template<typename K>
auto mul(K a, K b) -> decltype(a*b){
	return (a*b);
}

int main(){
	auto a=3;
	auto b =4;
	auto c= 5.0;
	auto d=.9;
	
	cout<<"Sum of integer"<<sum(a,b)<<endl;
	cout<<"Sub of integer"<<sub(a,b)<<endl;
	cout<<"Mul of integer"<<mul(a,b)<<endl;
	cout<<"Sum of double"<<sum(c,d)<<endl;
	cout<<"Sub of double"<<sub(c,d)<<endl;
	cout<<"Mul of double"<<mul(c,d)<<endl;
}