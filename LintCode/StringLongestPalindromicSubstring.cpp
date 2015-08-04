/*
	
Longest Palindromic Substring

23% Accepted
Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.

Have you met this question in a real interview? Yes
Example
Given the string = "abcdzdcab", return "cdzdc".

Challenge
O(n2) time is acceptable. Can you do it in O(n) time.
	
*/

#include "../commonHeader.h"

bool IsPalindrome(string s)
{
	for(int i = 0; i < s.size() / 2; i++)
	{
		if(s[i] != s[s.size() - 1 - i])
			return false;
	}
	return true;
}

//O(n^2)
string longestPalindrome(string& s) 
{
	int len = 0;
	string substr = "";
	for(int i = 0; i < s.size(); i++)
	{
		for(int j = i; j < s.size(); j++)
		{
			if(IsPalindrome(s.substr(i,j - i + 1)))
			{	
				if(j - i + 1 > len)
				{
					len = j - i + 1;
					substr = s.substr(i, j - i + 1);
				}
			}
		}
	}
	return substr;
}

//approch II, post-fix tree O(n)


int main()
{
	cout << IsPalindrome("bb") << endl;
}