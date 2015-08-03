/*
	
Medium Continuous Subarray Sum

20% Accepted
Given an integer array, find a continuous subarray where the sum of numbers is the biggest. Your code should return the index of the first number and the index of the last number. (If their are duplicate answer, return anyone)

Have you met this question in a real interview? Yes
Example
Give [-3, 1, 3, -3, 4], return [1,4].
	
*/

#include "../commonHeader.h"

vector<int> continuousSubarraySum(vector<int>& A) 
{
	int subSum = 0;
	int max = INT_MIN;
	int begin = 0;
	int end = 0;
	int tmpStart = 0;
	for(int i = 0; i < A.size(); i++)
	{
		if(subSum + A[i] < A[i])
		{
			subSum = A[i];
			tmpStart = i;
		}
		else
		{
			subSum += A[i];
		}
	
		if(subSum > max)
		{
			max = subSum;
			end = i;
			begin = tmpStart;
		}
	}
	
	return vector<int>({begin,end});
}

int main()
{
	
}