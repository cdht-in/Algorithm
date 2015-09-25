/*
	
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

Have you met this question in a real interview? Yes
Example
Given [4, 5, 6, 7, 0, 1, 2] return 0

Note
You may assume no duplicate exists in the array.

*/

#include "../commonHeader.h"

int findMin(vector<int> &num) 
{
	if(num.size() == 1)
		return num[0];
	
	int l = 0, r = num.size() - 1, mid = 0;
	while(l <= r)
	{
		mid = l + (r - l) / 2;
		
		if(mid >= 1 && num[mid - 1] >= num[mid])
		{
			return num[mid];
		}
		
		if(num[mid] >= num[num.size() - 1])
		{
			l = mid + 1;
		}
		else
		{
			r = mid - 1;
		}
	}
	
	//sorted array
	return num[0];
}

int main()
{
	
}