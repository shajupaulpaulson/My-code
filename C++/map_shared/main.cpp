#include "Car.h"
#include "Cat.h"
#include "Dog.h"
#include "main.h"
#include "base_sound.h"

int main() {

	for(auto const & temp: m_testMap){
		temp.second()->print(temp.first);
	}
	return 0;
}
