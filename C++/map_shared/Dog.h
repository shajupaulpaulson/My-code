#ifndef DOG_H
#define DOG_H
#include "base_sound.h"
#include <iostream>

class Dog : public BaseSound
{
public:
	Dog()=default;

	virtual void print(int value){ std::cout << "value in Map " << value <<"\nWohhh"<<std::endl; };
};


#endif
