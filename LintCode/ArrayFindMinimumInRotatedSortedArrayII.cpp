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
	int l = 0, r = num.size() - 1, mid = 0;
	//0, 10, 10
	//10,0,10
	while(l < r)
	{
		mid = l + (r - l) / 2;
		//this mean the left part is unsorted
		if(num[mid] > num[r])
		{
			l = mid + 1;
		}
		//note here if is set to be mid - 1, it could filter out the solution for case like //10,0,10
		else if(num[mid] < num[r])s
		{
			r = mid;
		}
		else
		{
			r--;
		}
	}
	
	return num[l];
}



int main()
{
	//0, 10, 10, l <= mid <= r, r = mid - 1;
	//0,0,0 r == 0
	//1,2,3, r = mid - 1;
	
	//1,1,0,1,1 r = mid - 1 => l
	//1,1,1,1
	
	vector<int> vec = {0,10,10};
	cout << findMin(vec) << endl;
	
}