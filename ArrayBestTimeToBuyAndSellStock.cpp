/*
  Say you have an array for which the ith element is the price of a given stock on day i. If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
*/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

//O(n)
int FindStock (int* data, int size)
{
  //record what day the stock is cheapest
  int Lowest = 100;
  int LowestIndex = 0;
  int Highest = 0;
  int BestDeal = 0;
  for (int i = 0; i < size; i++) {
    if (data[i] < Lowest) {
      LowestIndex = i;
      Lowest = data[i];
    }
    if (data[i] - Lowest > BestDeal) {
      Highest = i;
      BestDeal = data[i] - Lowest;
    }
  }
  std::cout << "best deal is " << BestDeal << " at " << LowestIndex << " and " << Highest << std::endl;
  return BestDeal;
}

int maxProfit (vector<int>& prices)
{
  if (prices.size() <= 1)
    return 0;
  int max = 0;
  int buy = prices[0];
  for (int i = 1; i < prices.size(); i++) {
    if(prices[i] <= buy){
      buy = prices[i];
    }
    max = (max > (prices[i] - buy) ) ? max : (prices[i] - buy);
  }
  return max;
}

int maxProfit1 (vector<int>& prices)
{
	if(prices.size() < 2)
		return 0;
	int max = prices[prices.size() - 1];
	int maxProfit = INT_MIN;
	for(int i = prices.size() - 2 ; i >= 0; i--)
	{
		if(prices[i] >= max)
			max = prices[i];
		maxProfit = (max - prices[i] > maxProfit)? max - prices[i]: maxProfit;
	}
	return maxProfit;
}

int maxProfit(vector<int> &prices) {
	if(prices.size() <= 1)
		return 0;
	int curLow = prices[0];
	int max = INT_MIN;
	for(int i = 1; i < prices.size(); i++)
	{
		if(prices[i] <= curLow)
			curLow = prices[i];
		max = (prices[i] - curLow > max)? prices[i] - curLow : max;
	}
	return max;
}










































//third implementation
int maxProfitII(vector<int> &prices) {
	if(prices.size() < 2)
		return 0;
	int low = prices[0];
	int max = -1;
	for(int i = 1; i < prices.size(); i++)
	{
		if(prices[i] < low)
			low = prices[i];
		if(prices[i] - low > max)
			max = prices[i] - low;
	}
	return max;
}


int main()
{
  int foo[] = {2, 1, 2, 0, 1};
  vector<int> vec;
  for(int i = 0; i < sizeof(foo) / sizeof(int); i++)
	  vec.push_back(foo[i]);
  cout << maxProfit1 (vec) << endl;
}



