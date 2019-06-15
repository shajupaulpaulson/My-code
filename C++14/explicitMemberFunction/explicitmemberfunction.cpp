/****************************************************************** 
My test examples for modern C++ to learn the latest changes in C++ 
https://en.wikipedia.org/wiki/C%2B%2B11 
https://en.wikipedia.org/wiki/C%2B%2B14 
****************************************************************/

#include "Calculator.h"

int main (){

	Calculator <int> aCalc(8,9);
	aCalc.add();
	aCalc.sub();
	aCalc.pro();
	aCalc.div();
	Calculator <float> bCalc(8,0);
	bCalc.add();
	bCalc.sub();
	bCalc.pro();
	bCalc.div();
	Calculator <double>cCalc(0,8);
	cCalc.add();
	cCalc.sub();
	cCalc.pro();
	cCalc.div();
	//Calculator cCalc("ten","eleven");
	//error: missing template arguments before ‘cCalc’

	return 0;
}
