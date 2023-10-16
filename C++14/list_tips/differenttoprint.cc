#include<iostream>
#include <vector>
#include <sstream>
#include <iterator>

using namespace std;
int main(){

// Data stream. Any number of various whitespace characters will be OK.
istringstream istr("1\t 2 3 4");

vector <int> i = { 0, 1, 2, 3, 4, 5, 6};

// Constructing stream iterators and copying data from stream into vector.
copy(
	// Iterator which will read stream data as integers.
	istream_iterator<int>(istr),
	// Default constructor produces end-of-stream iterator.
	istream_iterator<int>(),
	ostream_iterator<int>(std::cout, " -- "));

cout << endl;

copy(
	i.begin(),
	// Default constructor produces end-of-stream iterator.
	i.end(),
	ostream_iterator<int>(std::cout, "\n"));
return 0;

}
