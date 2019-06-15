/****************************************************************** 
My test examples for modern C++ to learn the latest changes in C++ 
https://en.wikipedia.org/wiki/C%2B%2B11 
https://en.wikipedia.org/wiki/C%2B%2B14 
****************************************************************/

#include <iostream>     // std::cout
#include <cstdlib>      // std::exit
#include <new>          // std::set_new_handler

void OOM(){
	std::cout << " Out of memory " << std::endl;
	std::exit(1);
}



int main(){
	std::set_new_handler(OOM);
	float* p = new float [1024*1024*1024];
  	std::cout << "Ok\n";
  	delete[] p;

	return 0;
}

