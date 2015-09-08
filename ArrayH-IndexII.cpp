/*

Follow up for H-Index: What if the citations array is sorted in ascending order? Could you optimize your algorithm?

Hint:

Expected runtime complexity is in O(log n) and the input is sorted.

*/


#include "./commonHeader.h"

int hIndex(vector<int>& citations) 
{
	int l = 0, r = citations.size() - 1;
	while(l <= r)
	{
		int mid = l + (r - l) / 2;
		
		if(citations[mid] == citations.size() - mid)
		{
			return citations[mid];
		}
		else if(citations[mid] > citations.size() - mid)
		{
			r = mid - 1;
		}
		else
		{
			l = mid + 1;
		}
	}
	
	return citations.size() - l;	
}

int hIndex(vector<int>& citations,int k) 
{
	int l = 0, r = citations.size() - 1;
	while(l <= r)
	{
		int mid = l + (r - l) / 2;
		
		if(citations[mid] == k)
		{
			return citations[mid];
		}
		else if(citations[mid] > k)
		{
			r = mid - 1;
		}
		else
		{
			l = mid + 1;
		}
	}
	
	if(r == -1)
	{
		throw "nothing smaller than " + to_string(k);
	}
	return citations[l];
	
}


int main()
{
	vector<int> foo = {0,1,3,4,6};
	int k = -1;
	cout << hIndex(foo,k) << endl;
	
}