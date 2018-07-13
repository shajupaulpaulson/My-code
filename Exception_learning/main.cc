#include <iostream>
#include "exception.h"
#include<limits.h>

using namespace std;
int main(){
  int temp = 0;
  
  cout << "Enter values for first class :" <<endl;
  cin >> temp;
  Number x(temp);
  
  cout << "Enter values for Second class :" <<endl;
  cin >> temp;
  Number y(temp);
  try { 
  Number sum  = x + y;
  Number diff = x - y;
  Number prod = x * y;
  Number quot = x / y;
    }
  catch (Number::Overflow& exception) {
    // ...code that handles overflow...
  }
  catch (Number::Underflow& exception) {
    // ...code that handles underflow...
  }
  catch (Number::DivideByZero& exception) {
    // ...code that handles divide-by-zero...
	cout <<"In divide by zero" <<endl;
  }
}
