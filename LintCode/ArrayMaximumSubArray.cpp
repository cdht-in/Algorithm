/*
	
Given an array of integers, find a contiguous subarray which has the largest sum.

Have you met this question in a real interview? Yes
Example
Given the array [−2,2,−3,4,−1,2,1,−5,3], the contiguous subarray [4,−1,2,1] has the largest sum = 6.

Note
The subarray should contain at least one number.

Challenge
Can you do it in time complexity O(n)?
	
*/

#include "../commonHeader.h"

int maxSubArray(vector<int> nums) 
{
	int sum = INT_MIN;
	int subSum = 0;
	int l = 0, r = 0;
	for(int i = 0; i < nums.size(); i++)
	{
		if(subSum + nums[i] <= nums[i])
		{
			subSum = nums[i];
			l = i;
		}
		else
		{
			subSum += nums[i];
		}
		
		if(subSum > sum)
		{
			sum = subSum;
			r = i;
		}
	}
	
	return sum;
}

int main()
{
	
}