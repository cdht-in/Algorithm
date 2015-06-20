/*
	
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container.


*/

#include <vector>
#include <cmath>
#include <iostream>

using namespace std;


//NOTE that if height[left] < height[right], only moving the lower height to close up the gap between left and right could possibly result in a bigger area, because moving the higher height would either decrease the width or both the width and the height of the container, result in smaller area
int maxArea(vector<int> &height) {
	int res = 0, n = height.size();
	int left = 0, right = n-1;
	while(left < right)
	{
	    res = max(res, (right-left) * min(height[left], height[right]));
		
	    if(height[left] < height[right])
	        left++;
	    else
			right--;
	}
	return res;
}







































//second implementation
int maxAreaI(vector<int> &height) 
{
	if(height.size() <= 1)
		return 0;
	
	int l = 0;
	int r = height.size() - 1;
	int area = 0;
	
	while(l < r)
	{
		int capacity = 0;
		//it can only move the lower end to make a possible bigger container
		if(height[l] < height[r])
		{
			capacity = (r - l) * height[l];
			l++;
		}
		else
		{
			capacity = (r - l) * height[r];
			r--;
		}
		
		if(capacity > area)
		{
			area = capacity;
		}
	}
	
	return area;
}





int main()
{
	int foo[] = {9,6,14,11,2,2,4,9,3,8};
	int n = sizeof(foo) / sizeof(int);
	vector<int> height(foo, foo + n);
	
	cout << maxAreaI(height) << endl;
	
}