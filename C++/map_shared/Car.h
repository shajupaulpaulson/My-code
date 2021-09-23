#ifndef CAR_H
#define CAR_H
#include "base_sound.h"
#include <iostream>

class Car : public BaseSound
{
public:
	Car()=default;
	virtual ~Car()=default;
	virtual void print(int value){ std::cout << "value in Map " << value <<"\narrgh"<<std::endl; };
};


#endif
