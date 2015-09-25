/*
	
Medium Find Peak Element

44% Accepted
There is an integer array which has the following features:

The numbers in adjacent positions are different.
A[0] < A[1] && A[A.length - 2] > A[A.length - 1].
We define a position P is a peek if:

A[P] > A[P-1] && A[P] > A[P+1]
Find a peak element in this array. Return the index of the peak.

Have you met this question in a real interview? Yes
Example
Given [1, 2, 1, 3, 4, 5, 7, 6]

Return index 1 (which is number 2) or 6 (which is number 7)

Note
The array may contains multiple peeks, find any of them.

Challenge
Time complexity O(logN)
	
*/

#include "../commonHeader.h"

int findPeakHelper(vector<int>& A, int l, int r)
{
	if(l > r)
	{
		return -1;
	}
	
	int mid = l + (r - l) / 2;
	
	if(mid == 0 || mid == A.size() - 1)
	{
		return -1;
	}
	
	if(A[mid] > A[mid - 1] && A[mid] > A[mid + 1])
	{
		return mid;
	}
	else if(A[mid] < A[mid - 1] && A[mid] < A[mid + 1])
	{
		int leftIndex = findPeakHelper(A,l, mid - 1);
		
		return (leftIndex != -1)? leftIndex : findPeakHelper(A,mid + 1, r);
	}
	else
	{
		if(A[mid] > A[mid - 1])
		{
			//mid - 1 can't be a peak
			int leftIndex = findPeakHelper(A,l, mid - 2);
			
			return (leftIndex != -1)? leftIndex : findPeakHelper(A,mid + 1, r);
		}
		else
		{
			//mid + 1 can't be a peak
			int leftIndex = findPeakHelper(A,l, mid - 1);
			return (leftIndex != -1)? leftIndex : findPeakHelper(A,mid + 2, r);
		}
	}
}

int findPeak(vector<int> A) 
{
	if(A.size() < 3)
		return -1;
	
	return findPeakHelper(A,1,A.size() - 2);
}

int main()
{
	vector<int> vec = {1, 2,3, 1};
	cout << findPeak(vec) << endl;
}