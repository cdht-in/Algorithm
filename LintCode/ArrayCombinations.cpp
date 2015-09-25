/*

Medium Combinations

32% Accepted
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

Have you met this question in a real interview? Yes
Example
For example,
If n = 4 and k = 2, a solution is:
[[2,4],[3,4],[2,3],[1,2],[1,3],[1,4]]

*/

#include "../commonHeader.h"

//O(2^n) in time
vector<vector<int> > combine(int n, int k) 
{
	vector<vector<int> > ret;
	vector<vector<int> > sets;
	sets.push_back(vector<int>());
	
	for(int i = 1; i <= n; i++)
	{
		int size = sets.size();
		for(int j = 0; j < size; j++)
		{
			vector<int> set = sets[j];
			set.push_back(i);
			
			if(set.size() == k)
			{
				ret.push_back(set);
			}
			
			sets.push_back(set);
		}
	}
	return ret;
}

int main()
{
	
}