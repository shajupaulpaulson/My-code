#include <iostream>
using namespace std;

bool passwd_check (string &passwd)
{
    string lower = "abcdefghijklmnopqrstuvwxyz";
    string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string special = "@#$%";
    string not_allowed = "_.";
    bool allowed =false;
    if ( passwd.find_first_of(lower)!= std::string::npos){
	allowed = true;
      	cout << "lower true" <<endl;
    }
    if ( passwd.find_first_of(upper)!= std::string::npos){
	allowed = allowed && true; 
      	cout << "upper true" <<endl;
    }
    else{
	allowed = allowed && false;
      	cout << "upper false" <<endl;
    }
    if ( passwd.find_first_of(special)!= std::string::npos){
	allowed = allowed && true; 
      	cout << "special true" <<endl;
    }
    else {
	allowed = allowed && false;
      	cout << "special false" <<endl;
    }
    if ( passwd.find_first_of(not_allowed)!= std::string::npos) {
	allowed = allowed && false;  
      	cout << "not allowed false" <<endl;
    }
    else{
	allowed = allowed && true;  
      	cout << "not allowed true" <<endl;  
    }

    return allowed;
}



int main(){
	string input_password;
	cout <<"Please intput your password : " << endl;
	cin >>input_password;
        bool valid = passwd_check(input_password);
        string final_validation = valid ? "OK" : "NOT OK";
        cout << "The password is "<<final_validation << valid <<endl;
}
