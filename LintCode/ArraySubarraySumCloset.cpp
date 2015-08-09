/*

Given an integer array, find a subarray with sum closest to zero. Return the indexes of the first number and last number.

Have you met this question in a real interview? Yes
Example
Given [-3, 1, 1, -3, 5], return [0, 2], [1, 3], [1, 1], [2, 2] or [0, 4]

Challenge
O(nlogn) time
	
*/

#include "../commonHeader.h"

//this wouldn't work
vector<int> subarraySumClosestHelper(vector<int> nums,int start, int end)
{
	if(start >= end)
	{
		vector<int> ret;
		ret.push_back(nums[start]);
		ret.push_back(start);
		ret.push_back(start);
		return ret;
	}
	
	int mid = start + (end - start) / 2;
	vector<int>	left = subarraySumClosestHelper(nums,0,mid);
	vector<int>	right = subarraySumClosestHelper(nums,mid + 1,end);
	
	//now the closest sum to 0 is the among the left, right and the one spanning over two
	
	int sum = std::min(std::abs(left[0]),std::abs(right[0]));
	sum = std::min(sum,std::abs(left[0] + right[0]));
	
	if(sum == left[0])
	{
		return left;
	}
	if(sum == right[0])
	{
		return right;
	}
	
	vector<int> ret;
	ret.push_back(sum);
	ret.push_back(left[1]);
	ret.push_back(right[2]);
	
	return ret;
}

vector<int> subarraySumClosest(vector<int> nums)
{
	vector<int> result = subarraySumClosestHelper(nums,0,nums.size() - 1);
	vector<int> interval;
	interval.push_back(result[1]);
	interval.push_back(result[2]);
	return interval;
}

vector<int> subarraySumClosestI(vector<int> nums)
{
	vector<int> ret;
	if(nums.size() == 0)
		return ret;
	if(nums.size() == 1)
	{
		ret.push_back(0);
		ret.push_back(0);
		return ret;
	}
	
	vector<pair<int,int> > subSum(nums.size(),make_pair(0,0));
	subSum[0] = make_pair(nums[0],0);
	//get the subSum from the beginning
	for(int i = 1; i < nums.size(); i++)
	{
		subSum[i] = make_pair(nums[i] + subSum[i - 1].first,i);
	}
	
	sort(subSum.begin(),subSum.end());
	
	//now the the difference between each sum is the sum of subarray between them
	int diff = INT_MAX;
	int index = 0;
	for(int i = 0; i < subSum.size() - 1; i++)
	{
		int subArraySum = subSum[i + 1].first - subSum[i].first;
		if(std::abs(subArraySum - 0) < diff)
		{
			diff = std::abs(subArraySum - 0);
			index = i;
		}
	}
	
	//note the subarray sum for [0,j] - [0,i] is [i + 1,j]
	int begin = std::min(subSum[index].second,subSum[index + 1].second) + 1;
	int end = std::max(subSum[index].second,subSum[index + 1].second);
	
	ret.push_back(begin);
	ret.push_back(end);
	return ret;
}

int main()
{
	
}