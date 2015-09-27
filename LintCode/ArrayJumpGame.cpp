/*

	Given an array of non-negative integers, you are initially positioned at the first index of the array.

	Each element in the array represents your maximum jump length at that position.

	Determine if you are able to reach the last index.

	Have you met this question in a real interview? Yes
	Example
	A = [2,3,1,1,4], return true.

	A = [3,2,1,0,4], return false.

	Note
	This problem have two method which is Greedy and Dynamic Programming.

	The time complexity of Greedy method is O(n).

	The time complexity of Dynamic Programming method is O(n^2).

	We manually set the small data set to allow you pass the test in both ways. This is just to let you learn how to use this problem in dynamic programming ways. If you finish it in dynamic programming ways, you can try greedy method to make it accept again.
	
*/

#include "../commonHeader.h"

//greedy
bool canJump(vector<int> A) 
{
	int maxReach = 0;
	for(int i = 0; i < A.size(); i++)
	{
		if(i <= maxReach)
		{
			int newMaxReach = i + A[i];
			maxReach = std::max(maxReach,newMaxReach);
		}
	}
	
	return maxReach >= A.size() - 1;
}


//O(n^2)
bool canJumpI(vector<int> A)
{
	vector<bool> dp(A.size(),false);
	dp[0] = true;
	for(int i = 0; i < A.size(); i++)
	{
		if(dp[i])
		{
			for(int j = 0; j <= A[i]; j++)
			{
				int pos = i + j;
				if(pos < A.size())
				{
					dp[pos] = true;
				}
			}
		}
	}
	return dp[A.size() - 1];
}

int main()
{
	vector<int> vec = {5,8,3,0,6,7,9,6,3,4,5,2,0,6,2,6,7,10,8,0};
	cout << canJump(vec) << endl;
}