/*
	
Easy Longest Increasing Continuous subsequence

26% Accepted
Give you an integer array (index from 0 to n-1, where n is the size of this array)，find the longest increasing continuous subsequence in this array. (The definition of the longest increasing continuous subsequence here can be from right to left or from left to right)

Have you met this question in a real interview? Yes
Example
For [5, 4, 2, 1, 3], the LICS is [5, 4, 2, 1], return 4.

For [5, 1, 2, 3, 4], the LICS is [1, 2, 3, 4], return 4.

Note
O(n) time and O(1) extra space.
	
*/

#include "../commonHeader.h"

int longestIncreasingContinuousSubsequence(vector<int>& A) 
{
	int len = 0;
	int i = 0;
	while(i < A.size())
	{
		int j = i + 1;
		while(j < A.size() && A[j] >= A[j - 1])
		{
			j++;
		}
		
		int subSeqLen = j - i;
		
		len = std::max(len,subSeqLen);
		
		i = j;
	}
	
	i = A.size() - 1;
	while(i >= 0)
	{
		int j = i - 1;
		while(j >= 0 && A[j] >= A[j + 1])
		{
			j--;
		}
		
		int subSeqLen = i - j;
		
		len = std::max(len,subSeqLen);
		
		i = j;
	}
	
	return len;
}

int main()
{
	
}