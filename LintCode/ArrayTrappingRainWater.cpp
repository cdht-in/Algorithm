/*
	
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

Trapping Rain Water

Have you met this question in a real interview? Yes
Example
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

Challenge
O(n) time and O(1) memory

O(n) time and O(n) memory is also acceptable.

*/

#include "../commonHeader.h"

int trapRainWater(vector<int> &heights) 
{
	if(heights.size() <= 2)
		return 0;
	
	int lHeight = 0;
	int sum = 0;
	int tmpSum = 0;
	int width = 1;
	for(int i = 0; i < heights.size(); i++)
	{
		if(heights[i] < lHeight)
		{
			tmpSum += (lHeight - heights[i]) * width;
		}
		else
		{
			sum += tmpSum;
			tmpSum = 0;
			lHeight = heights[i];
		}
	}
	
	int rHeight = 0;
	tmpSum = 0;
	for(int i = heights.size() - 1; i >= 0; i--)
	{
		//NOTE here for case like [100,0,100], the container could be counted twice
		// <= here awoids this situation
		if(heights[i] <= rHeight)
		{
			tmpSum += (rHeight - heights[i]) * width;
		}
		else
		{
			sum += tmpSum;
			tmpSum = 0;
			rHeight = heights[i];
		}
	}
	
	return sum;
}

int main()
{
	vector<int> foo = {100,0,100};
	
	cout << trapRainWater(foo) << endl;
}