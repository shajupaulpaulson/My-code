#include "exception.h"   
 class  DivideByZeroException;
 
	   Number operator+ (const Number& x, const Number& y)
	   {
		   Number temp(x.getValue()+y.getValue());
		   return temp;
		   
	   }
       Number operator- (const Number& x, const Number& y)
	   {
		   Number temp(x.getValue()-y.getValue());
		   return temp;
		   
	   }	   
       Number operator* (const Number& x, const Number& y)
	   {
		   Number temp(x.getValue()*y.getValue());
		   return temp;
		   
	   }	   
       Number operator/ (const Number& x, const Number& y)
	   {
		   if (y.getValue() ==0)
			   throw (DivideByZeroException temp);
		   Number temp(x.getValue()/y.getValue());
		   return temp;
		   
	   }	   