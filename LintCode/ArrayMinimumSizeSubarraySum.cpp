/*
	
Medium Minimum Size Subarray Sum

Given an array of n positive integers and a positive integer s, find the minimal length of a subarray of which the sum ≥ s. If there isn't one, return -1 instead.

Have you met this question in a real interview? Yes
Example
Given the array [2,3,1,2,4,3] and s = 7, the subarray [4,3] has the minimal length under the problem constraint.

Challenge
If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n).
	
*/

#include "../commonHeader.h"

//O(n)
int minimumSize(vector<int> &nums, int s) 
{
	if(nums.size() == 0)
		return -1;
	if(nums.size() == 1)
		return (nums[0] >= s)? 1 : -1;
	
	int l = 0, r = 1;
	int sum = nums[0];
	int len = INT_MAX;
	while(r < nums.size())
	{
		sum += nums[r];
		if(sum < s)
		{
			r++;
			continue;
		}
		
		while(l < r)
		{
			if(sum - nums[l] >= s)
			{
				sum -= nums[l];
				l++;
			}
			else
				break;
		}
		
		len = (len < r - l + 1)? len : r - l + 1;
		r++;
	}
	
	if(len == INT_MAX)
	{
		return -1;
	}
	return len;
}

int main()
{
	
}