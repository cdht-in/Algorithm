#include <string>
#include <iostream>
#include <vector>

using namespace std;


//recursion to reverse the order O(m + n);
void PrintLCS(vector<vector<int> >& trace, string& s, int i, int j)
{
	if(i == 0 || j == 0)
		return;
	
	if(trace[i][j] == 0)
	{
		PrintLCS(trace,s,i - 1, j - 1);
		cout << s[i - 1] << " ";
	}
	else if (trace[i][j] == 1)
	{
		PrintLCS(trace,s,i - 1, j);
	}
	else
	{
		PrintLCS(trace,s,i, j - 1);
	}
}


int LCS(string s, string t)
{
	int m = s.size();
	int n = t.size();
	
	//the trace matrix could be completely removed
	vector<vector<int> > trace(m + 1, vector<int>(n + 1, 0));
	
	vector<vector<int> > dp(m + 1, vector<int>(n + 1, 0));
	
	for(int i = 1; i <= m; i++)
	{
		for(int j = 1; j <= n; j++)
		{
 			if(s[i - 1] == t[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
				trace[i][j] = 0;
			}
			else
			{
				if(dp[i - 1][j] >= dp[i][j - 1])
				{
					dp[i][j] = dp[i - 1][j];
					trace[i][j] = 1;
				}
				else
				{
					dp[i][j] = dp[i][j - 1];
					trace[i][j] = -1;
				}
			}
		}
	}
			
	//print the sequence
	PrintLCS(trace,s,m,n);	
	
	cout << endl;
			
	return dp[m][n];
}


//O(n) in space but wouldn't have enough information to print the sub-sequence
int LCSImproved(string s, string t)
{
	int m = s.size();
	int n = t.size();
	
	vector<int> dp(m + 1,0);
	
	for(int i = 1; i <= m; i++)
	{
		for(int j = n; j >= 1; j--)
		{
			//dp[i] have the value for previous row
			//and dp[j - 1] => dp[i - 1][j - 1] in the 2-D DP
 			if(s[i - 1] == t[n - j])
			{
				dp[i] = dp[i - 1] + 1;
			}
			else
			{
				if(dp[i] < dp[j])
				{
					dp[i] = dp[j + 1];
				}
			}
		}
	}
						
	return dp[m];
}

int main()
{
	/*
	string s = "ABCBDAB";
	string t = "BDCABA";
	*/
	
	string s = "BC";
	string t = "ABCD";
	
	cout << LCSImproved(s,t) << endl;
}