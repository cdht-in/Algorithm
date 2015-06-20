/*
	
'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true

*/

/*
The recursion mainly breaks down elegantly to the following two cases:

1. If the next character of p is NOT ‘*’, then it must match the current character of s. Continue pattern matching with the next character of both s and p.
2. If the next character of p is ‘*’, then we do a brute force exhaustive matching of 0, 1, or more repeats of current character of p… Until we could not match any more characters.
	
*/

#include <vector>
#include <iostream>
#include <string>

using namespace std;

//http://articles.leetcode.com/2011/09/regular-expression-matching.html
//O(2^n)
bool isMatch(const char *s, const char *p) 
{	
	if (*p == '\0') 
		return *s == '\0';

	// next char is not '*': must match current character
	if (*(p + 1) != '*')
	{
	  return ((*p == *s) || (*p == '.' && *s != '\0')) && isMatch(s + 1, p + 1);
	}
	
	// next char is '*'
	while ((*p == *s) || (*p == '.' && *s != '\0')) 
	{
	  if (isMatch(s, p + 2)) 
		  return true;
	  s++;
	}
	
	//this would lead to the zero occurance of the *p, e.g s = a, p = b*a
	return isMatch(s, p + 2);
}

bool isMatchHelper(const string& s, int startS,const string& p, int startP)
{
	if(startP == p.size())
		return startS == s.size();
	
	if(p[startP + 1] != '*')
	{
		return ((s[startS] == p[startP]) ||
			 (p[startP] == '.' && startS != s.size())) && isMatchHelper(s,startS + 1, p,startP + 1);
	}
	
	while(s[startS] == p[startP] || (p[startP] == '.' && startS != s.size()))
	{
		if(isMatchHelper(s,startS,p,startP + 2))
			return true;
		startS++;
	}
	
	return isMatchHelper(s,startS,p,startP + 2);
}

bool isMatch(string s, string p) 
{
	return isMatchHelper(s,0,p,0);
}
	
//DP O(n^2)
bool isMatchI(const char *s, const char *p) 
{
	int m = strlen(s), n = strlen(p);
	vector<vector<bool> > dp(m + 1, vector<bool>(n + 1,false));
	dp[0][0] = true;
    
	for(int i = 0; i <= m; i++) 
	{
	    for(int j = 1; j <= n; j++) 
		{
			//regular matching
	        if(p[j - 1] !='.' && p[j - 1] !='*') 
			{
	            if(i > 0 && s[i - 1] == p[j - 1] && dp[i - 1][j - 1])
	                dp[i][j] = true;
	        }
	        else if(p[j - 1] == '.') 
			{
	            if(i > 0 && dp[i - 1][j - 1])
	                dp[i][j] = true;
	        }
			//'*' cannot be the 1st element
	        else if(j > 1) 
			{  
	            if(dp[i][j - 1] || dp[i][j - 2])  // match 0 or 1 preceding element
	                dp[i][j] = true;
				
	            else if(i > 0 && (p[j - 2] == s[i - 1] || p[j - 2] == '.') && dp[i - 1][j]) 
					// match multiple preceding elements
	                dp[i][j] = true;
	        }
	    }
	}
	return dp[m][n];
}

int main()
{
	char s[] = "aab";
	char p[] = "c*a*b";
	cout << isMatch(s,p) << endl;
	
}