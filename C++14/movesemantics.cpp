/****************************************************************** 
My test examples for modern C++ to learn the latest changes in C++ 
https://en.wikipedia.org/wiki/C%2B%2B11 
https://en.wikipedia.org/wiki/C%2B%2B14 
****************************************************************/
#include <iostream>
#include <string>
#include <utility>
using namespace std;
//copy ellision
class Student {
	public:
	Student(string n, int a):name(n), age(a){};
	Student (const Student &t){
		name = t.name;
		age = t.age;
		cout << "copy constructor"	<<endl;
	}
	Student(Student &&t): name(" "), age(0){
		name = t.name;
		age = t.age;
		t.name = "default";
		t.age = 0;
		cout << "Move constructor"	<<endl;
	}
	void print(){
		cout << "Name is : " << name <<endl;
		cout << "Age is  : " << age <<endl;
	}
	private:
	string name;
	int age;
	
};

int main(){
	Student stud1("Test1",12);
	Student stud4("Test1",13);
	Student & rstud1=stud1;
	Student&& stud2 = move(stud4);//copy ellision
	Student stud3(stud2);
	stud1.print();
	stud2.print();
	std::pair<int,Student> a(3,Student("test2",2));// Move constructor
	stud3.print();
	
}