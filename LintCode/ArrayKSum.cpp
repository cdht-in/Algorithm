/*
	
Given n distinct positive integers, integer k (k <= n) and a number target.

Find k numbers where sum is target. Calculate how many solutions there are?

Have you met this question in a real interview? Yes
Example
Given [1,2,3,4], k = 2, target = 5.

There are 2 solutions: [1,4] and [2,3].

Return 2.

*/

#include "../commonHeader.h"

//this is correct, but it would exceed time limit on lintcode
int kSumHelper(const vector<int>& A , int index, int sum, int c,int k, int target)
{
	if(c == k && sum == target)
	{
		return 1;
	}
		
	if(c == k)
	{
		return 0;
	}
	
	int n = 0;
	for(int i = index; i < A.size(); i++)
	{
		if(sum + A[i] > target)
			break;
		
		n += kSumHelper(A,i + 1,sum + A[i],c + 1,k,target);
	}
	
	return n;
}

int kSum(vector<int> A, int k, int target) 
{
	sort(A.begin(),A.end());
	return kSumHelper(A,0,0,0,k,target);	
}

//http://www.cnblogs.com/yuzhangcmu/p/4279676.html
int kSumI(vector<int> A, int n, int target)
{
	//the first i numbers, choose j numbers and sum up to k
	int dp[A.size() + 1][n + 1][target + 1];
	//don't forget to initialize the array
	for(int i = 0; i <= A.size(); i++)
	{
		for(int j = 0; j <= n; j++)
		{
			for(int k = 0; k <= target; k++)
			{
				dp[i][j][k] = 0;
			}
		}
	}
	
	for(int i = 0; i <= A.size(); i++)
	{
		for(int j = 0; j <= n; j++)
		{
			for(int k = 0; k <= target; k++)
			{
				//choose 0 elements and the target is 0, there is one way which is not to choose at all
				if(j == 0 && k == 0)
				{
					dp[i][j][k] = 1;
				}
				else if(i > 0 && j > 0 && k > 0)
				{
					//if A[i] is not choosen and previous i - 1 numbers already suffice
					dp[i][j][k] = dp[i - 1][j][k];
					
					//if A[i] is choosen, and the previous i - 1 should suffice the following equation
					if(k >= A[i - 1])
					{
						dp[i][j][k] += dp[i - 1][j - 1][k - A[i - 1]];
					}
				}
			}
		}
	}
	
	return dp[A.size()][n][target];
}

//with reduced memory
int kSumII(vector<int> A, int k, int target)
{
	if (target < 0) 
	{
		return 0;
	}
	
	int len = A.size();
		
	// D[i][j]: k = i, target j, the solution.
	int dp[k + 1][target + 1];
	
	for(int i = 0; i < k + 1; i++)
	{
		for(int j = 0; j < target + 1; j++)
		{
			dp[i][j] = 0;
		}
	}
	
	// only one solution for the empty set.
	dp[0][0] = 1;
	for (int i = 1; i <= len; i++) 
	{
	    for (int t = target; t > 0; t--) 
		{
	        for (int j = 1; j <= k; j++) 
			{
	            if (t - A[i - 1] >= 0) 
				{
	                dp[j][t] += dp[j - 1][t - A[i - 1]];
	            }
	        }
	    }
	}
	
	return dp[k][target];
}


int main()
{
	vector<int> A = {1,2,4};
	int k = 2;
	int target = 6;
	cout << kSumII(A,k,target) << endl;
}