#include<iostream>

using namespace std;
/*
Allocation of a hall for a set of people

start: { 1, 8, 10}
finish : {5, 11, 12}

output 2

start : {25000, 59000}
finish : { 45000, 75000}

output 2

*/

struct Interval{
	long int start;
	long int finish;
} ;

/*
  Dispaly function to display the table not use in final product for debugging
*/
void display (Interval interval2[]){
	cout << "Interval Start " << endl;
	for (int i=0;i<6;i++)
	{
		cout << interval2[i].start << " ";
	}
	cout <<endl << "Interval End " << endl;
	for (int i=0;i<6;i++)
	{
		cout  << interval2[i].finish << " ";
	}
	cout <<endl;
}

/*
Qsort partition function used to parittion based on pivot choosen at the end or begninning of the array
There is a counter j which suggest the number of swaps done or the array postion till which the values is less than pivot
Then at last swap pivot with the j+1 index
*/
int partition(Interval interval3[], int startindex, int endindex ){
	long int pivot = interval3[endindex].start;
	int j = startindex -1;
	//display (interval3);
	for (int i=startindex; i < (endindex-1); i++){
		//cout << "Inteval.start " << interval3[i].start <<"Pivot"<<pivot<<endl;
	    if (interval3[i].start < pivot){
			j++;
			Interval tmp;
			tmp = interval3[i];
			interval3[i]=interval3[j];
			interval3[j]=tmp;
		}
		//cout<<"Inside Partition"<<endl;
		//display (interval3);
	}
	Interval tmp;
	tmp = interval3[endindex];
	interval3[endindex] = interval3[j+1];
	interval3[j+1]=tmp;
	//cout << "J:" <<j <<"StartIndex :" << startindex <<"EndIndex:" << endindex<< endl;
	return (j+1);
}

/*
Qsort start the quick sort by chossing a value at beginning or end. 
Choose beginning or end as the Quick sort is called in loop either the last or start for easy implementation
*/
void qSort ( Interval interval2[], int start, int last){
	if(start<last){
		int pivot= partition(interval2, start, last);
		//cout <<"First partition" <<"Pivot :" << pivot <<"start :" << start << "last : "<< last <<endl;
		qSort(interval2, start, pivot-1);
		qSort(interval2, pivot+1, last);
		
	}
}

/*
Function starting on the allocation
Calling quick sort to sort
Then it check if the end of a meeting is greater the start of next meeting if not the next meeting is schedulde or else we take the next element

*/

int numberofAlloc(long int *arr1, long int *arr2, int size){
	Interval interval1[6];
	for(int i=0;i<6;i++){
		interval1[i].start=*(arr1+i);
		interval1[i].finish=*(arr2+i);
	}
	//display (interval1);
	qSort(interval1,0,size-1);
	int tmp_first =0, tmp_last=0, alloc=0;
        //display (interval1);
	for(int i=0;i<6;i++){
		if (interval1[i].start >= tmp_last){
			alloc++;
			tmp_last = interval1[i].finish;
		}
	}
	
	
	return alloc;
}

/*
Main function
*/

int main(){
	long int start[]={2,10,7,8,9,4};
	long int finish[]={3,12,8,9,14,6};
	cout << "Number of meeting that could be arranged : " << numberofAlloc(start,finish,6) << endl;
	return 0;
}
