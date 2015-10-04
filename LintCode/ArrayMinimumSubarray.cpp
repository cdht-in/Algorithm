/*
Easy Minimum Subarray

38% Accepted
Given an array of integers, find the subarray with smallest sum.

Return the sum of the subarray.

Have you met this question in a real interview? Yes
Example
For [1, -1, -2, 1], return -3

Note
The subarray should contain at least one integer.

*/

#include "../commonHeader.h"

int minSubArray(vector<int> nums) 
{
	int sum = 0;
	int min = INT_MAX;
	for(int i = 0; i < nums.size(); i++)
	{
		if(sum + nums[i] >= nums[i])
		{
			sum = nums[i];
		}
		else
		{
			sum += nums[i];
		}
		
		min = std::min(min,sum);
	}
	return min;
}

int main()
{
	
}