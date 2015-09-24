/*
	
Given an array of integers and a number k, find k non-overlapping subarrays which have the largest sum.

The number in each subarray should be contiguous.

Return the largest sum.

Have you met this question in a real interview? Yes
Example
Given [-1,4,-2,3,-2,3], k=2, return 8

Note
The subarray should contain at least one number

*/

#include "../commonHeader.h"

int maxSubArray(vector<int> nums, int l, int r)
{
	int max = INT_MIN;
	int sum = 0;
	for(int i = l; i <= r; i++)
	{
		if(sum + nums[i] <= nums[i])
		{
			sum = nums[i];
		}
		else
		{
			sum += nums[i];
		}
		
		if(sum > max)
		{
			max = sum;
		}
	}
	return max;
}

int maxSubArrayHelper(vector<int>& nums,vector<vector<int> >& dp,int index,int k)
{	
	if(k == 1)
	{
		return dp[index][dp.size() - 1];
	}
	
	int max = INT_MIN;
	for(int i = index; i < dp.size() - 1; i++)
	{
		int lSum = dp[index][i];
		int rSum = maxSubArrayHelper(nums,dp,i + 1,k - 1);
		max = std::max(max,lSum + rSum);
		
	}
	
	return max;
}

//this would work, but would exceed time limit
int maxSubArray(vector<int> nums, int k) 
{
	if(nums.size() < k)
		return 0;
	
	vector<vector<int> > dp(nums.size(), vector<int>(nums.size(),INT_MIN));
	
	for(int i = 0; i < nums.size(); i++)
	{
		for(int j = i; j < nums.size(); j++)
		{
			int max = maxSubArray(nums,i,j);
			dp[i][j] = max;
		}
	}
		
	int max = maxSubArrayHelper(nums,dp,0,k);
	return max;
}

int main()
{
	vector<int> nums = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,-2,1,-15,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
	int k = 20;
	cout << maxSubArray(nums,k) << endl;
}