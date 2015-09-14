/*
	
Given an unsorted integer array, find the first missing positive integer.

Have you met this question in a real interview? Yes
Example
Given [1,2,0] return 3, and [3,4,-1,1] return 2.

Challenge
Your algorithm should run in O(n) time and uses constant space.
	
*/

#include "../commonHeader.h"

//usec index i to store index i + 1
int firstMissingPositive(vector<int> A) 
{
	for(int i = 0; i < A.size(); i++)
	{
		if(A[i] != i + 1)
		{
			int jumpTo = A[i] - 1;
			//BFS
			while(jumpTo >= 0 && jumpTo < A.size() && A[jumpTo] != jumpTo + 1)
			{
				int tmp = A[jumpTo] - 1;
				A[jumpTo] = jumpTo + 1;
				jumpTo = tmp;
			}
		}
	}
	
	for(int i = 0; i < A.size(); i++)
	{
		if(A[i] != i + 1)
			return i + 1;
	}
	
	return A.size() + 1;
}

int main()
{
	vector<int> A = {};
	cout << firstMissingPositive(A) << endl;
}