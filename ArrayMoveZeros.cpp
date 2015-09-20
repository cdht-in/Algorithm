/*
	
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.
Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
	
*/

#include "./commonHeader.h"

//this is not stable
void moveZeroes(vector<int>& nums) 
{
	int l = 0, mid = 0, r = nums.size() - 1;
	while(mid <= r)
	{
		if(nums[l] != 0)
		{
			l++;
			mid++;
		}
		else
		{
			int tmp = nums[l];
			nums[l] = nums[r];
			nums[r] = tmp;
			r--;
		}
	}
}

void moveZeroesI(vector<int>& nums)
{
	int p = 0;
	for(int i = 0; i < nums.size(); i++)
	{
		if(nums[i] != 0)
		{
			nums[p++] = nums[i];
		}
	}
	
	for(int i = p; i < nums.size(); i++)
	{
		nums[i] = 0;
	}
}

int main()
{
	vector<int> vec = {0, 1, 0, 3, 12};
	moveZeroesI(vec);
	for(auto i : vec)
	{
		cout << i << " ";
	}
	cout << endl;
}