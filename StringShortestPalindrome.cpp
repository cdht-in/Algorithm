/*
	
Given a string S, you are allowed to convert it to a palindrome by adding characters in front of it. Find and return the shortest palindrome you can find by performing this transformation.

For example:

Given "aacecaaa", return "aaacecaaa".

Given "abcd", return "dcbabcd".

Credits:
Special thanks to @ifanchu for adding this problem and creating all test cases. Thanks to @Freezen for additional test cases.

*/
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

bool isPalindrome(const string& s)
{
	for(int i = 0; i < s.size() / 2; i++)
	{
		if(s[i] == '.')
			continue;
		
		if(s[i] != s[s.size() - 1 - i])
			return false;
	}
	
	return true;
}

//O(n^2) this would exceed leetcode time limit
string shortestPalindrome(string s) 
{
	if(isPalindrome(s))
		return s;
	
	int n = s.size();
	
	string tmpS = s;
	//NOTE the longest palindrome it can form by this approach would be 2n, e.g. just prepending itself
	for(int i = 0; i < n; i++)
	{
		tmpS = "." + tmpS;
		if(isPalindrome(tmpS))
		{
			//convert all dots back to its correspondents
			for(int j = 0; j < tmpS.size() && tmpS[j] == '.'; j++)
			{
				tmpS[j] = tmpS[tmpS.size() - 1 - j];
			}
			
			break;
		}
	}
	
	return tmpS;
}

string shortestPalindromeI(string s) 
{
	if(s.size() == 0)
		return s;
	
	string substr = s.substr(1);
	reverse(substr.begin(),substr.end());
	
	int center = substr.size();
	
	string tmpStr = substr + s;
	
	string ret = tmpStr;
	
	while(center < tmpStr.size())
	{
		int l = center;
		int r = center;
		
		while(l >= 0 && r < tmpStr.size() && tmpStr[l] == tmpStr[r])
		{
			l--;
			r++;
		}
		
		//found the palindrome
		if(r == tmpStr.size())
		{
			//the left boundary has to be on the left of the original string
			ret = (l > 0 && l < substr.size())? tmpStr.substr(l + 1, r - l): ret;
		}
		
		center++;	
	}
	
	return ret;
}







int main()
{
	string s = "aaaaaaaaaaaaaaa";
	cout << shortestPalindromeI(s) << endl;
}
