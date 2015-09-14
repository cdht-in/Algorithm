/*
	
Given an array with positive and negative integers. Re-range it to interleaving with positive and negative integers.

Have you met this question in a real interview? Yes
Example
Given [-1, -2, -3, 4, 5, 6], after re-range, it will be [-1, 5, -2, 4, -3, 6] or any other reasonable answer.

Note
You are not necessary to keep the original order of positive integers or negative integers.

Challenge
Do it in-place and without extra memory.

*/

#include "../commonHeader.h"

void rerange(vector<int> &A) 
{
	int l = 0, r = A.size() - 1, mid = 0;
	//negative first
	while(mid <= r)
	{
		if(A[l] < 0)
		{
			l++;
			mid++;
		}
		else if(A[l] > 0)
		{
			int tmp = A[r];
			A[r] = A[l];
			A[l] = tmp;
			r--;
		}
	}
	
	int p = 0;
	int neg = 0;
	int pos = mid;
	//if there are less negative numbers, reverse it to make the positives go first so that the interleaved version is smoothed out
	if(pos - neg < A.size() - pos)
	{
		reverse(A.begin(),A.end());
		pos = A.size() - pos;
	}
			
	while(p < A.size() && pos < A.size())
	{
		if(p % 2 == 0)
		{
			A[p++] = A[neg++];
		}
		else
		{
			int tmp = A[p];
			A[p] = A[pos];
			A[pos] = tmp;
			p++;
			pos++;
			neg++;
		}
	}
	
}

int main()
{
	vector<int> vec = {1, 2, 3,-1,-2,-3};
	rerange(vec);
	for(auto i : vec)
	{
		cout << i << " ";
	}
	cout << endl;
}