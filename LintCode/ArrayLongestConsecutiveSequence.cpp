/*

Medium Longest Consecutive Sequence

32% Accepted
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

Have you met this question in a real interview? Yes
Example
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Clarification
Your algorithm should run in O(n) complexity.

*/

#include "../commonHeader.h"

int longestConsecutive(vector<int> &num) 
{
	unordered_set<int> set;
	for(auto i : num)
	{
		set.insert(i);
	}
	
	int len = INT_MIN;
	while(set.empty() == false)
	{
		int head = *set.begin();
		int p = head;
		int c = 1;
		set.erase(set.begin());
		
		while(set.empty() == false && set.find(p - 1) != set.end())
		{
			set.erase(set.find(p - 1));
			p--;
			c++;
		}
		
		p = head;
		while(set.empty() == false && set.find(p + 1) != set.end())
		{
			set.erase(set.find(p + 1));
			p++;
			c++;
		}
		
		len = std::max(len,c);
	}
	return len;
}

int main()
{
	vector<int> num = {100,4,200,1,3,2};
	cout << longestConsecutive(num) << endl;
}