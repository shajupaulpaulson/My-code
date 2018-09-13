/****************************************************************** 
My test examples for modern C++ to learn the latest changes in C++ 
https://en.wikipedia.org/wiki/C%2B%2B11 
https://en.wikipedia.org/wiki/C%2B%2B14 
****************************************************************/
#include <iostream>
#include <string>
#include <utility>
#include <array>
//#include <dynarray>
using namespace std;

struct TVGuide
{
    unsigned int channelnumber;
    string channelname;
};

void printChannelguide(initializer_list<TVGuide> channeldetails){
	int sizeoflist = channeldetails.size();
	cout << "Size of list : " << sizeoflist << endl;
	for (auto x : channeldetails){
		cout << " Channel number :" << x.channelnumber << " - " << x.channelname << endl;
	}
}
template<size_t SIZE>
void printChannelguide(array<TVGuide, SIZE>& arr){
	cout << "Size of list : " << SIZE << endl;
	for (auto x : arr){
		cout << " Channel number :" << x.channelnumber << " - " << x.channelname << endl;
	}
}

/*void printChannelguide(dynarray<TVGuide>& arr){
	cout << "Size of list : " << arr.size() << endl;
	for (auto x : arr){
		cout << " Channel number :" << x.channelnumber << " - " << x.channelname << endl;
	}
}*/
void newchannel(initializer_list<int> channelnumber){
	int sizeoflist = channelnumber.size();
	cout << "Size of list : " << sizeoflist << endl;
	for (auto x : channelnumber){
		cout << " Channel number is :" << x << endl;
	}
}

int main(){
	TVGuide sports={256,"Sports1"};
	TVGuide FavMoview [] = {{151,"HBO"},{152,"Movies Now"},{154,"WB"}};
	printChannelguide({{151,"HBO"},{152,"Movies Now"},{154,"WB"}});
	int sizearr=(sizeof(FavMoview)/sizeof(*FavMoview));
    std::array<TVGuide,3> Y;
    std::copy(std::begin(FavMoview), std::end(FavMoview), std::begin(Y));	
	printChannelguide(Y);
	//dynarray<TVGuide> arr(sizearr);
	newchannel({901, 902, 903});
	return 0;
}
	
	