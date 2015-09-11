/*
	
Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

Return 0 if the array contains less than 2 elements.

Have you met this question in a real interview? Yes
Example
Given [1, 9, 2, 5], the sorted form of it is [1, 2, 5, 9], the maximum gap is between 5 and 9 = 4.

Note
You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.

Challenge
Sort is easy but will cost O(nlogn) time. Try to solve it in linear time and space.
	
*/

#include "../commonHeader.h"

int maximumGap(vector<int> nums) 
{
	int maxGap = 0;
	if(nums.size() < 2)
		return maxGap;
	
	int max = 0;
	for(int i = 0; i < nums.size(); i++)
	{
		max = std::max(max,nums[i]);
	}
	
	//bucket that keeps min and max for each buccket
	vector<vector<int> > buckets(nums.size(),vector<int>());
	for(auto i : nums)
	{
		int index = (i / max) * (nums.size() - 1);
		buckets[index].push_back(i);
	}
	
	for(int i = 0; i < buckets.size(); i++)
	{
		sort(buckets[i].begin(),buckets[i].end());
	}
	
	int prevMax = -1;
	for(int i = 0; i < buckets.size(); i++)
	{
		if(buckets[i].empty())
			continue;
		
		for(int j = 0; j < buckets[i].size() - 1; j++)
		{
			//max gap within a bucket
			maxGap = std::max(maxGap,buckets[i][j + 1] - buckets[i][j]);
		}
				
		//between buckets
		
		if(prevMax != -1)
		{
			maxGap = std::max(maxGap,buckets[i][0] - prevMax);
		}
		
		prevMax = buckets[i][buckets[i].size() - 1];
	}
	
	return maxGap;
	
}

int main()
{
	vector<int> vec = {999,999,999,999,999,999,999,999,999,999};
	cout << maximumGap(vec) << endl;
}