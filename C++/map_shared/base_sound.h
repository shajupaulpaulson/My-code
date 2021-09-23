#ifndef BASE_SOUND_H
#define BASE_SOUND_H

class BaseSound {
public:
	BaseSound()=default;
	virtual ~BaseSound()=default;
	virtual void print (int value)=0;
};


#endif
