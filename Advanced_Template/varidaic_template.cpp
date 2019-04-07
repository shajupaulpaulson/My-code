#include <iostream>
#include <features.h>

using namespace std;

#define RED  "\x1B[31m"
#define RST  "\x1B[0m"
#define FRED(x) RED x RST

enum Level {
    debug, error, warning, info
};
void print(){
	cout <<endl;

}

template <typename Tone, typename... Trem>
void print (Tone x, Trem... rem){
	cout << x << " ";
	print(rem...);
}

void printw(){
	cout <<endl;

}
template <typename Tone, typename... Trem>
void printw (Tone x, Trem... rem){
	cout  << "\033[1;31m" << x << "\033[0m" << " ";
	printw(rem...);
}


#define LOG_LEVEL_DEBUG(...) print(__VA_ARGS__)
#define LOG_LEVEL_WARN(...) printw(__VA_ARGS__)
#define LOG_LEVEL (Level n, ...) if ( n == warning) {\
									LOG_LEVEL_WARN (...) ;\
								 } \
								 else \
									LOG_LEVEL_DEBUG (...)

int main(){

	LOG_LEVEL_WARN(Level::warning, "A sample warning", 4.5, 2 , "Done with it");
	LOG_LEVEL_DEBUG(Level::debug, "Debug warning", 3434, 1232);


}
