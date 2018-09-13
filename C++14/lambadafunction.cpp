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
void printVector(vector<int> v){
	cout << "values are :" <<endl;
	for(auto x: v){
		cout << x << endl;
	}
}

int main(){
	
	vector<int> v {4, 1, 3, 5, 2, 3, 1, 7}; 
  
    printVector(v); 
	
	auto sum = 0;
	auto it = for_each(v.begin(), v.end(),[&sum](int i)mutable -> int//To remove constant of sum when passed to lambada
	{
		(sum+=i);
	});
	auto fact = 1;
	auto it1 = for_each(v.begin(), v.end(),[&fact](int i)mutable -> int //int is known to compiler tbut for our learning
	{
		(fact*=i);
	});
	auto counter = count_if(v.begin(), v.end(),[](int i) -> bool //int is known to compiler tbut for our learning
	{
		return((i%2)!=0);
	});
	decltype(v) output(10);//If not given size segmentation fault
	auto it2 = remove_copy_if (v.begin(), v.end(),output.begin(),[](int i) -> bool{
		return ((i%3)==0);
	});

	cout << "Sum is" << sum <<endl;
	cout << "Factorial is" << fact <<endl;
	cout << "Number not divisible by 2 is " << counter <<endl;
	printVector(output);
	auto it3 = remove_if (v.begin(), v.end(),[](int i) -> bool{
		return ((i%3)==0);
	});
	printVector(v);
}