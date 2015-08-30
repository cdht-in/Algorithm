/*
	
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

For example,
Given nums = [0, 1, 3] return 2.

Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
	
*/

#include "./commonHeader.h"

int missingNumber(vector<int>& nums) 
{
	int sum1 = 0;
	int sum2 = 0;
	for(int i = 0; i < nums.size(); i++)
	{
		sum1 += nums[i];
		sum2 += i + 1;
	}
	
	return sum2 - sum1;
}

int main()
{
	
}