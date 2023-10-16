#include<iostream>

using namespace std;
/*
Consider  two inputs from user a point and sets of pair of elments if plotted horizontally find with the input.
Then the possible output is how many sets will be covered with the give input if not how much more data is required for intersecting

input1 : 3
input2 :  {{1,3},{2,4},{3.6}}

Output:1
0 1 2 3 4 5 6 7 8
  -----
    -----
	  -------
	  |
	  
input1 : 2
input2 : {{1,3},{3,6},{2,8}}

Output : 2
0 1 2 3 4 5 6 7 8 9
  -----
      -------
	-------------
	|
*/


int minPath ( int input1, int input2[][2], int rows, int cols)
{
	
	//cout << rows << " "<< cols << endl;
	int count = 0;
	for(int i=0;i<rows;i++)
	{       
		if ( input1 >= input2[i][0] && input1 <= input2[i][1])
			continue;
		else 
			count++;
	}
	return ++count;
}

int main()
{
	int input1 =2;
	int input2 [][2]= {{1,3},{2,4},{2,6}};
	
	cout <<"output : " << minPath(input1, input2, 3 ,2) <<endl;
}
