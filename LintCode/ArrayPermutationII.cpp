/*
	
Medium Permutations II

22% Accepted
Given a list of numbers with duplicate number in it. Find all unique permutations.

Have you met this question in a real interview? Yes
Example
For numbers [1,2,2] the unique permutations are:

[

    [1,2,2],

    [2,1,2],

    [2,2,1]

]

Challenge
Do it without recursion.
	
*/

#include "../commonHeader.h"

void Swap(vector<int>& vec, int a, int b)
{
	int tmp = vec[a];
	vec[a] = vec[b];
	vec[b] = tmp;
}

void permuteHelper(vector<int>& nums, int index,vector<vector<int> >& ret)
{
	if(index >= nums.size())
	{
		ret.push_back(nums);
	}
	
	for(int i = index; i < nums.size(); i++)
	{
		//need to skip those out of ordered duplicates too
		if(i != index && nums[i] == nums[index])
		{
			continue;
		}
		
		Swap(nums,index,i);
		permuteHelper(nums,index + 1, ret);
		Swap(nums,index,i);
		
		//this only wouldn't work because during the recurision, the array is no longer sorted, thus can't skip duplicates like this anymore
		while(i + 1 < nums.size() && nums[i] == nums[i + 1])
		{
			i++;
		}
	}
	
}


vector<vector<int> > permuteUnique(vector<int> &nums) 
{
	vector<vector<int> > ret;
	if(nums.size() == 0)
		return ret;
	
	sort(nums.begin(),nums.end());
	permuteHelper(nums,0,ret);
	return ret;
}

int main()
{
	vector<int> vec = {1,2,2};
	vector<vector<int> > ret = permuteUnique(vec);
	for(auto i : ret)
	{
		for(auto j : i)
		{
			cout << j << " ";
		}
		cout << endl;
	}
		
		
		
}