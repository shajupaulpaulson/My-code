/*
Consider an array [2,4,3,6,7,3]

we need to find the max difference possible with of a[j]-a[i] For array of size n
whenre 0<=i < j <=n

If the subsequent element is less than the before element no need to calculate

[2,4] = 2
--> next operation not required
[2,4,3,6] = [4,2,3]
[2,4,3,6,7] = [5,3,4,1]
--> no need for the other one

final answer is 5

*/