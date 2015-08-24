/*

There are n coins in a line. Two players take turns to take one or two coins from right side until there are no more coins left. The player who take the last coin wins.

Could you please decide the first play will win or lose?

Have you met this question in a real interview? Yes
Example
n = 1, return true.

n = 2, return true.

n = 3, return false.

n = 4, return true.

n = 5, return true.

Challenge
O(n) time and O(1) memory


*/


#include "../commonHeader.h"

bool firstWillWin(int n) 
{
	return n % 3 != 0;
	
	/*
	vector<int> dp(n,false);
	dp[0] = true;
	dp[1] = true;
	for(int i = 2; i < n; i++)
	{
		if(dp[i - 1])
		if(dp[i - 1] || dp[i - 2])
		{
			dp[i] = false;
		}
		else
		{
			dp[i] = true;
		}
	}
	return dp[n - 1];
	bool board[3];
	bool firstPlayerTerm = true;
	
	for(int i = 0; i < n; i += 2)
	{
		int oneStep = i % 3;
		int twoStep = (i + 1) % 3;
		if(firstPlayerTerm)
		{	
			board[oneStep] = true;
			board[twoStep] = true;
			firstPlayerTerm = false;
		}
		else
		{
			board[oneStep] = false;
			board[twoStep] = false;
			firstPlayerTerm = true;
		}
	}
	return board[(n - 1) % 3];
	*/
}

int main()
{
	cout << firstWillWin(5) << endl;
}

