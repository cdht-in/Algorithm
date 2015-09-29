/*
	
Given a sequence of integers, find the longest increasing subsequence (LIS).

You code should return the length of the LIS.

Have you met this question in a real interview? Yes
Example
For [5, 4, 1, 2, 3], the LIS  is [1, 2, 3], return 3

For [4, 2, 4, 5, 3, 7], the LIS is [4, 4, 5, 7], return 4

Challenge
Time complexity O(n^2) or O(nlogn)

Clarification
What's the definition of longest increasing subsequence?

    * The longest increasing subsequence problem is to find a subsequence of a given sequence in which the subsequence's elements are in sorted order, lowest to highest, and in which the subsequence is as long as possible. This subsequence is not necessarily contiguous, or unique.  

    * https://en.wikipedia.org/wiki/Longest_common_subsequence_problem
	
*/

#include "../commonHeader.h"

int longestIncreasingSubsequence(vector<int> nums) 
{	
	vector<int> dp(nums.size() + 1,1);
	dp[0] = 0;
	int max = 0;
	//i indicates the longest increasing sequence stops at i
	for(int i = 1; i <= nums.size(); i++)
	{
		for(int j = 1; j < i; j++)
		{
			if(nums[j - 1] <= nums[i - 1])
			{
				dp[i] = std::max(dp[i],dp[j] + 1);
			}
		}
		max = std::max(max,dp[i]);
	}	
	return max;
}

int main()
{
	vector<int> vec = {9,3,6,2,7};
	cout << longestIncreasingSubsequence(vec) << endl;
}