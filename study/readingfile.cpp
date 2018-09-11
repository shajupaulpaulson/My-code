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
/*int allocationseat(vector<string> &a, int N){
	
}*/
int main(){
	ifstream  input("/tmp/test.txt");
	string line;
	auto count =0;
	array<string, 3> a{"ab", "cd", "ef"};
	if (input.is_open())
	{
		while ( getline (input,line) )
		{
			//cout << line << '\n';
			auto it = find_if(begin(a), end(a),
                       [&](const string& s)
                       {return line.find(s) != string::npos; });
				if (it != end(a))
				{
					count++;
				}
		}
    input.close();
	}	

	else cout << "Unable to open file"; 

	cout << "Total count is : " << count ;
	return 0;
}