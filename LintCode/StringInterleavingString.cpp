/*
	
Medium Interleaving String

26% Accepted
Given three strings: s1, s2, s3, determine whether s3 is formed by the interleaving of s1 and s2.

Have you met this question in a real interview? Yes
Example
For s1 = "aabcc", s2 = "dbbca"

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.
Challenge
O(n2) time or better
	
*/

#include "../commonHeader.h"

bool isInterleave(string s1, string s2, string s3) 
{
	if(s1.size() + s2.size() != s3.size())
		return false;
	
	vector<vector<bool> > dp(s1.size() + 1,vector<bool>(s2.size() + 1,false));
	dp[0][0] = true;
	for(int i = 1; i < s2.size() + 1; i++)
	{
		dp[0][i] = (s2[i - 1] == s3[i - 1]);
	}
	
	for(int i = 1; i < s1.size() + 1; i++)
	{
		dp[i][0] = (s1[i - 1] == s3[i - 1]);
	}
	
	//until i and j, if s1[i] and s2[j] matches s3[i + j]
	for(int i = 1; i <= s1.size(); i++)
	{
		for(int j = 1; j <= s2.size(); j++)
		{
			if(s3[i + j - 1] == s1[i - 1])
			{
				dp[i][j] = dp[i - 1][j];
			};
			
			if(s3[i + j - 1] == s2[j - 1])
			{
				dp[i][j] = dp[i][j] || dp[i][j - 1];
			}
		}
	}
	
	return dp[s1.size()][s2.size()];
}

int main()
{
	string s1 = "aabcc";
	string s2 = "dbbca";
	string s3 = "aadbbbaccc";
	
	cout << isInterleave(s1,s2,s3) << endl;
}