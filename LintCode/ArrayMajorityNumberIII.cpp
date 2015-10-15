/*
	
Given an array of integers and a number k, the majority number is the number that occurs more than 1/k of the size of the array.

Find it.

Have you met this question in a real interview? Yes
Example
Given [3,1,2,3,2,3,3,4,4,4] and k=3, return 3.

Note
There is only one majority number in the array.

Challenge
O(n) time and O(k) extra space
	
*/

#include "../commonHeader.h"

int majorityNumber(vector<int> nums, int k) 
{	
	unordered_map<int,int> candidates;
	
	//{3,1,2,3,2,3,3,4,4,4};
	for(int i = 0; i < nums.size(); i++)
	{
		if(candidates.size() < k - 1)
		{
			candidates[nums[i]]++;
		}
		else if(candidates.size() == k - 1)
		{
			if(candidates.find(nums[i]) == candidates.end())
			{
				for(auto& it : candidates)
				{
					it.second--;
					if(it.second == 0)
					{
						candidates.erase(it.first);
					}
				}
			}
			
			if(candidates.size() < k - 1)
			{
				candidates[nums[i]] = 1;
			}
		}
	}
	
	for(auto& it : candidates)
	{
		it.second = 0;
		
		for(int j = 0; j < nums.size(); j++)
		{
			if(nums[j] == it.first)
			{
				it.second++;
			}
		}
	}
	
	for(auto& it : candidates)
	{
		if(it.second > nums.size() / k)
		{
			return it.first;
		}
	}
	
	//assume there is one majority number, shouldn't reach here
	return -1;
}

int main()
{
	vector<int> vec = {3,1,2,3,2,3,3,4,4,4};
	int k = 3;
	cout << majorityNumber(vec,k) << endl;
}