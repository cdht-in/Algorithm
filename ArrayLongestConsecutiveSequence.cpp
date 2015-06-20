/*
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.
	
*/

#include <unordered_set>
#include <vector>
#include <climits>
#include <iostream>

using namespace std;


//O(n^2) time and O(n) space
int longestConsecutive(vector<int> &num) {
	if(num.size() < 1)
		return 0;
	if(num.size() == 1)
		return 1;
	unordered_set<int> set;
	int maxLen = INT_MIN;
	int n = num.size();
	
	for(int i = 0; i < n; i++)
	{
		if(set.find(num[i]) == set.end())
			set.insert(num[i]);
	}

	for(int i = 0; i < n; i++)
	{
		//one consecutive sequence only be searched once
		int localLen = 1;
		set.erase(num[i]);
		//find the left part
		for(int j = num[i] - 1; set.find(j) != set.end(); j--)
		{
			localLen++;
			set.erase(j);
		}
		
		//find the right part
		for(int j = num[i] + 1; set.find(j) != set.end(); j++)
		{
			localLen++;
			set.erase(j);
		}
		
		if(localLen > maxLen)
			maxLen = localLen;
	}
	return maxLen;
}

int main(){
	int foo[] = {100, 4, 200, 1, 3, 2};
	vector<int> bar(foo, foo + sizeof(foo) / sizeof(int));
	cout << longestConsecutive(bar) << endl;
}