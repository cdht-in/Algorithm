/*
	
Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.
	
*/

#include "commonHeader.h"

bool isAnagram(string s, string t) 
{
	if(s.size() != t.size())
		return false;
	
	unordered_map<char,int> map;
	for(char i : s)
	{
		if(map.find(i) == map.end())
			map[i] = 0;
		map[i]++;
	}
	
	for(char i : t)
	{
		if(map.find(i) != map.end())
		{
			map[i]--;
			if(map[i] <= 0)
				map.erase(i);
		}	
	}
	
	return map.size() == 0;
}

int main()
{
	
}