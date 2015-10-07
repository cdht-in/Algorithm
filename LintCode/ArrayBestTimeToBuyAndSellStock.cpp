/*
	
Medium Best Time to Buy and Sell Stock

41% Accepted
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Have you met this question in a real interview? Yes
Example
Given an example [3,2,3,1,2], return 1
	
*/

#include "../commonHeader.h"

int maxProfit(vector<int> &prices) 
{
	if(prices.size() <= 1)
		return 0;
	
	int lowPrice = prices[0];
	int maxProfit = 0;
	
	for(int i = 1; i < prices.size(); i++)
	{
		lowPrice = std::min(lowPrice,prices[i]);
		
		maxProfit = std::max(maxProfit,prices[i] - lowPrice);
	}
	
	return maxProfit;
}

int main()
{
	
	
}