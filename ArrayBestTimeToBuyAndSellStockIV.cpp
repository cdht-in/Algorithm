
#include <vector>
#include <iostream>

using namespace std;

int Max(int a, int b)
{
	return (a < b)? b: a;
}



//runtime error in leetcode for some reason
int maxProfit(int k, vector<int> &prices) {
    if(prices.size() < 2 || k <= 0)
	{
		return 0;
	}
	int n = prices.size() + 1;
	int** local = new int*[n];
	int** global = new int*[n];
	for(int i = 0; i < n; i++)
	{
		local[i] = new int[k + 1];
		global[i] = new int[k + 1];
	}
	
	for(int i = 0 ; i < k + 1; i++)
	{
		local[0][i] = 0;
		global[0][i] = 0;
	}
	
		
	for(int i = 2; i < n; i++)
	{
		int diff = prices[i] - prices[i - 1];
		for(int j = 1; j <= k; j++)
		{
			local[i][j] = Max(global[i - 1][j - 1] + Max(diff,0), local[i - 1][j] + diff); 
			global[i][j] = Max(global[i - 1][j],local[i][j]);
		}
	}
	
	return global[n - 1][k];
}








































//second implementation, O(kn) time
//runtime error in leetcode for some reason
int maxProfitI(int k, vector<int> &prices) 
{
	if(k <= 0 || prices.size() < 2)
		return 0;
	
	int m = prices.size();
	//max profit if sold on day i
	vector<vector<int> > local(m,vector<int>(k + 1, 0));
	
	//max profit on day i
	vector<vector<int> > global(m,vector<int>(k + 1, 0));
		
	for(int i = 1; i < m; i++)
	{
		int profitOnDayI = prices[i] - prices[i - 1];
		for(int j = 1; j <= k; j++)
		{
			
			//global[i - 1][j - 1] = it satisfies j - 1 transaction on i - 1 day, then it makes the jth transaction on i day. If we loses money on the transaction, we choose not to do it with summing with 0
			
			//local[i - 1][j] = on i - 1 days, we already made j transaction but we dicide to sell that stock we sold before on day i this time, NOTE that this won't add the number of transaction time, simply "move" the last the transaction to day i
			local[i][j] = Max(global[i - 1][j - 1] + Max(profitOnDayI,0), local[i - 1][j] + profitOnDayI);
			
			//global[i - 1][j] = we made j transaction on i - 1 day already
			//local[i][j] = the jth transaction is made on day i
			global[i][j] = Max(global[i - 1][j],local[i][j]);
		}
	}
	return global[m - 1][k];
}


//with improved space complexity
int maxProfitII(int k, vector<int> &prices) 
{	
	if(k <= 0 || prices.size() < 2)
		return 0;
	
	int n = prices.size();
	
	//you can do any number of transaction
	if(k >= n / 2)
	{
		int sum = 0;
		for(int i = 1;i < n;i++){
		    if(prices[i] > prices[i - 1]){
		        sum += prices[i] - prices[i - 1];
		    }
		}
		return sum;
	}
	
	int dp[2][n + 1];
	memset(dp,0,sizeof(dp));
	
	for(int t = 1; t <= k; t++)
	{
	    int cur_max = 0x80000000;
	    dp[t % 2][0] = 0;
	    for(int i = 0; i < n; i++)
		{
	        dp[t % 2][i + 1] = Max(dp[(t + 1) % 2][i + 1],Max(dp[t % 2][i], prices[i] + cur_max));
	        cur_max = Max(cur_max,dp[(t + 1) % 2][i] - prices[i]);
	    }
	}
	return dp[k % 2][n];
}

//another interpretation, consider implementation at https://leetcode.com/problems/single-number-ii/
int maxProfitIII(int k, vector<int>& prices)
{
	if(k == 0 || prices.empty()) 
		return 0;
	// Max profit by k transaction from 0 to i
	const int n = prices.size();     
	
 	// balance - the balance with exactly j transactions with item 0 to i
    // profit - the profit with exactly j transactions with item 0 to i
    vector<int> balance(k + 1, INT_MIN), profit(k + 1,0);

    for(int i = 0; i < n; ++i) 
	{
        for(int j = 1; j <= k; ++j) 
		{
            balance[j] = max(profit[j - 1] - prices[i], balance[j]); // whether buy at prices[i]
			
            profit[j] = max(balance[j] + prices[i], profit[j]); // whether sell at prices[i]
        }
    }

    return profit[k];
}


//O(n + klog(n))
//https://leetcode.com/discuss/26745/c-solution-with-o-n-klgn-time-using-max-heap-and-stack


int main(){
	vector<int> vec = {1,2,4,2,5,7,2,4,9,0};
	int k = 4;
	
	cout << maxProfitIII(k,vec) << endl;
	
}