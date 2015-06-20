/*
	
Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

Ensure that numbers within the set are sorted in ascending order.


Example 1:

Input: k = 3, n = 7

Output:

[[1,2,4]]

Example 2:

Input: k = 3, n = 9

Output:

[[1,2,6], [1,3,5], [2,3,4]]
	
*/

#include <vector>

using namespace std;

vector<vector<int> > combinationSum3(int k, int n) 
{
	vector<vector<int> > result;
	result.push_back(vector<int>());
	vector<vector<int> > kSet;	
	for(int i = 1; i <= 9; i++)
	{
			int size = result.size();
			for(int j = 0; j < size; j++)
			{
				vector<int> newSubSet(result[j]);
				newSubSet.push_back(i);
			
				result.push_back(newSubSet);
			
				//get a subset of the power set, 2^n
				if(newSubSet.size() == k)
					kSet.push_back(newSubSet);
			
			}
	}
	
	vector<vector<int> > ret;
	for(int i = 0; i < kSet.size(); i++)
	{
		int sum = 0;
		for(int j = 0; j < kSet[i].size(); j++)
		{
			sum += kSet[i][j];
		}
		
		if(sum == n)
			ret.push_back(kSet[i]);
	}
	
	return ret;
		
}

int main()
{
	
	
}