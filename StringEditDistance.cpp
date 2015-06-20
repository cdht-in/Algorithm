/*
  Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

  You have the following 3 operations permitted on a word:

  a) Insert a character
  b) Delete a character
  c) Replace a character
*/
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


/*

The optimal function is:  table[i+1][j+1] = min [table[i][j]+1 or 0 (+1 if word1[i+1]==word2[j+1], else +0),   table[i][j+1]+1, table[i+1][j]+1 ].

Initialization:
table[0][i] = i  i=1:|word1|          here 0 means "", any string convert to "" needs the length of string
table[j][0] = j  i=1:|word2|
table[0][0]=0    "" convert to  "" need 0 steps.

 */
/* 
first implementation

int minDistance (string word1, string word2)
{
  int s1 = word1.size();
  int s2 = word2.size();
  if (s1 == 0) {
    return s2;
  }
  if (s2 == 0) {
    return s1;
  }
  vector<vector<int> > w (s1 + 1, vector<int> (s2 + 1, 0) );
  for (int i = 0; i <= s1; i++) {
    w[i][0] = i;
  }
  for (int i = 0; i <= s2; i++) {
    w[0][i] = i;
  }
  for (int i = 1; i <= s1; i++) {
    for (int j = 1; j <= s2; j++) {
      //add or delete
      w[i][j] = min (w[i - 1][j] + 1, w[i][j - 1] + 1);
      if (word1[i - 1] == word2[j - 1]) 
        w[i][j] = min (w[i - 1][j - 1], w[i][j]);
      //replace
      else 
        w[i][j] = min (w[i - 1][j - 1] + 1, w[i][j]);
    }
  }
  return w[s1][s2];
}

*/

//second implementation

int minDistance(string word1, string word2) {
	int m = word1.size();
	int n = word2.size();
	
	vector<vector<int> > dp(m + 1,vector<int>(n + 1,0));
	dp[0][0] = 0;
	
	for(int i = 1; i <= n; i++)
	{
		dp[0][i] = i;
	}
	for(int i = 1; i <= m; i++)
	{
		dp[i][0] = i;
	}

	for(int i = 1; i <= m; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			int nChange = 0;
			if(word1[i - 1] != word2[j - 1])
				nChange = 1;
			//the mininum change = min(nChange,nInsert,nDelete)
			nChange = dp[i - 1][j - 1] + nChange;
			int nInsert = dp[i][j - 1] + 1;
			int nDelete = dp[i - 1][j] + 1;
			int min = (nInsert < nDelete)?nInsert:nDelete;
			
			min = (min < nChange)? min : nChange;
			dp[i][j] = min;
		}
	}
	
	return dp[m][n];
}











































//thid implementation


int minDistanceI(string word1, string word2) {
	int m = word1.size();
	int n = word2.size();
	
	vector<vector<int> > dp(m + 1, vector<int>(n + 1, 0));
	
	//convert empty to word2
	for(int i = 0; i <= n; i++)
	{
		dp[0][i] = i;
	}
	
	//convert word 1 to empty
	for(int i = 0; i <= m; i++)
	{
		dp[i][0] = i;
	}
	
	for(int i = 1; i <= m; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			int nChange = 0;
			if(word1[i - 1] == word2[j - 1])
			{
				nChange = dp[i - 1][j - 1];
			}
			else
			{
				nChange = dp[i - 1][j - 1] + 1;
			}
			
			int nDelete = dp[i][j - 1] + 1;
			
			int nInsert = dp[i - 1][j] + 1;
			
			int min = (nChange < nDelete)? nChange : nDelete;
			min = (min < nInsert)? min : nInsert;
			
			dp[i][j] = min;
			
		}
	}
	return dp[m][n];
	
}




int main()
{
  string s1 = "a";
  string s2 = "b";
  cout << minDistance (s1, s2) << endl;
}
