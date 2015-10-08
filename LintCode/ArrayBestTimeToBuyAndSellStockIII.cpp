/*

Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Have you met this question in a real interview? Yes
Example
Given an example [4,4,6,1,1,4,2,5], return 6.

Note
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
	
*/

#include "../commonHeader.h"

int RegionalMax(vector<int> &prices,int l,int r)
{
	if(l > r)
		return 0;
	
	int lowPrice = prices[l];
	int maxProfit = 0;
	
	for(int i = l + 1; i <= r; i++)
	{
		if(lowPrice >= prices[i])
		{
			lowPrice = prices[i];
		}
		
		if(maxProfit < prices[i] - lowPrice)
		{
			maxProfit = prices[i] - lowPrice;
		}
	}
	
	return maxProfit;
}

//maximum k transaction
int maxProfit(vector<int> &prices,int k)
{
	int n = prices.size();
	
	//this records the maximum profit out of k transactions
	vector<vector<vector<int> > > kMax(k + 1,vector<vector<int> >(n,vector<int>(n,-1)));
	
	int maxProfit = 0;
	for(int kIndex = 1; kIndex <= k; kIndex++)
	{
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j <= i; j++)
			{
				if(kIndex == 1)
				{
					kMax[kIndex][j][i] = RegionalMax(prices,j,i);
					maxProfit = std::max(maxProfit,kMax[kIndex][j][i]);
					continue;
				}
				
				if(j + 1 < n)
				{
					kMax[kIndex][0][i] = std::max(kMax[kIndex][0][i],kMax[kIndex - 1][0][j] + kMax[1][j + 1][i]);
					maxProfit = std::max(maxProfit,kMax[kIndex][0][i]);
				}
			}
		}
	}
	
	//so the maximum profit at most k transaction
	return maxProfit;
}

int maxProfit(vector<int> &prices) 
{
	return maxProfit(prices,2);
}

//
int maxProfitI(vector<int> &prices)
{
	if(prices.size() <= 1)
		return;
	
	int maxProfit = 0;
	int n = prices.size();
	
	vector<int> regionMaxI(n,0);
	
	vector<int> regionMaxII(n,0);
	
	int lowPrice = prices[0];
	
	for(int i = 1; i < n; i++)
	{
		if(lowPrice >= prices[i])
		{
			lowPrice = prices[i];
		}
	
		if(maxProfit < prices[i] - lowPrice)
		{
			maxProfit = prices[i] - lowPrice;
		}
		
		regionMaxI[i] = maxProfit;
	}
	
	maxProfit = 0;	
	int highPrice = prices[n - 1];
	
	int max = 0;
	for(int i = n - 2; i >= 0; i--)
	{
		if(highPrice < prices[i])
		{
			highPrice = prices[i];
		}
	
		if(maxProfit < highPrice - prices[i])
		{
			maxProfit = highPrice - prices[i];
		}
		
		if(i + 1 < n)
		{
			max = std::max(max,regionMaxI[i] + maxProfit);
		}
		else
		{
			max = std::max(max,regionMaxI[n - 1]);
		}
	}
	return max;
}


int main()
{
	vector<int> prices = {4,4,6,1,1,4,2,5};
	cout << maxProfit(prices) << endl;
	
}