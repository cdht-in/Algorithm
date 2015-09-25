/*
	
Medium Edit Distance

29% Accepted
Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

Insert a character
Delete a character
Replace a character
Have you met this question in a real interview? Yes
Example
Given word1 = "mart" and word2 = "karma", return 3.
	
*/

#include "../commonHeader.h"

int minDistance(string word1, string word2) 
{
	vector<vector<int> > dp(word2.size() + 1, vector<int>(word1.size() + 1,INT_MAX));
	
	for(int i = 0; i <= word1.size(); i++)
	{
		dp[0][i] = i;
	}
	
	for(int i = 0; i <= word2.size(); i++)
	{
		dp[i][0] = i;
	}
	
	for(int i = 1; i <= word2.size(); i++)
	{
		for(int j = 1; j <= word1.size() ; j++)
		{
			if(word2[i - 1] == word1[j - 1])
			{
				//no change
				dp[i][j] = std::min(dp[i][j],dp[i - 1][j - 1]);
			}
			else
			{
				//replace
				dp[i][j] = std::min(dp[i][j],dp[i - 1][j - 1] + 1);
				
				//insert
				dp[i][j] = std::min(dp[i][j],dp[i][j - 1] + 1);
				
				//delete
				dp[i][j] = std::min(dp[i][j],dp[i - 1][j] + 1);
				
			}
		}
	}
	
	return dp[word2.size()][word1.size()];
	
	
}

int main()
{
	
}