#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <array>
using namespace std;

/*
a[11] = { 5,2,-1,0,3,-4,5}
longest sequence of wobling postive and negative integer
0 is considered both postivie and negative depending on the need
*/
int longest_list(vector<int> &a){
	int longest=0;
	auto it = a.begin();
	while (it != a.end()){
		int count=0;
		auto next_element = it+1;
		while (next_element != a.end()){
			if ( ( (*it <= 0) && (*next_element >= 0) ) ||
				 ( (*it >= 0) && (*next_element <= 0) ) )	{
				count++	 ;
			}
			cout << *it << " " << *next_element << endl;
			it++;
			next_element++;
		}
		count > longest ? longest = count : count =0;
		it++;
	}
	return longest;
}

int main(){
	vector<int> a ={5,2,0,3,-4,0,-2,1,0,1,2,-4};
	int count =longest_list(a);
	
	cout << "Total count is : " << count ;
	return 0;
}