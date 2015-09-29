/*
	
Medium Longest Common Substring

30% Accepted
Given two strings, find the longest common substring.

Return the length of it.

Have you met this question in a real interview? Yes
Example
Given A = "ABCD", B = "CBCE", return 2.

Note
The characters in substring should occur continuously in original string. This is different with subsequence.

Challenge
O(n x m) time and memory.

	
*/

#include "../commonHeader.h"

//with substrings
int longestCommonSubstring(string &A, string &B) 
{	
	unordered_set<string> set;
	
	for(int i = 0; i < A.size(); i++)
	{
		for(int j = i + 1; j <= A.size(); j++)
		{
			set.insert(A.substr(i,j - i));
		}
	}
	
	int len = 0;
	for(int i = 0; i < B.size(); i++)
	{
		for(int j = i + 1; j <= B.size(); j++)
		{
			if(set.find(B.substr(i, j - i)) != set.end())
			{
				len = std::max(len,j - i);
			}
		}
	}
	
	return len;
}

//The idea is to find length of the longest common suffix for all substrings of both strings and store these lengths in a table.
int longestCommonSubstringI(string &A, string &B)
{
	vector<vector<int> > dp(B.size() + 1, vector<int>(A.size() + 1, 0));
	
	int len = 0;
	for(int i = 1; i <= B.size(); i++)
	{
		for(int j = 1; j <= A.size(); j++)
		{
			if(B[i - 1] == A[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
				len = std::max(len,dp[i][j]);
			}
			else
			{
				dp[i][j] = 0;
			}
		}
	}
	
	return len;
}

int main()
{
	string A = "ABC";
	string B = "ABC";
	cout << longestCommonSubstringI(A,B) << endl;
}