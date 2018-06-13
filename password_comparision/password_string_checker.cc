#include <iostream>
using namespace std;

#define uppercase_need true
#define lowercase_need true
#define special_character_need true
#define notallowedcharacter_need true
#define special_characterlist "@#$%"
#define notallowedcharacter_list "_."
#define numbers_needed true

//Color coding
#define green "\033[0;32m"
#define red "\033[7;31m"
#define reset "\033[0m"


bool passwd_check (string &passwd)
{
    string lower = "abcdefghijklmnopqrstuvwxyz";
    string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string numbers = "0123456789";
    string special = special_characterlist;
    string not_allowed = notallowedcharacter_list;
    bool allowed =false;
	if (uppercase_need){
		if ( passwd.find_first_of(lower)!= std::string::npos){
			allowed = true;
			cout << green << "lower true" << reset <<endl;
		}
		else 
			cout << red << "lower false" << reset << endl;
	}
		
	if (lowercase_need){	
		if ( passwd.find_first_of(upper)!= std::string::npos){
			allowed = allowed && true; 
			cout << green << "upper true" << reset <<endl;
		}
		else{
			allowed = allowed && false;
			cout << red << "upper false" << reset <<endl;
		}
	}
	if (numbers_needed)
	{
		if ( passwd.find_first_of(numbers)!= std::string::npos){
			allowed = allowed && true; 
			cout << green << "numbers true" << reset <<endl;
		}
		else {
			allowed = allowed && false;
			cout << red << "numbers false" << reset <<endl;
		}
	}
	if(special_character_need)
	{
		if ( passwd.find_first_of(special)!= std::string::npos){
			allowed = allowed && true; 
			cout << green << "special true" << reset <<endl;
		}
		else {
			allowed = allowed && false;
			cout << red << "special false" << reset <<endl;
		}

	}
	if(notallowedcharacter_need)
	{	
		if ( passwd.find_first_of(not_allowed)!= std::string::npos) {
		allowed = allowed && false;  
			cout << red << "not allowed characters false" << reset <<endl;
		}
		else{
		allowed = allowed && true;  
			cout << green << "not allowed characters true" << reset <<endl;  
		}
	}
    return allowed;
}



int main(){
	string input_password;
	cout <<"Please intput your password : " << endl;
	cin >>input_password;
        bool valid = passwd_check(input_password);
        string final_validation = valid ? "OK" : "NOT OK";
        cout << "The password is "<< (valid?green:red) <<final_validation  <<reset <<endl;
}
