/*
	
Given a list of numbers that may has duplicate numbers, return all possible subsets

Have you met this question in a real interview? Yes
Example
If S = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
Note
Each element in a subset must be in non-descending order.

The ordering between two subsets is free.

The solution set must not contain duplicate subsets.
	
*/

#include "../commonHeader.h"

vector<vector<int> > subsetsWithDup(vector<int> &nums) 
{
	sort(nums.begin(),nums.end());
	vector<vector<int> > ret;
	ret.push_back(vector<int>());
	
	for(int i = 0; i < nums.size(); i++)
	{	
		//find the len of duplicates
		int k = i;
		while(k + 1 < nums.size() && nums[k] == nums[k + 1])
		{
			k++;
		}
		int len = k - i + 1;
		
		int n = ret.size();
		//add the power set of the duplicates to the existing set to avoid duplicates further
		for(int j = 0; j < n; j++)
		{	
			for(int c = 1; c <= len; c++)
			{
				vector<int>	set = ret[j];
				for(int a = 0; a < c; a++)
				{
					set.push_back(nums[i]);
				}
				ret.push_back(set);
			}
		}
		
		//skip the entire portion of the duplicates
		i = k;
	}
	
	return ret;
}

int main()
{
	vector<int> vec = {1,4,4,4,4};
	vector<vector<int> > ret = subsetsWithDup(vec);
	for(auto i : ret)
	{
		for(auto j : i)
		{
			cout << j << " ";
		}
		cout << endl;
	}
}