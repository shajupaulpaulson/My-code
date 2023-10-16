#include <iostream>
using namespace std;
/*
Given an array consisting of cost of toys. Given an integer K depicting the amount of money available to purchase toys. Write a program to find the maximum number of toys one can buy with the amount K.

Note: One can buy only 1 quantity of a particular toy.

Examples :

Input:  N = 10, K =  50
        cost = { 1, 12, 5, 111, 200, 1000, 10, 9, 12, 15 }
Output: 6
Explanation: Toys with amount 1, 5, 9, 10, 12, and 12 
can be purchased resulting in a total amount of 49. Hence,
maximum number of toys is 6.

Input: N = 7, K = 50
       cost = { 1, 12, 5, 111, 200, 1000, 10 }
Output: 4


*/
int partition(int *toys, int start, int end){
	int i=start, j=start-1;
	int median = toys[end];
	for (;i<=end-1;i++){ // <= because last before element has to be checked with median which is the last
		if ( toys [i] < median){
        	j++;
			int tmp;
			tmp = toys[i];
			toys[i] = toys[j];
			toys[j] = tmp;
		}
	}

	int tmp;
	tmp = toys[end];
	toys[end] = toys[j+1];
	toys[j+1] = tmp;
	return (j+1);
}

void quicksorttoys( int *toys, int start, int end){
	if (start <end){
		int pivot= partition(toys,start,end);
		quicksorttoys(toys,start,pivot-1);
		quicksorttoys(toys,pivot+1,end);
	}
}

int numberoftoys( int *toys, int N, int K){
	for(int i =0,sum =0 ; i<N; i++)
	{
		sum+=(toys[i]);
		cout << sum <<endl;
		if (sum > K)
			return i;
	}
}
int main(){
	int N=10;
	int k = 50;
	int toys[N] ={ 1, 12, 5, 111, 200, 1000, 10, 9, 12, 15 };
	
	quicksorttoys(toys, 0, N-1);
	int final_toys = numberoftoys(toys, N-1, k);
	cout <<"Total number of toys " << final_toys << endl;
	
}