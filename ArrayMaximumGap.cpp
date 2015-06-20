/*

Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

Try to solve it in linear time/space.

Return 0 if the array contains less than 2 elements.

You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.

*/
#include <vector>
#include <iostream>
#include <climits>


using namespace std;

//counting sort, O(n)
int maximumGap(vector<int> &num) {
	if(num.size() < 2)
		return 0;
	vector<int> c(INT_MAX,0);
	
	for(int i = 0; i < num.size(); i++)
	{
		c[num[i]]++;
	}
	
	int gap = 0;
	for(int l = 0; l < c.size(); l++)
	{
		if(c[l] == 0)
			continue;
		
		int r = l + 1;
		for(; r < c.size() && c[r] == 0; r++);		
		
		if(r == c.size())
			break;
		
		if(r - l > gap)
		{	
			gap = r - l;
		}
		
		l = r;
	}
	return gap;
}

//bucket sort
int maximumGapI(vector<int> &num) {
	if(num.size() < 2)
		return 0;
	
	int max = -1;
	
	int n = num.size();
	
	for(int i = 0; i < n; i++)
	{
		if(num[i] > max)
			max = num[i];
	}
	
	//n buckets
	vector<vector<int> > buckets(n,vector<int>());
	
	//distribute numbers into buckets
	for(int i = 0; i < n; i++)
	{
		int index = num[i] / max * (n - 1) ;
		buckets[index].push_back(num[i]);
	}
	
	
	//sort each buckets
	for(int i = 0; i < n; i++)
	{
		sort(buckets[i].begin(),buckets[i].end());
	}
	
	//put each bucket back to the list
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < buckets[i].size(); j++)
		{
			num[i + j] = buckets[i][j];
		}
	}
	
	int gap = 0;
	for(int i = 1; i < n; i++)
	{
		if(num[i] - num[i - 1] > gap)
			gap = num[i] - num[i - 1];
	}
	return gap;
}


int main(){
	vector<int> num;
	num.push_back(1);
	num.push_back(10000000);
	
	cout << maximumGapI(num) << endl;
}