/*
	
Given an array with integers.

Find two non-overlapping subarrays A and B, which |SUM(A) - SUM(B)| is the largest.

Return the largest difference.

Have you met this question in a real interview? Yes
Example
For [1, 2, -3, 1], return 6

Note
The subarray should contain at least one number

Challenge
O(n) time and O(n) space.
	
*/

#include "../commonHeader.h"

int maxDiffSubArrays(vector<int> nums) 
{
	vector<int> leftMax(nums.size(),0);
	vector<int> leftMin(nums.size(),0);
	vector<int> rightMax(nums.size(),0);
	vector<int> rightMin(nums.size(),0);
	
	int subsumMax = 0;
	int subsumMin = 0;
	int max = INT_MIN;
	int min = INT_MAX;
	for(int i = 0; i < nums.size(); i++)
	{
		if(i == 0)
		{
			subsumMax = nums[i];
			leftMax[i] = subsumMax;
			subsumMin = nums[i];
			leftMin[i] = subsumMin;
			continue;
		}
		
		if(nums[i] + subsumMax <= nums[i])
		{
			subsumMax = nums[i];
		}
		else
		{
			subsumMax += nums[i];
		}
		
		if(nums[i] + subsumMin >= nums[i])
		{
			subsumMin = nums[i];
		}
		else
		{
			subsumMin += nums[i];
		}
				
		max = std::max(max,subsumMax);
		min = std::min(min,subsumMin);
		
		leftMax[i] = max;
		leftMin[i] = min;
	}
	
	subsumMax = 0;
	subsumMin = 0;
	max = INT_MIN;
	min = INT_MAX;
	int maxDiff = INT_MIN;
	
	for(int i = nums.size() - 1; i >= 0; i--)
	{
		if(i == nums.size() - 1)
		{
			subsumMax = nums[i];
			rightMax[i] = subsumMax;
			subsumMin = nums[i];
			rightMin[i] = subsumMin;
		}
		else
		{
			if(nums[i] + subsumMax <= nums[i])
			{
				subsumMax = nums[i];
			}
			else
			{
				subsumMax += nums[i];
			}
		
			if(nums[i] + subsumMin >= nums[i])
			{
				subsumMin = nums[i];
			}
			else
			{
				subsumMin += nums[i];
			}
		
			max = std::max(max,subsumMax);
			min = std::min(min,subsumMin);
		
			rightMax[i] = max;
			rightMin[i] = min;
		}
		
		if(i < nums.size() - 1)
		{
			maxDiff = std::max(maxDiff,std::abs(leftMax[i] - rightMin[i + 1]));
			maxDiff = std::max(maxDiff,std::abs(leftMin[i] - rightMax[i + 1]));	
		}
	}
	
	return maxDiff;
}

int main()
{
	vector<int> vec = {101,33,44,-55,-67,-78,101,33,43};
	cout << maxDiffSubArrays(vec) << endl;
}