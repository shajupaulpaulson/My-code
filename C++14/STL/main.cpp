#include "vector_functional.h"


int main(){
	
	std::vector <int> vec ={11,2,4,5,22,33,24,2,0,-9};
	vectorFunction <int> vecfunc_obj(vec);
	vecfunc_obj.sortingFuncionGreater();
	vecfunc_obj.printVector();
	vecfunc_obj.sortingFuncionLesser();
	vecfunc_obj.printVector();
	return 0;
}

