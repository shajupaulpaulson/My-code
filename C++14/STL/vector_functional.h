#ifndef VECTOR_FUNCTIONAL_H
#define VECTOR_FUNCTIONAL_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

template <typename T>
class vectorFunction{

public:
	vectorFunction();
	vectorFunction(vectorFunction<T> &Obj);
	vectorFunction( std::vector <T> &vec){
		v.resize(vec.size());
		std::copy(vec.begin(),vec.end(),v.begin());
	};

	void addToVector(std::vector <T> &vec);
	
	void printVector(){
		for_each(v.begin(), v.end(), [] (T i) {
			std::cout << i<<" ";		
		}); 
		std::cout << std::endl;
	};

	void sortingFuncionGreater(){
		std::sort(begin(v), end(v), std::greater<>());
	};

	void sortingFuncionLesser(){
		std::sort(begin(v), end(v), std::less<>());
	};

private:
	std::vector <T> v;
};

#endif
