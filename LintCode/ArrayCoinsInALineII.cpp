/*
	
Medium Coins in a Line II

29% Accepted
There are n coins with different value in a line. Two players take turns to take one or two coins from left side until there are no more coins left. The player who take the coins with the most value wins.

Could you please decide the first player will win or lose?

Have you met this question in a real interview? Yes
Example
Given values array A = [1,2,2], return true.

Given A = [1,2,4], return false.
	
*/

#include "../commonHeader.h"

//greedy
bool firstWillWin(vector<int> &values) 
{
	int n = values.size();
	int max1 = 0;
	int max2 = 0;
	bool firstTurn = true;
	for(int i = 0; i < n; i++)
	{
		if(firstTurn)
		{
			max1 += values[i];
			if(i + 1 < n && values[i + 1] >= values[i])
				max1 += values[++i];
		}
		else
		{
			max2 += values[i];
			if(i + 1 < n && values[i + 1] >= values[i])
				max2 += values[++i];
		}
		firstTurn = !firstTurn;
	}
	return max1 > max2;
}

int main()
{
	
}
