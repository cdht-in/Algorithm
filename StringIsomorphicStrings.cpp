/*

Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

For example,
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true.

Note:
You may assume both s and t have the same length.
	
*/

#include <string>
#include <map>
#include <iostream>

using namespace std;

bool isIsomorphic(string s, string t) 
{
	map<char,char> mappingForward;
	map<char,char> mappingBackward;
	for(int i = 0; i < s.size(); i++)
	{
		if(mappingForward.find(s[i]) == mappingForward.end())
		{
			mappingForward[s[i]] = t[i];
		}
		else
		{
			if(mappingForward[s[i]] != t[i])
				return false;
		}
		
		if(mappingBackward.find(t[i]) == mappingBackward.end())
		{
			mappingBackward[t[i]] = s[i];
		}
		else
		{
			if(mappingBackward[t[i]] != s[i])
				return false;
		}
	}
	
	return true;
}

int main()
{
	cout << isIsomorphic("ab","aa") << endl;
	
}