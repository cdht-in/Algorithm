/*
	
	Given two array of integers(the first array is array A, the second array is array B), now we are going to find a element in array A which is A[i], and another element in array B which is B[j], so that the difference between A[i] and B[j] (|A[i] - B[j]|) is as small as possible, return their smallest difference.

	Have you met this question in a real interview? Yes
	Example
	For example, given array A = [3,6,7,4], B = [2,8,9,3], return 0

	Challenge
	O(n log n) time
*/

#include "../commonHeader.h"

int smallestDifference(vector<int> &A, vector<int> &B) 
{
	sort(A.begin(),A.end());
	sort(B.begin(),B.end());
	int i = 0, j = 0;
	int min = INT_MAX;
	while(i < A.size() && j < B.size())
	{
		int distance = (A[i] >= B[j])? (A[i] - B[j]) : (B[j] - A[i]);
		min = (min < distance) ? min : distance;
		if(A[i] == B[j])
		{
			break;
		}
		else if(A[i] < B[j])
		{
			i++;
		}
		else
		{
			j++;
		}
	}
	
	return min;
	
}

int main()
{
	
}