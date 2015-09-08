/*
Given an array of citations (each citation is a non-negative integer) of a researcher, write a function to compute the researcher's h-index.

According to the definition of h-index on Wikipedia: "A scientist has index h if h of his/her N papers have at least h citations each, and the other N − h papers have no more than h citations each."

For example, given citations = [3, 0, 6, 1, 5], which means the researcher has 5 papers in total and each of them had received 3, 0, 6, 1, 5 citations respectively. Since the researcher has 3 papers with at least 3 citations each and the remaining two with no more than 3 citations each, his h-index is 3.

Note: If there are several possible values for h, the maximum one is taken as the h-index.

Hint:

An easy approach is to sort the array first.
What are the possible values of h-index?
A faster approach is to use extra space.
	
*/

#include "./commonHeader.h"

int binarySearch(vector<int>& citations, int k, bool& found)
{
	int l = 0, mid = 0, r = citations.size() - 1;
	while(l <= r)
	{
		mid = l + (r - l) / 2;
		if(citations[mid] == k)
		{
			found = true;
			return mid;
		}	
		else if(citations[mid] < k)
		{
			l = mid + 1;
		}
		else
		{
			r = mid - 1;
		}
	}
	found = false;
	return l;
}

//O(n^2)
int hIndex(vector<int>& citations) 
{
	sort(citations.begin(),citations.end());
	int h = 0;
		
	for(int i = citations.size() - 1; i >= 0; i--)
	{
		//h is at most citations.size()
		for(int j = citations.size(); j > 0; j--)
		{
			if(citations.size() - i >= j && citations[i] >= (int)citations.size() - i)
			{
				h = std::max(h, (int)citations.size() - i);
			}
		}
	}
	
	return h;
}

//not correct
int hIndexI(vector<int>& citations) 
{
	sort(citations.begin(),citations.end());
	int h = 0;
		
	for(int i = citations.size() - 1; i >= 0; i--)
	{
		//h is at most citations.size()
		if(citations[i] < (int)citations.size() - i)
			continue;
		
		//find the first j that is less or equal to citations.size() - i
		int l = 1, mid = 0,r = citations.size();
		while(l <= r)
		{
			mid = l + (r - l) / 2;
			if(mid == citations.size() - i)
				break;
			else if(mid < citations.size() - i)
				l = mid + 1;
			else
				r = mid - 1;
		}
		
		h = std::max(h, r);
	}
	
	return h;
}


int main()
{
	vector<int> foo = {3,0,6,1,5};
	cout << hIndexI(foo) << endl;
}