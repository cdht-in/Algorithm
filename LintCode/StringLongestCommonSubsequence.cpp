/*
	
Given two strings, find the longest common subsequence (LCS).

Your code should return the length of LCS.

Have you met this question in a real interview? Yes
Example
For "ABCD" and "EDCA", the LCS is "A" (or "D", "C"), return 1.

For "ABCD" and "EACB", the LCS is "AC", return 2.

Clarification
What's the definition of Longest Common Subsequence?

https://en.wikipedia.org/wiki/Longest_common_subsequence_problem
http://baike.baidu.com/view/2020307.htm
	
*/

#include "../commonHeader.h"

int longestCommonSubsequence(string A, string B) 
{
	vector<vector<int> > dp(B.size() + 1, vector<int>(A.size() + 1, 0));
	
	for(int i = 1; i <= B.size(); i++)
	{
		for(int j = 1; j <= A.size(); j++)
		{
			if(A[j - 1] == B[i - 1])
			{
				dp[i][j] = std::max(dp[i][j],dp[i - 1][j - 1] + 1);
			}
			else
			{
				dp[i][j] = std::max(dp[i - 1][j],dp[i][j - 1]);
			}
		}
	}
	
	return dp[B.size()][A.size()];
}

int main()
{
	string A = "bedaacbade";
	string B = "dccaeedbeb";
	cout << longestCommonSubsequence(A,B) << endl;
}