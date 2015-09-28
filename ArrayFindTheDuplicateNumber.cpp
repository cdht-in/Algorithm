/*
	
Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate element must exist. Assume that there is only one duplicate number, find the duplicate one.

Note:
You must not modify the array (assume the array is read only).
You must use only constant extra space.
Your runtime complexity should be less than O(n2).
Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
	
*/

#include "./commonHeader.h"

int findDuplicate(vector<int>& nums) 
{
	sort(nums.begin(),nums.end());
	int duplicate = -1;
	for(int i = 0; i < nums.size(); i++)
	{
		//the logic is if there is only one duplicate, after sorting positions nums[i] - 1 and nums[i] should both be the same number
		if(i > nums[i] - 1)
		{
			duplicate = nums[i];
			break;
		}
	}
	return duplicate;
}

int main()
{
	
}