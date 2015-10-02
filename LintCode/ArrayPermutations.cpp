/*
	
Given a list of numbers, return all possible permutations.

Have you met this question in a real interview? Yes
Example
For nums = [1,2,3], the permutations are:

[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
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
		Swap(nums,index,i);
		permuteHelper(nums,index + 1, ret);
		Swap(nums,index,i);
	}
}

vector<vector<int> > permute(vector<int> nums) 
{
	vector<vector<int> > ret;
	if(nums.size() == 0)
		return ret;
	
	permuteHelper(nums,0,ret);
	return ret;
}

int main()
{
	
}