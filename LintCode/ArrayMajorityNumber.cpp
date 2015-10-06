/*
	
Easy Majority Number

40% Accepted
Given an array of integers, the majority number is the number that occurs more than half of the size of the array. Find it.

Have you met this question in a real interview? Yes
Example
Given [1, 1, 1, 1, 2, 2, 2], return 1

Challenge
O(n) time and O(1) extra space


*/

#include "../commonHeader.h"

//http://www.cnblogs.com/yuzhangcmu/p/4175046.html
int majorityNumber(vector<int> nums) 
{
	if(nums.size() == 1)
	{
		return nums[0];
	}
	
	int majorIndex = 0;
	int c = 1;
	
	for(int i = 1; i < nums.size(); i++)
	{
		if(nums[i] == nums[majorIndex])
		{
			c++;
		}
		else
		{
			c--;
			if(c == 0)
			{
				majorIndex = i;
				c = 1;
			}
		}
	}
	
	c = 0;
	for(int i = 0; i < nums.size(); i++)
	{
		if(nums[i] == nums[majorIndex])
		{
			c++;
		}
	}
	
	return (c > nums.size() / 2)? nums[majorIndex] : -1;
}

int main()
{
	
}