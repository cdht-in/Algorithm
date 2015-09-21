/*

Medium Partition Array

25% Accepted
Given an array nums of integers and an int k, partition the array (i.e move the elements in "nums") such that:

All elements < k are moved to the left
All elements >= k are moved to the right
Return the partitioning index, i.e the first index i nums[i] >= k.

Have you met this question in a real interview? Yes
Example
If nums = [3,2,2,1] and k=2, a valid answer is 1.

Note
You should do really partition in array nums instead of just counting the numbers of integers smaller than k.

If all elements in nums are smaller than k, then return nums.length

Challenge
Can you partition the array in-place and in O(n)?

*/

#include "../commonHeader.h"

int partitionArray(vector<int> &nums, int k) 
{
	int l = 0, mid = 0, r = nums.size() - 1;
	while(mid <= r)
	{
		if(nums[l] < k) 
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
	
	return mid;
	
}

int main()
{
	
}