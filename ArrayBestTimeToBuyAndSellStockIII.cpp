/*
  Say you hav>e an array for which the ith element is the price of a given stock on day i.

  Design an algorithm to find the maximum profit. You may complete at most two transactions.

  Note:
  You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/

#include <vector>
#include <queue>

using namespace std;

//first implementation
int maxProfit (vector<int>& prices)
{
  if (prices.size() <= 1)
    return 0;
  int max = 0;
  int lowest = prices[0];
  int bestdeal = 0;
  vector<int> MaxEndWith;
  MaxEndWith.push_back (0);
  for (int i = 1; i < prices.size(); i++) {
    if ( (prices[i] - lowest) >= bestdeal)
      bestdeal = prices[i] - lowest;
    MaxEndWith.push_back (bestdeal);
    if (prices[i] <= lowest)
      lowest = prices[i];
  }
  int highest = prices[prices.size() - 1];
  bestdeal = 0;
  for (int i = prices.size() - 2; i >= 0; i--) {
    if ( (highest - prices[i]) >= bestdeal)
      bestdeal = highest - prices[i];
    max = (max > (MaxEndWith[i] + bestdeal ) ) ? max : (MaxEndWith[i] + bestdeal);
    if (prices[i] >= highest)
      highest = prices[i];
  }
  return max;
}


//second implementation
int maxProfitI(vector<int> &prices) {
	if(prices.size() <= 1)
		return 0;
	
	int n = prices.size();
	vector<int> leftMaxProfit(n, 0);
	vector<int> rightMaxProfit(n, 0);
	
	int curLow = prices[0];
	int lMax = INT_MIN;
	for(int i = 1; i < n; i++)
	{
		if(prices[i] < curLow)
			curLow = prices[i];
		
		if(prices[i] - curLow > lMax)
		{
			lMax = prices[i] - curLow;
		}
		
		//the max profit in sub region [0,i]
		leftMaxProfit[i] = lMax;
	}
	
	int curHigh = prices[n - 1];
	int rMax = INT_MIN;
	for(int i = n - 2;  i >= 0; i--)
	{
		if(prices[i] > curHigh)
			curHigh = prices[i];
		
		if(curHigh - prices[i] > rMax)
		{
			rMax = curHigh - prices[i];
		}
		
		//the max profit in sub region [i,n]
		rightMaxProfit[i] = rMax;
	}
	
	int max = INT_MIN;
	for(int i = 0; i < n; i++)
	{
		int twoTransactionMax = leftMaxProfit[i] + rightMaxProfit[i];
		max = (max > twoTransactionMax)? max : twoTransactionMax;
	}
	return max;
}












































//optimized based on the implementation II, erase one iteration
int maxProfitII(vector<int> &prices) {
	if(prices.size() <= 1)
		return 0;
	
	int n = prices.size();
	vector<int> leftMaxProfit(n, 0);
	
	int curLow = prices[0];
	int lMax = INT_MIN;
	for(int i = 1; i < n; i++)
	{
		if(prices[i] < curLow)
			curLow = prices[i];
		
		if(prices[i] - curLow > lMax)
		{
			lMax = prices[i] - curLow;
		}
		
		//the max profit in sub region [0,i]
		leftMaxProfit[i] = lMax;
	}
	
	int curHigh = prices[n - 1];
	
	int max = leftMaxProfit[n - 1];
	
	int rMax = INT_MIN;
	for(int i = n - 2;  i >= 0; i--)
	{
		if(prices[i] > curHigh)
			curHigh = prices[i];
		
		if(curHigh - prices[i] > rMax)
		{
			rMax = curHigh - prices[i];
		}
		
		if(rMax + leftMaxProfit[i] > max)
			max = rMax + leftMaxProfit[i];
	}
	
	return max;
}	



int main()
{
}






