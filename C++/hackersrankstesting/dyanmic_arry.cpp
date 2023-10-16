#include <iostream>
/*
Given an array of integers, find the subset of non-adjacent elements with the maximum sum. Calculate the sum of that subset.

For example, given an array  we have the following possible subsets:

Subset      Sum
[-2, 3, 5]   6
[-2, 3]      1
[-2, -4]    -6
[-2, 5]      3
[1, -4]     -3
[1, 5]       6
[3, 5]       8
Our maximum subset sum is .

Function Description

Complete the  function in the editor below. It should return an integer representing the maximum subset sum for the given array.

maxSubsetSum has the following parameter(s):

arr: an array of integers
Input Format

The first line contains an integer, . 
The second line contains  space-separated integers .

Constraints

Output Format

Return the maximum sum described in the statement.

Sample Input 0

5
3 7 4 6 5
Sample Output 0

13
*/
using namespace std;

int maxSubsetSum (int *arr, int arraysize){
	int *temparr = arr;
	int sum; int firstassign=true;
	int i,j;
	for ( i=0; i < arraysize; i++){
		int tempsum=0;
		for ( j = i+2; j < arraysize; j+=2){
			tempsum= tempsum + arr[i] + arr[j];
			if (firstassign)
				sum=tempsum,firstassign=false;
			if (tempsum > sum)
				sum = tempsum;
		}
	}
	return sum;
}

int main( int argc, char **argv){
	int arraysize;
	int *arr = NULL;
 	for (int i = 0; i < argc; ++i) {
        cout << argv[i] << "\n"; 
		switch (i){
			case 0:
				//Executable name dont do anything
				break;
			case 1:
				arraysize=atoi(argv[i]);
				arr= new int [arraysize];
				//Executable name dont do anything
				break;
			default:
				arr[i-2]=atoi(argv[i]);		
		}
	}
	
	for (auto i = 0; i< arraysize; i++)
		cout << arr[i] << " " ;
	
	cout << maxSubsetSum (arr, arraysize);	
	delete [] arr;
}
