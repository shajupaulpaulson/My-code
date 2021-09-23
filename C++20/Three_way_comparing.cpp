#include <compare>
#include <iostream>
#include <math.h>

using namespace std;
int main(){
	cout << "Please input square coefficient"<<endl;
	int square_data;
	cin >> square_data
	cout << "Please input cube coefficient"<<endl;
	int cube_data;
	cin >> cube_data;
	
	square_data=pow(square_data,2);
	cube_data=pow(square_data,3);
	
	auto whichBetter= square_data <=> cube_data;
	if (whichBetter == 0)
		cout << "They are equal" <<endl;
	else if (whichBetter < 0)
		cout << "Square is better" <<endl;
	else
		cout << "Cube is better" <<endl;	
	return 0;
}

