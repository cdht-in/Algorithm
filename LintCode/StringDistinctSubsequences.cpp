/*
	
Medium Distinct Subsequences

30% Accepted
Given a string S and a string T, count the number of distinct subsequences of T in S.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Have you met this question in a real interview? Yes
Example
Given S = "rabbbit", T = "rabbit", return 3.

Challenge
Do it in O(n2) time and O(n) memory.

O(n2) memory is also acceptable if you do not know how to optimize memory.

*/

#include "../commonHeader.h"

int numDistinct(string &S, string &T) 
{
	int m = S.size();
	int n = T.size();
	vector<vector<int> > dp(m + 1, vector<int>(n + 1, 0));
	//empty T to S
	for(int i = 0; i <= m; i++)
	{
		dp[i][0] = 1;
	}
	
	for(int i = 1; i <= m; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			if(S[i - 1] == T[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
			}
			else
			{
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
		
	return dp[m][n];
}

//rolling 
int numDistinctI(string &S, string &T) 
{
	int m = S.size();
	int n = T.size();
	vector<int> dp(n + 1, 0);
	//empty T to S
	dp[0] = 1;
	
	for(int i = 1; i <= m; i++)
	{
		for(int j = n; j >= 1; j--)
		{
			//dp[j] stores the dp[i - 1][j] amd d[j - 1] stores the dp[i - 1][j - 1]
			if(S[i - 1] == T[j - 1])
			{
				dp[j] = dp[j] + dp[j - 1];
			}
			//this line is here to illustarte the difference between this and the previous solution
			else
			{
				dp[j] = dp[[j];
			}
		}
	}
		
	return dp[n];
}

int main()
{
	string S = "ddd";
	string T = "dd";
	cout << numDistinct(S,T) << endl;
		
}