/*
	
	Given an array of integers, find out whether there are two distinct indices i and j in the array such that the difference between nums[i] and nums[j] is at most t and the difference between i and j is at most k.
	
*/

#include <vector>
#include <unordered_set>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

bool myfunction (pair<int,int>& i,pair<int,int>& j) 
{ 
	return (i.first < j.first); 
}

//naive O^2, this would exceed leetcode time limit
bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) 
{
	for(int i = 0; i < nums.size(); i++)
	{
		for(int j = i + 1; j < nums.size(); j++)
		{
			if(std::abs(nums[j] - nums[i]) <= t && j - i <= k)
			{
				return true;
			}
		}
	}
	
	return false;
}

//O(nlogn) in time, take advantage of binary range selection ability
bool containsNearbyAlmostDuplicateI(vector<int>& nums, int k, int t) 
{
	map<long long,int> M;
	int l = 0;
	for (int r = 0; r < nums.size(); r++) 
	{
		//maintain the r - l <= k window
	    if (r - l > k && M[nums[l]] == l)
	        M.erase(nums[l++]);
		
		//nums[r] - nums[l] <= t => *it = nums[l] <= 
	    auto it = M.lower_bound(nums[r] - t);
		
	    if (it != M.end() && std::abs(it->first - nums[r]) <= t)
	        return true;
		
	    M[nums[r]] = r;
	}
	
	return false;
}

int main()
{
	vector<int> nums = {1,3,6,2};
	int k = 1;
	int t = 2;
	
	cout << containsNearbyAlmostDuplicate(nums,k,t) << endl;
}