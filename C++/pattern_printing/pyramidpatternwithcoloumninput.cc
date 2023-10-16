#include<iostream>
#include <iomanip>
#include <sstream>
#include <string>
using namespace std;
/*
Input : n = 4
Output :
1

5 2

8 6 3

10 9 7 4

Input : n = 6
Output :
1
7 2
12 8 3
16 13 9 4
19 17 14 10 5
21 20 18 15 11 6
*/

void printpatternsamenumber(int &column_number ){
	int i = 1 ;
	while (i <= column_number)
	{   int j = 0;
		while ( j< i)
		{
			cout << std::setw(5) << i << " ";
			j++;
		}
		cout << endl;
		i++;
	}
	
}

void printpattern(int &column_number ){
	int i = 1 ;
	while (i <= column_number)
	{   int j = 1;
		while ( j<= i)
  		{ 	int sum =0;
			int local_i = i-j; // number of iteration to add 
			int maxsum= column_number-i+j; //maximum sum to add depened on the row and also the column postion
			while (local_i !=0)
			{
				sum +=maxsum;
				local_i--;
				maxsum++;
			}
			cout << std::setw(5)<< (i+sum) << " ";
			j++;
		}
		cout << endl;
		i++;
	}
	
}
int main ()
{
	long int column_number=4;
	string text;
	int error =0;
	/*
	Defining such a way that user can take only integer.
	*/
	do{
		if (error > 0)
		{
			cout <<" Please enter a valid number between 0 to 32767" <<endl <<"Or press E or q to exit or quit" <<endl;
		}
		cout << "Please enter a number" << endl;
		cin >> text;
		if(text == "E" || text == "e" || text == "exit" || text == "Q" || text == "q" || text == "Quit") {
			cout<<"Exiting program";
			return(2);
		}
	
		stringstream txt(text);
		txt >> column_number;
		cout << "Number decided " << column_number << endl;
		error++;
	}while (column_number > 32767 || column_number <= 0);
    int col = static_cast <int>(column_number) ;
		
	printpatternsamenumber(col);
	printpattern(col);
	
}