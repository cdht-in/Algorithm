/*
	
Given n items with size Ai and value Vi, and a backpack with size m. What's the maximum value can you put into the backpack?

Have you met this question in a real interview? Yes
Example
Given 4 items with size [2, 3, 5, 7] and value [1, 5, 2, 4], and a backpack with size 10. The maximum value is 9.

Note
You cannot divide item into small pieces and the total size of items you choose should smaller or equal to m.

Challenge
O(n x m) memory is acceptable, can you do it in O(m) memory?
	
*/

#include "../commonHeader.h"

//O(n * m) in space
int backPackII(int m, vector<int> A, vector<int> V) 
{
	vector<vector<int> > dp(m + 1,vector<int>(A.size() + 1,0));
	
	for(int size = 1; size <= m; size++)
	{
		for(int bag = 1; bag <= A.size(); bag++)
		{
			//if taken the bag
			if(size >= A[bag - 1])
			{
				dp[size][bag] = std::max(dp[size][bag],V[bag - 1] + dp[size - A[bag - 1]][bag - 1]);
			}
			
			//if not taken the bag
			dp[size][bag] = std::max(dp[size][bag],dp[size][bag - 1]);
		}
	}
	
	return dp[m][A.size()];
}

//with memory optimization
int backPackIII(int m, vector<int> A, vector<int> V) 
{
	vector<int > dp(m + 1,0);
	
	
	/*
	both work, NOTE if can't think of a way to optimize the memory, reversing the outer and inner loop sometime helps.
	for(int bag = A.size() ; bag >= 1; bag--)
	{
		for(int size = m; size >= 1; size--)
		{
			if(size >= A[bag - 1])
			{
				dp[size] = std::max(dp[size],V[bag - 1] + dp[size - A[bag - 1]]);
			}
		}
	}
	
	for(int bag = 1 ; bag <= A.size(); bag++)
	{
		for(int size = m; size >= 1; size--)
		{
			if(size >= A[bag - 1])
			{
				dp[size] = std::max(dp[size],V[bag - 1] + dp[size - A[bag - 1]]);
			}
		}
	}
	*/	
	
	return dp[m];
}



int main()
{
	
}