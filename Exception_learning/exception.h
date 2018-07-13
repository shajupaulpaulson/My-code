#include <stdexcept>
#include "BasicExceptionclass.h"

    class Number : public std::runtime_error{
    public:
	  Number (int temp):a(temp){};
      friend Number operator+ (const Number& x, const Number& y);
      friend Number operator- (const Number& x, const Number& y);
      friend Number operator* (const Number& x, const Number& y);
      friend Number operator/ (const Number& x, const Number& y);
      // ...
	  inline const int getValue() const{return a;}
	  private :
	     int a;
    };