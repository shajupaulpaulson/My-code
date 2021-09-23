#ifndef CAT_H
#define CAT_H
#include "base_sound.h"
#include <iostream>

class Cat : public BaseSound
{
public:
	Cat()=default;

	virtual void print(int value){ std::cout << "value in Map " << value <<"\nmeow"<<std::endl; };
};


#endif
