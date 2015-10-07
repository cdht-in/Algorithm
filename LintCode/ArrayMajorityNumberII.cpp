/*
	
Given an array of integers, the majority number is the number that occurs more than 1/3 of the size of the array.

Find it.

Have you met this question in a real interview? Yes
Example
Given [1, 2, 1, 2, 1, 3, 3], return 1.

Note
There is only one majority number in the array.

Challenge
O(n) time and O(1) extra space.
	
*/

#include "../commonHeader.h"

int majorityNumber(vector<int> nums) 
{
	if(nums.size() == 1 || nums.size() == 2)
		return nums[0];
	
	int n1 = nums[0];
	int n2 = INT_MIN;
	int c1 = 1;
	int c2 = 0;
	for(int i = 1; i < nums.size(); i++)
	{
		if(nums[i] == n1)
		{
			c1++;
			continue;
		}
		
		if(n2 == INT_MIN)
		{
			n2 = nums[i];
			c2 = 1;
			continue;
		}
		
		if(n2 == nums[i])
		{
			c2++;
			continue;
		}
		
		c1--;
		c2--;
		
		if(c1 == 0)
		{
			n1 = nums[i];
			c1 = 1;
		}
		if(c2 == 0)
		{
			n2 = nums[i];
			c2 = 1;
		}
	}
	
	c1 = 0;
	c2 = 0;
	for(int i = 0; i < nums.size(); i++)
	{
		if(nums[i] == n1)
		{
			c1++;
		}
		else if(nums[i] == n2)
		{
			c2++;
		}
	}
	
	//assume there is one majority number
	return (c1 > nums.size() / 3)? n1 : n2;
}

int main()
{
	vector<int> vec = {1,1,1,2,2,3};
	cout << majorityNumber(vec) << endl;
}