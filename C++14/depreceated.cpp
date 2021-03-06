/****************************************************************** 
My test examples for modern C++ to learn the latest changes in C++ 
https://en.wikipedia.org/wiki/C%2B%2B11 
https://en.wikipedia.org/wiki/C%2B%2B14 
****************************************************************/

#include <iostream>
#include <thread>

using namespace std;
static int abc =2;

// Nice way in Software industry the cheif architect can write these as part of review comments and he could possibly check in so that the developer can work on optimization provided by architect will help in cleaning old code throws a warning fWarnings-depreceated with this compilation would stop
[[deprecated("Deprecteated since the worker thread is not optimized")]]
void WorkerThread(void);

int main(){

	thread t1(WorkerThread);
	int j=3;
	for(auto a=0; a<=j;a++){
		abc *=3;
		cout << "P " <<abc  << " "<<endl;
	}
	t1.join();
	return 0;
}

void WorkerThread(){
	int i =10;
	for(auto a=1; a<=i;a++){
		abc*=a;
		cout << "T " << abc << " " <<endl;
	}
	return;
}


