/*
	
	Given an array of integers and an integer k, return true if and only if there are two distinct indices i and j in the array such that nums[i] = nums[j] and the difference between i and j is at most k.
	
*/
#include <vector>
#include <unordered_map>

using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k) 
{
	if(nums.size() < 2)
		return false;
	
	unordered_map<int,vector<int> > map;
	
	for(int i = 0; i < nums.size(); i++)
	{
		if(map.find(nums[i]) == map.end())
		{
			map[nums[i]] = vector<int>();
		}
		
		if(map[nums[i]].size() == 0)
		{
			map[nums[i]].push_back(i);
			continue;
		}
			
		//more than 2 duplicates
		if(map[nums[i]].size() >= 2)
			return false;
		
		//size == 1
		if(i - map[nums[i]].back() > k)
			return false;
		
		map[nums[i]].push_back(i);
	}
	
	for(auto it = map.begin(); it != map.end(); it++)
	{
		if(it->second.size() == 2)
			return true;
	}
	
	return false;
}

int main()
{
	
	
}