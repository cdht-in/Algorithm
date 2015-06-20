
/*Say you have an array for which the ith element is the price of a given stock on day i.

  Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).*

*/

//tranformable to activity allocation problem, greedy approach O(nlog(n))

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


int FindStock (const int* data, int a, int b)
{
  if (a >= b)
    return 0;
  int Lowest = 100;
  int BestDeal = 0;
  int Highest = 0;
  for (int i = a; i <= b; i++) {
    if (data[i] < Lowest)
      Lowest = data[i];
    if (data[i] - Lowest > BestDeal) {
      BestDeal = data[i] - Lowest;
      Highest = i;
    }
  }
  cout << "buying at " << Lowest << " selling at " << Highest << endl;
  return BestDeal + FindStock (data, Highest + 1, b);
}

int maxProfit(vector<int> &prices) {
  if(prices.size() <= 1)
    return 0;
  int max = 0;
  int buy = prices[0];
  int sell = prices[0];
  for(int i = 0; i < prices.size(); i++){
    if(prices[i] >= sell)
      sell = prices[i];
    else{
      //find the current best deal
      max += (sell - buy);
      buy = prices[i];
      sell = prices[i];
    }
  }
  max += (sell - buy);
  return max;   
}

int maxProfit(vector<int> &prices) {
	//every time the prices falls, sell it
	if(prices.size() <= 1)
	{
		return 0;
	}
	int curMin = prices[0];
	int curMax = prices[0];
	int max = 0;
	int localMax = 0;
	for(int i = 1; i < prices.size(); i++)
	{
		if(prices[i] >= curMax)
		{
			curMax = prices[i];
			int profit = curMax - curMin;
			localMax = (profit > localMax)?  profit : localMax;
		}
		//price falls
		else
		{
			max += localMax;
			localMax = 0;
			curMin = prices[i];
			curMax = prices[i];
		}
	}
	max += localMax;
	return max;
}


int main()
{
  int foo[] = {1, 2, 8, 2, 4};
  cout << "max profit is " << FindStock (foo, 0, sizeof (foo) / sizeof (int) - 1) << endl;
}

