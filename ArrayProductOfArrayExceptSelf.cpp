/*
	
Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6].

Follow up:
Could you solve it with constant space complexity? (Note: The output array does not count as extra space for the purpose of space complexity analysis.)
	
*/
#include <vector>

using namespace std;

//O(n) time and space
vector<int> productExceptSelf(vector<int>& nums) 
{
	int n = nums.size();
	vector<int> ret(n,0);
	vector<int> lDp(n,1);
	vector<int> rDp(n,1);
	
	for(int i = 1; i < n; i++)
	{
		lDp[i] = nums[i - 1] * lDp[i - 1];
	}
	
	for(int i = n - 2; i >= 0; i--)
	{
		rDp[i] = nums[i + 1] * rDp[i + 1];
	}
	
	for(int i = 0; i < n; i++)
	{
		ret[i] = lDp[i] * rDp[i];
	}
	
	return ret;
}

vector<int> productExceptSelfI(vector<int>& nums)
{
	int n = nums.size();
	vector<int> ret(n,1);
	
	for(int i = 1; i < n; i++)
	{
		ret[i] = nums[i - 1] * ret[i - 1];
	}
	
	int r = 1;
	for(int i = n - 1; i >= 0; i--)
	{
		ret[i] *= r;
		r *= nums[i];
	}
		
	return ret;
}



int main()
{
	
}