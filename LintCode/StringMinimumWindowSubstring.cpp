/*
	
Given a string source and a string target, find the minimum window in source which will contain all the characters in target.

Have you met this question in a real interview? Yes
Example
source = "ADOBECODEBANC" target = "ABC" Minimum window is "BANC".

Note
If there is no such window in source that covers all characters in target, return the emtpy string "".

If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in source.

Challenge
Can you do it in time complexity O(n) ?

Clarification
Should the characters in minimum window has the same order in target?

    - Not necessary.

*/

#include "../commonHeader.h"

string minWindow(string &source, string &target) 
{
	int len = INT_MAX;
	int index = -1;
	string s = "";
	int l = 0, r = 0,c = 0;
	unordered_map<char,int> window;
	for(int i = 0; i < target.size(); i++)
	{
		window[target[i]]++;
	}
	
	while(r < source.size())
	{
		///aaaaba ab
		if(window.find(source[r]) != window.end())
		{
			window[source[r]]--;
			
			//pay attention to how those if statements skip those duplicates like in "aaaaba" "ab"
			if(window[source[r]] >= 0)
				c++;
			
			while(c == target.size())
			{
				int windowLen = r - l + 1;
				if(windowLen < len)
				{
					len = windowLen;
					index = l;
				}
				
				if(window.find(source[l]) != window.end())
				{
					window[source[l]]++;
					//pay attention to how those if statements skip those duplicates like in "aaaaba" "ab"
					if(window[source[l]] > 0)
					{
						c--;
					}
				}
				l++;
			}
		}
		r++;		
	}
	
	return (index == -1)? "" : source.substr(index,len);
}

int main()
{
	string s = "ADOBECODEBANC";
	string target = "ABC";
	cout << minWindow(s,target) << endl;
}