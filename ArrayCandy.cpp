/*
  There are N children standing in a line. Each child is assigned a rating value.

  You are giving candies to these children subjected to the following requirements:

  Each child must have at least one candy.
  Children with a higher rating get more candies than their neighbors.
  What is the minimum candies you must give?
*/

#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

//O(n^2)
int NofCandy (int* rate, int len)
{
  if (len < 1)
    return 0;
  if (len == 1)
    return 1;
  int candy[len];
  candy[0] = 1;
  for (int i = 1; i < len; i++) {
    //add one to keep the child with higher rate happy
    if (rate[i - 1] < rate[i] )
      candy[i] = candy[i - 1] + 1;
    //give as less as possible
    else {
      candy[i] = 1;
      //propogate to the first one that has lower rate
      for (int j = i; j - 1 >= 0; j--) {
        if (rate[j - 1] > rate[j] && candy[j - 1] == candy[j])
          candy[j - 1] += 1;
        else
          break;
      }
    }
  }
  int sum = 0;
  for (int i = 0; i < len; i++)
    sum += candy[i];
  return sum;
}

/*

There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?
	
*/

//O(n^2)
int candy(vector<int> &ratings) {
	if(ratings.size() < 1)
		return 0;
	if(ratings.size() == 1)
		return 1;
	int n = ratings.size();
	vector<int> numberOfCandies(n,0);
	//give the first child 1 candy
	numberOfCandies[0] = 1;
	for(int i = 1; i < n; i++)
	{
		int j = i;
		if(ratings[j] >= ratings[j - 1])
		{
			numberOfCandies[j] = numberOfCandies[j - 1] + 1;
			continue;
		}
		numberOfCandies[j] = 1;
		//update all prior number of candies
		while(j >= 0 && ratings[j - 1] > ratings[j])
		{
			numberOfCandies[j - 1] = numberOfCandies[j] + 1;
			j--;
		}
	}
		
	int totalCandies = 0;
	for(int i = 0; i < n; i++)
	{
		cout << numberOfCandies[i] << endl;
		totalCandies += numberOfCandies[i];
	}	

	return totalCandies;
}

//DP O(n)
int candyI(vector<int>& ratings)
{
	if(ratings.size() < 1)
		return 0;
	if(ratings.size() == 1)
		return 1;
	int n = ratings.size();
	//each child is given 1 candy
	vector<int> numberOfCandies(n,1);
	//take care of the increasing ratings
	for(int i = 1; i < n; i++)
	{
		if(ratings[i] > ratings[i - 1])
			numberOfCandies[i] = numberOfCandies[i - 1] + 1; 
	}
	
	for(int i = n - 2; i >= 0; i--)
	{
		if(ratings[i] > ratings[i + 1] && numberOfCandies[i] <= numberOfCandies[i + 1])
			numberOfCandies[i] = numberOfCandies[i + 1] + 1; 
	}
	
	int total = 0;
	for(int i = 0; i < n; i++)
	{
		total += numberOfCandies[i];
	}
	return total;
	
}


int main()
{
	
  int rate[] = {2,2,1};  
  vector<int> foo(rate, rate + sizeof(rate) / sizeof(int));
  cout << candy(foo) << endl;
}