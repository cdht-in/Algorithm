/*
	
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

The array may contain duplicates.

Have you met this question in a real interview? Yes
Example
Given [4,4,5,6,7,0,1,2] return 0
	
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
		
		if(mid >= 1 && num[mid - 1] > num[mid])
		{
			return num[mid];
		}	
		
		int i = mid;
		while(i < num.size() && num[mid] == num[i])
		{
			i++;
		}
		
		if(i < num.size() && num[i] >= num[num.size() - 1])
		{
			l = mid + 1;
		}
		else
		{
			r = mid - 1;
		}
	}
	
	//sorted array
	return num[l];
}

int main()
{
	vector<int> vec = {1,1,-1,1};
	cout << findMin(vec) << endl;
	
}