#include <string>
#include <iostream>

using namespace std;

template <typename T>
class Calculator{
public:
	Calculator() = delete;
	Calculator ( T i, T j):varA(i), varB(j) { };
	Calculator ( string i, string j) = delete;
	Calculator ( Calculator <T> &obj) {
	this.varA = obj.varA;
	this.varB = obj.varB; };

	void add (){
		cout << "Sum is : " << varA+varB;
	};

	void sub (){
		cout << "Sub is : " << varA-varB;
	};

	void pro (){
		cout << "Pro is : " << varA*varB;
	};


	void div (){
		(varB != 0) ? cout << "Divide by Zero" : cout << "Div is : " << varA/varB;
	};
private:
	T varA, varB;
};
