/*
	
Given an integer array, find a subarray where the sum of numbers is between two given interval. Your code should return the number of possible answer.

Have you met this question in a real interview? Yes
Example
Given [1,2,3,4] and interval = [1,3], return 4. The possible answers are:

[0, 0]
[0, 1]
[1, 1]
[2, 2]
	
*/

#include "../commonHeader.h"

//O(n^2)
int subarraySumII(vector<int>& A, int start, int end) 
{
	int c = 0;
	for(int i = 0; i < A.size(); i++)
	{
		int sum = 0;
		for(int j = i; j < A.size(); j++)
		{
			sum += A[j];
			if(sum >= start && sum <= end)
			{
				c++;
			}
		}
	}
	return c;
}

int main()
{
	
}