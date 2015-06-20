/*
	
Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false
	
*/

#include <iostream>
#include <vector>

using namespace std;

//O(m * n)
bool isMatch(const char *s, const char *p) {	
		
	const char* sp = s;
	const char* pp = p;
	
	bool wildcard = false;
	
	while(*s != '\0')
	{
		if(*p == '?' || *s == *p)
		{
			s++;
			p++;
			continue;
		}
		if(*p == '*')
		{
			//save the wild card location
			sp = s;
			pp = p;
			p++;
			wildcard = true;
			continue;
		}
		
		//NOTE here how it tries to match the matter like s = ACC, p = *C;
		if(wildcard)
		{
			sp++;
			s = sp;
			p = pp + 1;
			continue;
		}
		return false;	
	}
	
	while(*p == '*')
		p++;
	
	return *p == '\0';
}

//second implementation
bool isMatchI(const char *s, const char *p) {
	
	bool wildCard = false;
	
	const char* wildCardS = s;
	const char* wildCardP = p;
	while(*s != '\0')
	{
		if(*p == '?' || *s == *p)
		{
			s++;
			p++;
			continue;
		}
		
		if(*p == '*')
		{
			//you can think of this as the "*" match zero occurance of *s
			wildCard = true;
			wildCardP = p;
			wildCardS = s;
			p++;
			continue;
		}
		
		if(wildCard)
		{
			//this tries to match the * with any number of *s
			wildCardS++;
			s = wildCardS;
			p = wildCardP + 1;
			continue;
		}
		
		return false;
	}
	
	while(*p == '*')
		p++;
	return *p == '\0';
}

bool isMatchRecursionHelper(const char *s, const char *p, int l, int r)
{
	if(p[r] == '\0')
		return s[l] == '\0';
	
	if(p[r] == '*')
	{
		//skip those '*'s
		while(p[r] == '*')
			r++;
		
		while(s[l] != '\0')
		{
			if(isMatchRecursionHelper(s,p,l,r))
				return true;
			l++;
		}
		
		//this would take care of the case where s[l] != '\0'
		return isMatchRecursionHelper(s,p,l,r);
	}
	else
	{
		if(s[l] != '\0' && (p[r] == '?' || s[l] == p[r]))
			return (isMatchRecursionHelper(s,p,l + 1,r + 1));
	}
	return false;
}

//recursion
bool isMatchRecursion(const char *s, const char *p)
{
	return isMatchRecursionHelper(s,p,0,0);
}


//DP
bool isMatchDP(const char *s, const char *p) 
{			
	int m = strlen(s);
	int n = strlen(p);
		
	vector<vector<bool> > dp(m + 1,vector<bool>(n + 1, false));
	dp[0][0] = true;
	
	for(int i = 1; i <= n; i++)
	{
		if(p[i] != '*')
		{
			for(int j = 1; j <= m; j++)
			{
				dp[j][i] = ((p[i] == '?') || (s[j - 1] == p[i - 1])) && dp[j - 1][i - 1];
			}
		}
		else
		{
			int k = 0;
			while(k <= m && dp[k][i] == false)
			{
				k++;
			}
			
			while(k <= m)
			{
				dp[k][i] = true;
				k++;
			}
		}
		
	}
	
	return dp[m][n];
}

int main()
{
	char s[] = "aa";
	char p[] = "*";
	bool result = isMatchDP(s,p);
	cout << result << endl;
}