#include<iostream>
#include <iomanip>
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
	int column_number=4;
	cin >> column_number;
	printpatternsamenumber(column_number);
	printpattern(column_number);
	
}