/*
	Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
	
*/

#include <string>
#include <iostream>

using namespace std;

int lengthOfLongestSubstring(string s) {
	
	//assume s is in all lower case
	if(s.size() == 0)
		return 0;
	if(s.size() == 1)
		return 1;
	
	int max = -1;
	int r = 0;
	int l = 0;
	int leftStart = -1;
	
	int map[26];
	memset(map,0,26 * sizeof(int));
	
	while(r < s.size())
	{
		if(map[s[r] - 'a'] == 0)
		{
			map[s[r] - 'a']	= 1;
		}
		else
		{
			//found duplicates
			if(max < r - l)
			{
				max = r - l;
				leftStart = l;
			}
			
			//now move the left boundary
			while(l < r && s[l] != s[r])
			{
				map[s[l]] = 0;
				l++;
			}
			
			//now l is the duplicate, so skip it
			l++;
		}
		r++;
	}
	
	//if not duplicates are found
	if(max < r - l)
	{
		max = r - l;
		leftStart = l;
	}
	
	return max;
}


int main()
{
	//for some reason it would fail on leetcode on this string, but works fine locally
	string s = "jlygy";
	cout << lengthOfLongestSubstring(s) << endl;
		
}