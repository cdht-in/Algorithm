/*
	
Given a string s, find the length of the longest substring T that contains at most k distinct characters.

Have you met this question in a real interview? Yes
Example
For example, Given s = "eceba", k = 3,

T is "eceb" which its length is 4.

Challenge
O(n), n is the size of the string s.
	
*/

#include "../commonHeader.h"

int lengthOfLongestSubstringKDistinct(string s, int k) 
{	
	unordered_map<char,int> map;
	int l = 0, r = 0, len = 0;
	while(r < s.size())
	{
		map[s[r]]++;
		while(l <= r && map.size() > k)
		{
			map[s[l]]--;
			if(map[s[l]] == 0)
			{
				map.erase(s[l]);
			}
			l++;
		}
		
		len = std::max(len,r - l + 1);
		r++;
	}
	return len;
}

int main()
{
	string s = "abc";
	int k = 4;
	cout << lengthOfLongestSubstringKDistinct(s,k) << endl;
}