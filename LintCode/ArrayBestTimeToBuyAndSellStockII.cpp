/*
	
Medium Best Time to Buy and Sell Stock II

51% Accepted
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

Have you met this question in a real interview? Yes
Example
Given an example [2,1,2,0,1], return 2
	
*/

#include "../commonHeader.h"

//greedy, sell as soon as make profit
int maxProfit(vector<int> &prices) 
{
	if(prices.size() <= 1)
		return 0;
	int lowPrice = prices[0];
	int maxProfit = 0;
	for(int i = 1; i < prices.size();i++)
	{
		if(prices[i] < prices[i - 1])
		{
			maxProfit += (prices[i - 1] - lowPrice);
			lowPrice = prices[i];
		}
	}
	maxProfit += (prices[prices.size() - 1] - lowPrice);
	
	return maxProfit;
}

int main()
{
	
	
}