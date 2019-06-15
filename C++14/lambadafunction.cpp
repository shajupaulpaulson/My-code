/****************************************************************** 
My test examples for modern C++ to learn the latest changes in C++ 
https://en.wikipedia.org/wiki/C%2B%2B11 
https://en.wikipedia.org/wiki/C%2B%2B14 
****************************************************************/
#include <iostream>
#include <string>
#include <utility>
#include <algorithm>
#include <vector>


using namespace std;
template <typename T>
void printVector(vector<T> & v){
	cout << "values are :" <<endl;
	for(auto x: v){
		cout << x << endl;
	}
	cout << endl;
}

template <typename T>
void SumVector(vector<T> & v){
	auto sum = 0;
	auto it = for_each(v.begin(), v.end(),[&sum](T i)mutable -> T//To remove constant of sum when passed to lambada
	{
		(sum+=i);
	});
	cout << "Sum is : " << sum <<endl;
}

template <typename T>
void FactorialVector(vector<T> & v){
	auto fact = 1;
	auto it1 = for_each(v.begin(), v.end(),[&fact](T i)mutable -> T //int is known to compiler tbut for our learning
	{
		(fact*=i);
	});
	cout << "Factorial is : " << fact <<endl;
}

template <typename T>
void Divisblenumbers(vector<T> & v, T value){
	auto counter = count_if(v.begin(), v.end(),[&value](T i) -> bool //int is known to compiler tbut for our learning
	{
		return((i%value)!=0);
	});
	cout << "Total Numbers not divisible by 2 is " << counter <<endl;
}
int main(){
	
	vector<int> v {4, 1, 3, 5, 2, 3, 1, 7}; 
  
    printVector(v); 
	SumVector(v);
	FactorialVector(v);
	Divisblenumbers(v, 2);

	decltype(v) output(v.size());//If not given size segmentation fault
	auto it2 = remove_copy_if (v.begin(), v.end(),output.begin(),[](int i) -> bool{
		return ((i%3)==0);
	});


	printVector(output);
	auto it3 = remove_if (v.begin(), v.end(),[](int i) -> bool{
		return ((i%3)==0);
	});
	printVector(v);
}
