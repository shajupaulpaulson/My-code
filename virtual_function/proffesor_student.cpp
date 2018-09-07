#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


#include <sstream>
class Person{
    public:
    virtual void getdata(){cout <<"Parent class"<<endl;}
    virtual void putdata(){cout <<"Parent class"<<endl;}
    void updateName (string n) { name =n;}
    void printName(){cout << name << " ";}
    private:
    string name;

};

class Professor : public  Person{
    virtual void updateAge (int n) { age =n;}
    virtual void printAge(){cout << age << " ";}
	virtual void updatePub (int n) { publication =n;}
    virtual void printP(){cout << publication << " ";}
    void getdata(){
    //cout <<"Parent" ;
		string Name;
		cin >> Name;
		cin >> age;
		cin >> publication; 
        updateName(Name);
        local_id=id;
        Professor::id++;
    }
    void putdata(){
        printName();
        printAge();
		printP();
        cout <<  local_id << endl;
    }
    private:
    int age;
	int publication;
    int local_id;
    static int id;
};
int Professor::id=1;
class Student : public Person{
    virtual void updateScore (int n) { score =n;}
    virtual void printScore(){cout << score << " ";}
	virtual void printAge(){cout << age << " ";}
    void getdata(){
		string Name,line;
		cin >> Name;
		cin >> age;
        getline (cin,line);
        stringstream ss(line);
    
        int total=0;
        int marks;
        while (!ss.eof()){
            ss>>marks;
            total+=marks;
        }
        updateName(Name);
        updateScore(total);
        local_id=id;
        Student::id++;
    }
    void putdata(){
        printName() ;
		printAge();
        printScore();
        cout << local_id << endl;
    }
    private:
	int age;
    int score;
    int local_id;
    static int id;
};
int Student::id=1;

int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
