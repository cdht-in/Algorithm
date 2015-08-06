/*
	
	Given n pieces of wood with length L[i] (integer array). Cut them into small pieces to guarantee you could have equal or more than k pieces with the same length. What is the longest length you can get from the n pieces of wood? Given L & k, return the maximum length of the small pieces.
	
*/

#include "../commonHeader.h"

//http://algorithm.yuanbin.me/binary_search/wood_cut.html
int woodCut(vector<int> L, int k) 
{
	if(L.size() == 0 || k <= 0)
		return 0;
	
	sort(L.begin(),L.end());
	
	int end = L[L.size() - 1];
	int start = 0;
	int mid = 0;
	int maxLen = 0;
	while(start + 1 < end)
	{
		mid = start + (end - start) / 2;
		
		int c = 0;
		for(int i : L)
		{
			c += (i / mid);
		}
		
		if(c < k)
		{
			end = mid;
		}
		else
		{
			start = mid;
			maxLen = mid;
		}
	}
	
	return maxLen;
	
}

int main()
{
	
}