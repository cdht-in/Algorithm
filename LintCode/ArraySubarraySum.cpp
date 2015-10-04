/*
	
Easy Subarray Sum

25% Accepted
Given an integer array, find a subarray where the sum of numbers is zero. Your code should return the index of the first number and the index of the last number.

Have you met this question in a real interview? Yes
Example
Given [-3, 1, 2, -3, 4], return [0, 2] or [1, 3].

Note
There is at least one subarray that it's sum equals to zero.
	
*/

#include "../commonHeader.h"

//O(n^2) in time and O(n) in space
vector<int> subarraySum(vector<int> nums)
{
	vector<int> subSum(nums.size(),0);
	int sum = 0;
	for(int i = 0; i < nums.size(); i++)
	{
		sum += nums[i];
		subSum[i] = sum;
	}
	
	for(int i = 0; i < nums.size(); i++)
	{
		for(int j = i; j < nums.size(); j++)
		{
			int lSum = 0;
			int rSum = subSum[j];
			
			if(i != 0)
			{
				lSum = subSum[i - 1];
			}
			
			if(rSum - lSum == 0)
			{
				if(i == 0)
					return vector<int>({0,j});
				return vector<int>({i,j});
			}
		}
	}
	
	return vector<int>({-1,-1});
}

int main()
{
	vector<int> vec = {0};
	vector<int> ret = subarraySum(vec);
	for(auto i : ret)
	{
		cout << i << " ";
	}
	cout << endl;
}