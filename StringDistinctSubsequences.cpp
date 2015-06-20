/*
  Given a string S and a string T, count the number of distinct subsequences of T in S.

  A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

  Here is an example:
  S = "rabbbit", T = "rabbit"

  Return 3.
*/

//NOTE that the wording of the question is way off, 

#include <iostream>
#include <unordered_set>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

int nDistinctSubsequence1 (char* s)
{
  int n = strlen (s);
  int* dp = new int[n];
  //empty set has 1 subset
  dp[0] = 1;
  char last[256];
  //record which position this char occured in
  for (int i = 0; i < 256; i++) {
    last[i] = 0;
  }
  //start with a set with 1 element in it
  for (int i = 1; i <= n; i++) {
    //if all elements in the set were distinct,its power set would be 2^n
    dp[i] = (dp[i - 1] * 2);
    //if this char occured before, that means that the real number of distinct number would be 2^n - # subset this char generated, which happens to be the # of distinct subsets before this char, NOTE: the dp array is recursively built up
    if (last[s[i]] != 0)
      dp[i] -= dp[last[s[i]] - 1];
    //update its last seen position
    last[s[i]] = i;
  }
  int distinct = dp[n];
  delete[] dp;
  return distinct;
}


//second implementation

int numDistinct(string S, string T) {
   
   
	/*
	if(T.size() == 0)
		return 1;
   
	if(S.size() == 0)
		return (T.size() == 0)? 1 : 0;
	
	int c = 0;
	
	for(int i = 0; i < S.size(); i++)
	{
		if(S[i] == T[0])
		{
			c += numDistinct(S.substr(i + 1),T.substr(1));
		}
		//skipping those words is same as deleting some words in S
	}
	return c;
	*/
	
	
 
	int match[200];  
   if(S.size() < T.size())
	 return 0;  
   match[0] = 1;  
   for(int i=1; i <= T.size(); i++)  
     match[i] = 0;
	  
   for(int i=1; i<= S.size(); i ++)  
      for(int j =T.size(); j>=1; j--)  
		//this traverse the top right half of the dp rectangle, match[j] have the dp[i - 1][j] from the previous state  
        if(S[i-1] == T[j-1])  
          match[j]+= match[j-1];
	  
    return match[T.size()];    
	
}


/*
设母串的长度为 j，  
子串的长度为 i，我们要求的就是长度为 i 的字串在长度为 j 的母串中出现的次数，设为 t[i][j]，若母串的最后一个字符与子串的最后一个字符不同，则长度为 i 的子串在长度为 j 的母串中出现的次数就是母串的前 j - 1 个字符中子串出现的次数，即 t[i][j] = t[i][j - 1]，若母串的最后一个字符与子串的最后一个字符相同，那么除了前 j - 1 个字符出现字串的次数外，还要加上子串的前 i - 1 个字符在母串的前 j - 1 个字符中出现的次数
*/
int numDistinctI(string S, string T) {
	if(S.size() < T.size())
	{
		return 0;
	}
	
	int m = S.size();
	int n = T.size();
	
	vector<vector<int> > dp(n + 1, vector<int>(m + 1,0));
	
	//when T is empty, there is only one subsequence of S that is equal to T, e.g. removing all characters
	for(int i = 0; i <= m; i++)
		dp[0][i] = 1;
	
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			if(T[i - 1] == S[j - 1])
			{
				dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1]; 
			}
			else
			{
				dp[i][j] = dp[i][j - 1];
			}
		}
	}
	
	return dp[n][m];
	
}









































//third implementation
int numDistinctII(string S, string T) 
{
	if(S.size() < T.size())
		return 0;
	
	int m = S.size();
	int n = T.size();
	
	vector<vector<int> > dp(m + 1, vector<int>(n + 1,0));
	
	for(int i = 0; i <= m; i++)
		dp[i][0] = 1;
	
	for(int i = 1; i <= m; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			int prev = 0;
			if(S[i - 1] == T[j - 1])
				prev = dp[i - 1][j - 1];
			//ifS[i - 1] != T[j - 1]), then deleting S[i - 1] has no effect
			dp[i][j] = dp[i - 1][j] + prev;
		}
	}
	
	return dp[m][n];
}


int main()
{
	string S = "rabbbit";
	string T = "rabbit";
	cout << numDistinctI(S,T) << endl;
}


