/****************************************************************** 
My test examples for modern C++ to learn the latest changes in C++ 
https://en.wikipedia.org/wiki/C%2B%2B11 
https://en.wikipedia.org/wiki/C%2B%2B14 
****************************************************************/
#include <string>
#include <iostream>
#include <unordered_map>

template <typename T, typename Z>
class hash_table{
public:
	void addtoHash(T x, Z y){
		hash_set[ x ] = y ;
	};

	void printValue (T x){
		std::cout << "Value for " << x << " : " <<  hash_set[ x ] << endl;
	};


private:
	std::unordered_map<T, Z> hash_set;
};


using namespace std;
int main(){
	hash_table < string, float> obj_hash;
	obj_hash.addtoHash("Banana", 25);
	obj_hash.addtoHash("Mango", 35);
	obj_hash.addtoHash("Apple", 155);
	obj_hash.addtoHash("Cherry", 225);
	obj_hash.addtoHash("Grapes", 55);
	obj_hash.addtoHash("Tomato", 15);
	obj_hash.printValue("Mango");

}
