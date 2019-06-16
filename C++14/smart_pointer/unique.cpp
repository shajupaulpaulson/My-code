#include <iostream>
#include <memory>

using namespace std;
int main(){
	int a =10;
	unique_ptr<int> p1 (new int(10));
	/*
	unique.cpp:7:23: error: conversion from ‘int’ to non-scalar type ‘std::unique_ptr<int>’ requested
  	unique_ptr<int> p1 = a;
	
	unique.cpp:7:23: error: conversion from ‘int*’ to non-scalar type ‘std::unique_ptr<int>’ requested
  	unique_ptr<int> p1 = &a;

	*/
	//unique_ptr<int> p2 = p1;
	/*
	unique.cpp:16:23: error: use of deleted function ‘std::unique_ptr<_Tp, _Dp>::unique_ptr(const std::unique_ptr<_Tp, _Dp>&) [with _Tp = int; _Dp = std::default_delete<int>]’
	unique_ptr<int> p2 = p1;

	*/	
	cout <<"p1 value is : " << *p1 <<endl;
	unique_ptr<int> p2 = move(p1);
	cout <<"p2 value is : " << *p2 <<endl;
	if ( p1 == NULL)
		cout <<"p1 cleared on move"<<endl;
	else
		cout <<"p1 is not null and trying to print "<< *p1 <<endl;

	return 0;
}

