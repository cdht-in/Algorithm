/*
	
Find K-th largest element in an array.

Have you met this question in a real interview? Yes
Example
In array [9,3,2,4,8], the 3rd largest element is 4.

In array [1,2,3,4,5], the 1st largest element is 5, 2nd largest element is 4, 3rd largest element is 3 and etc.

Note
You can swap elements in the array

Challenge
		
*/

#include "../commonHeader.h"

//O(n * k)
int kthLargestElement(int k, vector<int> nums) 
{
	int p = nums.size() - 1;
	for(int i = 0; i < k; i++)
	{
		int max = INT_MIN;
		int maxIndex = 0;
		for(int j = 0; j <= p; j++)
		{
			if(nums[j] > max)
			{
				max = nums[j];
				maxIndex = j;
			}
		}
		
		int tmp = nums[maxIndex];
		nums[maxIndex] = nums[p];
		nums[p] = tmp;
		p--;
	}
	
	return nums[p + 1];
}

int kthLargestElementHelper(int k, vector<int>& nums, int l, int r)
{
	if(l == r)
	{
		return nums[l];
	}
	
	int lPtr = l, rPtr = r, pivot = l, midPtr = l;
	while(midPtr <= rPtr)	
	{
		if(nums[lPtr] <= nums[pivot])
		{
			lPtr++;
			midPtr++;
		}
		else
		{
			int tmp = nums[rPtr];
			nums[rPtr] = nums[lPtr];
			nums[lPtr] = tmp;
			rPtr--;
		}
	}
	
	int tmp = nums[rPtr];
	nums[rPtr] = nums[pivot];
	nums[pivot] = tmp;
	
	int numberToRight = r - rPtr;
	//kth largest number to its right, there are k - 1 number
	if(numberToRight == k - 1)
	{
		return nums[rPtr];
	}
	else if(numberToRight < k - 1)
	{
		return kthLargestElementHelper(k - 1 - numberToRight, nums,l,rPtr - 1);
	}
	else
	{
		return kthLargestElementHelper(k, nums,rPtr + 1,r);
	}
}

int kthLargestElementI(int k, vector<int> nums)
{
	return kthLargestElementHelper(k,nums,0,nums.size() - 1);
}

int main()
{
	vector<int> vec = {9,3,4,8};
	int k = 3;
	cout << kthLargestElementI(k,vec) << endl;
}