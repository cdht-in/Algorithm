/*
	
Medium Maximum Product Subarray

28% Accepted
Find the contiguous subarray within an array (containing at least one number) which has the largest product.

Have you met this question in a real interview? Yes
Example
For example, given the array [2,3,-2,4], the contiguous subarray [2,3] has the largest product = 6.
	
*/

#include "../commonHeader.h"

int maxProduct(vector<int>& nums) 
{
	if(nums.size() == 1)
		return nums[0];
	
	int globalMax = nums[0],localMax = nums[0],localMin = nums[0];
	
	for(int i = 1; i < nums.size(); i++)
	{
		int tmp = localMax;
		localMax = std::max(std::max(nums[i] * localMax, nums[i]),nums[i] * localMin);
		localMin = std::min(std::min(nums[i] * tmp,nums[i]),nums[i] * localMin);
		globalMax = std::max(globalMax,localMax);
	}

	return globalMax;
}

int main()
{
	vector<int> vec = {-3,0,1,-2};
	cout << maxProduct(vec) << endl;
}