/*
	
Given an array of integers, find two non-overlapping subarrays which have the largest sum.

The number in each subarray should be contiguous.

Return the largest sum.

Have you met this question in a real interview? Yes
Example
For given [1, 3, -1, 2, -1, 2], the two subarrays are [1, 3] and [2, -1, 2] or [1, 3, -1, 2] and [2], they both have the largest sum 7.

Note
The subarray should contain at least one number

Challenge
Can you do it in time complexity O(n) ?
	
*/

#include "../commonHeader.h"

int maxTwoSubArrays(vector<int> nums) 
{
	if(nums.size() <= 1)
	{
		return 0;
	}
	
	vector<int> dp(nums.size(),0);
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
		
		dp[i] = sum;
	}
	
	sum = INT_MIN;
	subSum = 0;
	l = nums.size() - 1;
	r = l;
	int finalSum = INT_MIN;
	for(int i = nums.size() - 1; i >= 0 ; i--)
	{
		if(subSum + nums[i] <= nums[i])
		{
			subSum = nums[i];
			r = i;
		}
		else
		{
			subSum += nums[i];
		}
		
		if(subSum > sum)
		{
			sum = subSum;
			l = i;
		}
		
		if(i >= 1 && dp[i - 1] + sum > finalSum)
		{
			finalSum = dp[i - 1] + sum;
		}
	}
	
	return finalSum;
}

int main()
{
	vector<int> nums = {-1,0,1};
	cout << maxTwoSubArrays(nums) << endl;
}