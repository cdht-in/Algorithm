/*
	
Medium Container With Most Water

40% Accepted
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Have you met this question in a real interview? Yes
Example
Given [1,3,2], the max area of the container is 2.

Note
You may not slant the container.
	
*/

#include "../commonHeader.h"

int maxArea(vector<int> &heights) 
{
	if(heights.size() <= 1)
		return 0;
	
	int l = 0, r = heights.size() - 1;
	int max = 0;
	while(l < r)
	{
		if(heights[l] <= heights[r])
		{
			max = std::max(max,(r - l) * heights[l++]);
		}
		else
		{
			max = std::max(max,(r - l) * heights[r--]);
		}
	}
	return max;
}

int main()
{
	vector<int> heights = {1,1};
	cout << maxArea(heights) << endl;
}