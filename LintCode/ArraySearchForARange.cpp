/*
	
Medium Search for a Range

20% Accepted
Given a sorted array of n integers, find the starting and ending position of a given target value.

If the target is not found in the array, return [-1, -1].

Have you met this question in a real interview? Yes
Example
Given [5, 7, 7, 8, 8, 10] and target value 8, return [3, 4].

Challenge
O(log n) time.
	
*/

#include "../commonHeader.h"

vector<int> searchRange(vector<int> &A, int target) 
{
	int l = 0, r = A.size() - 1, mid = 0, lbound = -1, rbound = -1;
	while(l <= r)
	{
		mid = l + (r - l) / 2;
		if(A[mid] == target)
		{
			int index = mid;
			while(index >= 1 && A[index - 1] == A[index])
			{
				index--;
			}
			lbound = index;
			
			index = mid;
			while(index < A.size() - 1 && A[index + 1] == A[index])
			{
				index++;
			}
			rbound = index;
			break;
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
	return vector<int>({lbound,rbound});
}

int main()
{
	
}