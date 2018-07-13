#include <stdexcept> // stdexcept header file contains runtime_error
using std::runtime_error; // standard C++ library class runtime_error
class DivideByZeroException : public runtime_error
{
public:
 // constructor specifies default error message
 DivideByZeroException()
 : runtime_error( "attempted to divide by zero" ) {}
};

class Underflow : public runtime_error
{
public:
 // constructor specifies default error message
 Underflow()
 : runtime_error( "attempted to divide by zero" ) {}
};

class Overflow : public runtime_error
{
public:
 // constructor specifies default error message
 Overflow()
 : runtime_error( "attempted to divide by zero" ) {}
};