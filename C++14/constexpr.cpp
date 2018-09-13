/****************************************************************** 
My test examples for modern C++ to learn the latest changes in C++ 
https://en.wikipedia.org/wiki/C%2B%2B11 
https://en.wikipedia.org/wiki/C%2B%2B14 
****************************************************************/
#include <iostream>
#include <string>
#include <utility>

using namespace std;
constexpr float pi (){
	return(static_cast<float>(22)/static_cast<float>(7));
}

constexpr double spherevolumeworadius=(((pi()) * 4.0)/3.0);
constexpr double conevolumeworadius=((pi())/3);
int main(){
	int radiusofsphere =5;
	int radiusofcone =4;
	cout << "PI :"<< pi() <<endl;
	cout << "Volume of Sphere : "<< (spherevolumeworadius*radiusofsphere)<<endl;
	cout << "Volume of Cone : "<< (conevolumeworadius*radiusofsphere)<<endl;
	return 0;
}

