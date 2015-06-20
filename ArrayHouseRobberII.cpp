/*
	
Note: This is an extension of House Robber.

After robbing those houses on that street, the thief has found himself a new place for his thievery so that he will not get too much attention. This time, all houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, the security system for these houses remain the same as for those in the previous street.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

Credits:
Special thanks to @Freezen for adding this problem and creating all test cases.
	
*/

#include <vector>

using namespace std;

int rob(vector<int>& nums) 
{
	int n = nums.size();
	
	if(n == 0)
		return 0;
	if(n == 1)
		return nums[0];
	
	//case 1: rob nums[0]
	int pre = 0;
	int max1 = 0;
	for(int i = 0; i < nums.size() - 1; i++)
	{
		int tmp = pre;
		pre = max1;
		max1 = std::max(nums[i] + tmp,pre);
	}
	
	//case 2, not rob nums[0]
	pre = 0;
	int max2 = 0;
	for(int i = 1; i < nums.size(); i++)
	{
		int tmp = pre;
		pre = max2;
		max2 = std::max(nums[i] + tmp,pre);
	}
	
	return std::max(max1,max2);
	
}

int main()
{
	
	
}