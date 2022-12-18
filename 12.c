/*Kadane’s algorithm for 1D array can be used to reduce the time complexity to O(n^3). 
The idea is to fix the left and right columns one by one and find the maximum sum contiguous
rows for every left and right column pair. We basically find top and bottom row numbers (which have maximum sum)
for every fixed left and right column pair. To find the top and bottom row numbers, calculate sum of elements 
in every row from left to right and store these sums in an array say temp[]. So temp[i] indicates sum of elements 
from left to right in row i. If we apply Kadane’s 1D algorithm on temp[], and get the maximum sum subarray of temp,
this maximum sum would be the maximum possible sum with left and right as boundary columns. To get the overall 
maximum sum, we compare this sum with the maximum sum so far.*/
#include <stdio.h> 
#include <string.h> 
#include <limits.h> 
#define ROW 5 
#define COL 5  
int kadane(int* arr, int* start, int* finish, int n) 
{ 
	int sum = 0, maxSum = INT_MIN, i;
	*finish = -1; 
	int local_start = 0; 
	for (i = 0; i < n; ++i) 
	{ 
		sum += arr[i]; 
		if (sum < 0) 
		{ 
			sum = 0; 
			local_start = i+1; 
		} 
		else if (sum > maxSum) 
		{ 
			maxSum = sum; 
			*start = local_start; 
			*finish = i; 
		} 
	}
	if (*finish != -1) 
		return maxSum;
	maxSum = arr[0]; 
	*start = *finish = 0;
	for (i = 1; i < n; i++) 
	{ 
		if (arr[i] > maxSum) 
		{ 
			maxSum = arr[i]; 
			*start = *finish = i; 
		} 
	} 
	return maxSum; 
} 
void findMaxSum(int M[][COL]) 
{ 
	int maxSum = INT_MIN, finalLeft, finalRight, finalTop, finalBottom; 
	int left, right, i; 
	int temp[ROW], sum, start, finish;
	for (left = 0; left < COL; ++left) 
	{ 
		memset(temp, 0, sizeof(temp)); 
		for (right = left; right < COL; ++right) 
		{  
			for (i = 0; i < ROW; ++i) 
				temp[i] += M[i][right];
			sum = kadane(temp, &start, &finish, ROW);
			if (sum > maxSum) 
			{ 
				maxSum = sum; 
				finalLeft = left; 
				finalRight = right; 
				finalTop = start; 
				finalBottom = finish; 
			} 
		} 
	}
	printf("(Top, Left) (%d, %d)\n", finalTop, finalLeft); 
	printf("(Bottom, Right) (%d, %d)\n", finalBottom, finalRight); 
	printf("Max sum is: %d\n", maxSum); 
} 

int main() 
{ 
	int M[ROW][COL],i,j;
    printf("Enter array elements(5x5) matrix:");
    for ( i = 0; i < ROW; i++)
    {
        for ( j = 0; j < COL; j++)
        {
            scanf("%d",&M[i][j]);
        } 
    }
    printf("Array:\n");
    for ( i = 0; i < ROW; i++)
    {
        for ( j = 0; j < COL; j++)
        {
            printf("%d\t",M[i][j]);
        } 
        printf("\n");
    }
	findMaxSum(M); 
	return 0; 
} 
/*
Conclusion:
Because of the way this algorithm uses optimal substructures (the maximum subarray ending at each position 
is calculated in a simple way from a related but smaller and overlapping subproblem: the maximum subarray 
ending at the previous position) this algorithm can be viewed as a simple example of dynamic programming. 
Kadane’s algorithm is able to find the maximum sum of a contiguous subarray in an array with a runtime of O(n).
*/

/*OUTPUT:
Enter array elements(5x5) matrix:
1 2 -1 -4 -20
-8 -3 4 -2 1
3 8 9 1 3
-4 -1 1 7 -6
-2 -3 8 1 -1
Array:
1       2       -1      -4      -20
-8      -3      4       -2      1
3       8       9       1       3
-4      -1      1       7       -6
-2      -3      8       1       -1
(Top, Left) (2, 1)
(Bottom, Right) (4, 3)
Max sum is: 31*/