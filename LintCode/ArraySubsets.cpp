/*
	
Medium Subsets

22% Accepted
Given a set of distinct integers, return all possible subsets.

Have you met this question in a real interview? Yes
Example
If S = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
Note
Elements in a subset must be in non-descending order.

The solution set must not contain duplicate subsets.

*/

#include "../commonHeader.h"

vector<vector<int> > subsets(vector<int> &nums) 
{
	vector<vector<int> > ret;
	ret.push_back(vector<int>());
	
	for(int i = 0; i < nums.size(); i++)
	{
		int n = ret.size();
		for(int j = 0; j < n; j++)
		{
			vector<int> set = ret[j];
			set.push_back(nums[i]);
			ret.push_back(set);
		}
	}
	
	return ret;
}

int main()
{
	
}

