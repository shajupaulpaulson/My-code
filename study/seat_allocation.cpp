#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <array>
using namespace std;

/*
		A	B	C		D	E	F	G		H	I	J
1
2
3
.
.
N
*/
int allocationseat(vector<string> &a, int N){
	int count=0;
	bool found =false;
	for(int i=1; i<= N; i++){
		auto col1 ={to_string(i)+"A", to_string(i)+"B", to_string(i)+"C"};
		//vector<string>::iterator it;

		for (auto x: col1){
			auto it = find ( a.begin(), a.end(), x);
			cout << x << endl;
			if (it != a.end())
			{
				found = true;
				break;
			}
		}
		found == false?count++:found = false;
		
		auto col2 ={to_string(i)+"H", to_string(i)+"I", to_string(i)+"J"};
		//vector<string>::iterator it;

		for (auto x: col2){
			auto it = find ( a.begin(), a.end(), x);
			cout << x << endl;
			if (it != a.end())
			{
				found = true;
				break;
			}
		}
		found == false?count++:found = false;
		
		auto col3 ={to_string(i)+"E", to_string(i)+"F"};
		//vector<string>::iterator it;

		for (auto x: col3){
			auto it = find ( a.begin(), a.end(), x);
			cout << x << endl;
			if (it != a.end())
			{
				found = true;
				break;
			}
		}
		if (found == false){
			auto col4 ={to_string(i)+"D", to_string(i)+"G"};
		//vector<string>::iterator it;

			for (auto x: col3){
				auto it = find ( a.begin(), a.end(), x);
				cout << x << endl;
				if (it == a.end())
				{
					count++;
					break;
				}
			}
			
		}
		
		found = false;
		/*it = find_if(col1.begin(), col1.end(),
		   [a](string &s)
		   {return find(a.begin(), a.end(), s); });
		if (it != a.end())
		{
			count++;
		}*/
	}
	return count;
}

int main(){
	vector<string> a ={"1C", "2D", "1H"};
	int N =2;
	int count =allocationseat(a,N);
	
	cout << "Total count is : " << count ;
	return 0;
}