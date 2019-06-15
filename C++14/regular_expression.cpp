/****************************************************************** 
My test examples for modern C++ to learn the latest changes in C++ 
https://en.wikipedia.org/wiki/C%2B%2B11 
https://en.wikipedia.org/wiki/C%2B%2B14 
****************************************************************/

#include <iostream>
#include <fstream>
#include <regex>
#include <string>

int main(){
	std::ifstream fs( "log/kern.log");
	std::string str = "(EXT)(.*)(error)";
	std::regex rgx (str.c_str());
	std::cmatch match;
	std::string line;
	while (std::getline(fs, line))
	{
		//std::cout << line << std::endl;
		if (std::regex_search(line.c_str(), match, rgx))
		{
			std::string connector = "###";
			std::cout << line << std::endl;
    		const size_t n = match.size();
    		for (size_t a = 0; a < n; a++)
    		{
				std::string str1 (match[a].first,match[a].second);
        		std::cout << str1 << "\n";
     		}
		}

	}
	fs.close();
	return 0;
}
