/*
	
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

Have you met this question in a real interview? Yes
Example
Given [3, 8, 4], return 8.

Challenge
O(n) time and O(1) memory.
	
*/

#include "../commonHeader.h"

long long houseRobber(vector<int> A) 
{
	if(A.size() < 1)
		return 0;
	if(A.size() == 1)
		return A[0];
	
	long long dp[3];
	dp[0] = A[0];
	dp[1] = std::max(A[0],A[1]);
	for(int i = 2; i < A.size(); i++)
	{
		dp[i % 3] = std::max(dp[(i - 1) % 3], A[i] + dp[(i - 2) % 3]);
	}
	return dp[(A.size() - 1) % 3];
}

int main()
{
	
}