/*
	
Medium Longest Substring Without Repeating Characters

27% Accepted
Given a string, find the length of the longest substring without repeating characters.

Have you met this question in a real interview? Yes
Example
For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3.

For "bbbbb" the longest substring is "b", with the length of 1.

Challenge
O(n) time
	
*/

#include "../commonHeader.h"

int lengthOfLongestSubstring(string s) 
{
	int l = 0, r = 0;
	unordered_map<char,int> window;
	int len = INT_MIN;
	while(r < s.size())
	{
		if(window.find(s[r]) == window.end())
		{
			window[s[r]] = r;
			r++;
		}
		else
		{
			len = std::max(len,r - l);
			while(l <= window[s[r]])
			{
				window.erase(s[l++]);
			}
			window[s[r]] = r;
			r++;
		}
	}
	
	len = std::max(len,r - l);
	return len;
}

int main()
{
	string s = "gehmbfqmozbpripibusbezagafqtypz";
	cout << lengthOfLongestSubstring(s) << endl;
}