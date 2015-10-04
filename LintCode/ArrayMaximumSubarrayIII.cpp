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

int maxSubArray(vector<int>& nums, int l, int r)
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

//this would work, but would exceed time limit, DFS
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

//dp
int maxsubArrayI(vector<int> nums, int k)
{
	if(nums.size() < k)
		return 0;
		
	vector<vector<vector<int> > > dp(k + 1, vector<vector<int> >(nums.size(),vector<int>(nums.size(),0)));
	
	//allocating this 54 * 200 * 200 would overflow on the stack
	//int dp[k + 1][nums.size()][nums.size()];
	
	for(int a = 1; a <= k; a++)
	{
		for(int i = 0; i < nums.size(); i++)
		{
			for(int j = i; j < nums.size(); j++)
			{
				if(a == 1)
				{
					dp[a][i][j] = maxSubArray(nums,i,j);
				}
				else
				{
					dp[a][i][j] = INT_MIN;
				}
			}
		}
	}
	
	for(int a = 2; a <= k; a++)
	{
		for(int i = 0; i < nums.size(); i++)
		{
			for(int j = 0; j <= i; j++)
			{
				if(j == 0)
				{
					continue;
				}
				
				//max of k - 1 on [0,j - 1]
				int subMaxI = dp[a - 1][0][j - 1];
				
				//the largest sum of k subarray over [0,i]
				dp[a][0][i] = std::max(dp[a][0][i],subMaxI + dp[1][j][i]);
			}
		}
	}
	
	return dp[k][0][nums.size() - 1];
}

int main()
{
	vector<int> nums = {-68,64,-44,16,-85,6,-58,84,-5,72,-16,100,-88,14,-36,73,-96,42,-72,93,-15,53,-18,67,-71,25,-51,26,-37,16,-33,32,-11,89,-50,99,-41,80,-88,75,-42,7,-68,47,-35,25,-86,56,-44,36,-82,86,-5,59,-47,8,-1,34,-86,72,-6,25,-21,0,-23,45,-58,11,-4,3,-71,65,-50,61,-92,95,-4,99,-74,18,-76,97,0,23,-9,82,-66,93,-32,49,-50,54,-42,43,-14,71,-8,98,-70,9,-20,87,-60,7,-2,67,-44,58,-62,80,-83,7,-19,51,-35,95,-89,45,-34,37,-29,91,-14,0,-60,41,-24,93,-50,10,-2,11,-71,70,-86,75,-94,27,-72,74,-35,30,-6,4,-73,34,-31,14,-56,53,-79,84,-56,88,-10,87,-98,54,-73,50,-97,62,-38,20,-30,21,-60,94,-68,13,-29,34,-16,53,-55,35,-97,55,-10,73,-67,53,-98,31,-55,82,-25,47,-93,69,-43,77,-90,55,-88,94,-87,41,-70,8};
	int k = 54;
	cout << maxsubArrayI(nums,k) << endl;
}