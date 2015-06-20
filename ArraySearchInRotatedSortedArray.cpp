/*
	
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

*/
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int biSearch(int A[], int l, int r, int target)
{
	int mid = 0;
	while(l <= r)
	{
		mid = (l + r) / 2;
		if(A[mid] == target)
		{
			return mid;
		}
		else if(A[mid] < target)
		{
			l = mid + 1;
		}
		else
		{
			r = mid - 1;
		}
	}
	return -1;
}

int searchHelper(int A[], int n,int l, int r, int target)
{
	if(l > r)
		return -1;
	
	int mid = 0;
	mid = (l + r) / 2;
	//cout << "search in " << A[l] << " " << A[r] << " mid is " << A[mid]  << " target is " << target << endl;
	
	if(A[mid] == target)
	{
		return mid;
	}
	
	int result = -1;
	
	int lValue = INT_MIN;
	//left side is sorted
	if(mid - 1 >= l)
	{
		lValue = A[mid - 1];
	}
	
	if(A[mid] > lValue)
	{
		result = biSearch(A,l,mid - 1,target);
		if(result != -1)
			return result;
		result = searchHelper(A,n,mid + 1,r,target);
		if(result != -1)
			return result;
	}
	
	int rValue = INT_MAX;
	if(mid + 1 <= r)
	{
		rValue = A[mid + 1];
	}
	
	//right side is sorted
	if(A[mid] < rValue)
	{
		result = biSearch(A,mid + 1,r,target);
		if(result != -1)
			return result;
	 	result = searchHelper(A,n,l,mid - 1,target);
	}
	
	return result;
}

int search(int A[], int n, int target) {
	
	if(n == 0)
		return -1;
	return searchHelper(A,n,0,n - 1, target);
}



int biSearch(vector<int>& nums, int l, int r, int target)
{
	int mid = 0;
	while(l <= r)
	{
		mid = (l + r) / 2;
		if(nums[mid] == target)
		{
			return mid;
		}
		else if(nums[mid] < target)
		{
			l = mid + 1;
		}
		else
		{
			r = mid - 1;
		}
	}
	
	return -1;
}

//not good implementation
int findTarget(vector<int>& nums,int target) 
{
	int mid = 0;
	int l = 0;
	int r = nums.size() - 1;
	int pos = -1;
	while(l <= r)
	{
		mid = (l + r) / 2;
		//right side is sorted
		if(nums[mid] <= nums[r])
		{
			pos = biSearch(nums,mid,r,target);
			if(pos != -1)
				return pos;
			r = mid - 1;
		}
		//left side is sorted
		else
		{
			pos = biSearch(nums,l,mid - 1,target);
			if(pos != -1)
				return pos;
			l = mid + 1;
		}
	}
	return pos;	
}

//O(logn)
int findTargetI(vector<int>& nums,int target) 
{
	int l = 0;
	int r = nums.size() - 1;
	while(l <= r)
	{
		int mid = l + (r - l) / 2;
		if(nums[mid] == target) 
			return mid;
		//left side is sorted
		if(nums[mid] >= nums[l])
		{
		    if(target < nums[mid] && target >= nums[l])
		        r = mid - 1;
		    else
		        l = mid + 1;
		}
		//right side is sorted
		else 
		{
		    if(target > nums[mid] && target < nums[l])
		        l = mid + 1;
		    else
		        r = mid - 1;
		}
	}
	return -1;
}


//second implementation, O(logn)
int findMin(vector<int>& nums) 
{
	int mid = 0;
	int l = 0;
	int r = nums.size() - 1;
	int min = INT_MAX;
	while(l <= r)
	{
		mid = (l + r) / 2;
		//right side is sorted
		if(nums[mid] <= nums[r])
		{
			min = (min < nums[mid]) ? min : nums[mid];
			r = mid - 1;
		}
		//left side is sorted
		else
		{
			min = (min < nums[l]) ? min : nums[l];
			l = mid + 1;
		}
	}
	
	return min;	
}



int main()
{
	int foo[] = {5,6,1,2,3,4};
	int n = sizeof(foo) / sizeof(int);
	int target = 1;
	//cout << search(foo,n,target) << endl;
	
	vector<int> bar = {5,6,1,2,3,4};
	
	cout << findTargetI(bar,5) << endl;
	//cout << findMin(bar) << endl;
	
}