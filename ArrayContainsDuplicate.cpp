/*
	
	Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

*/

#include <vector>
#include <unordered_set>

using namespace std;

bool containsDuplicate(vector<int>& nums) 
{
	unordered_set<int> set;
	for(int i = 0; i < nums.size(); i++)
	{
		if(set.find(nums[i]) == set.end())
		{
			set.insert(nums[i]);
		}
		else
			return true;
	}
	
	return false;
		
}

int main()
{
	
}