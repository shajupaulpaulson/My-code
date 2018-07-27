#include<iostream>

std::ostream& operator<<(std::ostream& a, int  (*matrix)[3][3])
{
	int sum = 0;
	for(int i =0; i< 3; i++){
		for ( int j =0;j<3; j++){
			sum +=(*(*((*matrix)+i)+j));
		}
	}
	a << sum;
	a << std::endl;
	return a;
}


int main(){
	int a [3][3] = { {1,2,3}, {4,5,6}, {7,8,9}};
	int b [3][3] = { {11,12,13}, {14,15,16}, {17,18,19}};
	int c [3][3] = { {21,32,43}, {54,65,76}, {87,98,19}};

	std::cout << &a;
	std::cout << &b;	
	std::cout << &c;	
}