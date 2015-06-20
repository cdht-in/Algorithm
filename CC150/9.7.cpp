/*

A circus is designing a tower routine consisting of people standing atop one another’s shoulders. For practical and aesthetic reasons, each person must be both shorter and lighter than the person below him or her. Given the heights and weights of each person in the circus, write a method to compute the largest possible number of people in such a tower.

EXAMPLE:

Input (ht, wt): (65, 100) (70, 150) (56, 90) (75, 190) (60, 95) (68, 110)

Output: The longest tower is length 6 and includes from top to bottom: (56, 90) (60,95) (65,100) (68,110) (70,150) (75,190)

*/
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Person
{
	int height;
	int weight;
	
	Person(int h, int w):height(h), weight(w){}
};

int cmp(Person& a, Person& b)
{
	return a.height > b.height;
}

int LongestIncreasingSubsequenceDP(vector<Person>& seq)
{
	int n = seq.size();
    vector<int> dp(n,1);
	int max = 0;
	
	//i stands for the longest subsequence ends here
	for(int i = 1; i < n; i++)
	{
		for(int j = 0; j < i; j++)
		{
			//NOTE here is decreasing
			if(seq[i].weight < seq[j].weight && dp[i] < dp[j] + 1)
			{
				dp[i] = dp[j] + 1;
			}
		}
	}

    for (int i = 0; i < n; i++ )
   	{	
		if (max < dp[i])
		{
          	max = dp[i];
	  	}
  	}
	
	return max;
}

//O(n^2)
int TowerHeight(vector<Person>& vec)
{
	sort(vec.begin(),vec.end(),cmp);
	
	//this find the longest increasing sequence for the weight
	//O(n^2) dp, NOTE that this could be improved to nlogn, see ArrayLongestMonotonicallyIncreasingSubsequence.cpp
	return LongestIncreasingSubsequenceDP(vec);
}

int main()
{
	vector<Person> vec = {Person(65,100),Person(70,150),Person(56,90),Person(75,190),Person(60,95),Person(68,110)};
	
	cout << TowerHeight(vec) << endl;
}