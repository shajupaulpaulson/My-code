#include <iostream>
#include <vector>
#include <memory>
//#include <execution>
#include <filesystem>
#include <numeric>
#include <string>

using namespace std;
int main(){
	string dir = "/home/pau3cob/samba/views/android";
	vector<filesystem::path> paths;
	filesystem::recursive_directory_iterator dirpos(dir);
	copy(begin(dirpos), end(dirpos), std::back_inserter(paths));
	
	/*auto sz = transform_reduce(
				execution::par,
				paths.cbegin(),paths.cend(),
				std_uintmax_t{0},
				plus<>(),
				[](const std::filesystem::path &p){
					return is_regular_file(p) ? file_size (p) : std::uintmax_t{0};
				}
			);*/
	auto sz=0
	for ( auto&s :paths){
		
		sz= sz +	[](const std::filesystem::path &s){
					return is_regular_file(p) ? file_size (p) : std::uintmax_t{0};
				}

	}
	cout << "size is" << sz << endl;
}