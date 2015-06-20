

/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
*/

#include <vector>
#include <string>
#include <iostream>
#include <climits>

using namespace std;

/* this would work, but it would exceed the time limit on leetcode 

bool IsPalindrome(string& s)
{
	if(s.size() == 0)
		return false;
	if(s.size() == 1)
		return true;
	int n = s.size() / 2;
	for(int i = 0; i < n; i++)
	{
		if(s[i] != s[s.size() - 1 - i])
			return false;
	}
	return true;
}

//DFS O(n * 2^n)
void partitionHelper(string& s,int start, vector<string>& partition,vector<vector<string> >& substrs,int& minCut)
{
	//reached the end
	if(start >= s.size())
	{
		int nCut = partition.size() - 1;
		if(nCut < minCut)
			minCut = nCut;
		return;
	}
	
	for(int i = start + 1; i <= s.size(); i++)
	{
		//substr doesn't include i
		
		string substr = substrs[start][i];
		//s.substr(start,i - start);
		if(IsPalindrome(substr) == true)
		{
			partition.push_back(substr);
			partitionHelper(s,i,partition,substrs,minCut);
			partition.pop_back();
		}
	}
}

int minCut(string s) {
	if(s.size() == 0){
		return 0;
	}
	
	vector<string> partition;
	
	//optimize the subtrings
	vector<vector<string> > substrs;
	for(int i = 0; i <= s.size(); i++)
	{
		substrs.push_back(vector<string>()); 
		for(int j = 0; j <= s.size(); j++)
		{
			string substr = s.substr(i, j - i);
			substrs[i].push_back(substr);
		}
	}
	
	int minCut = INT_MAX;
	partitionHelper(s,0,partition,substrs,minCut);
	return minCut;

}

*/

int Min(int a, int b)
{
	return (a < b)? a : b;
}

int minCut(string s) {
	int n = s.size();
	vector<int> nCut;
	//in the worst case, each char could be divided to form a palindrome, so the minimum cut for len == n is n - 1;
	for(int i = 0; i <= n; i++)
	{
		nCut.push_back(i - 1);
	}
	//the outer loop is to maintain the minimum cut to s.size()
	for(int i = 0; i <= n; i++)
	{
		
		//odd number palindrome, i is the center and expand from the center to both sides
		for(int j = 0; i - j >= 0 && i + j < n && s[i - j] == s[i + j]; j++)
		{
			//here nCut[i - j] is the minimum number of cuts for the substr len = i - j
			nCut[i + j + 1] = Min(nCut[i + j + 1], 1 + nCut[i - j]);
		}
		
		//even number palindrome, i is the center and expand from the center to both sides
		for(int j = 1; i - j + 1 >= 0 && i + j < n && s[i - j + 1] == s[i + j]; j++)
		{
			nCut[i + j + 1] = Min(nCut[i + j + 1], 1 + nCut[i - j + 1]);
		}
	}
	
	return nCut[n];
}









































//second implementation
//http://www.acmerblog.com/palindrome-partitioning-ii-6148.html
int minCutI(string s) 
{
	int n = s.size();
	vector<vector<bool> > palindromeDP(n, vector<bool>(n,false));
	vector<int> mCuts(n,0);
	
	for(int i = 0; i < n; i++)
	{
		//the maximum cut length i requires
		mCuts[i] = i;
		for(int j = 0; j <= i; j++)
		{
			//if the region [j,i] is a palindrome with the help of memorization
			if(s[i] == s[j] && ((i - j <= 1) || palindromeDP[j + 1][i - 1]) == true)
			{
				palindromeDP[j][i] = true;
				//thus the length i could be divide into region [0, j - 1] and [j, i]
				//the number of cuts is mCuts[j - 1] plus one cut
				
				if(j > 0)	
				{
					mCuts[i] = (mCuts[i] < mCuts[j - 1] + 1)? mCuts[i] : mCuts[j - 1] + 1;
				}
				//if j == 0, that means region [0,i] is a palindrome and doesn't require a cut
				else{
					mCuts[i] = 0;
				}
			}
		}
		
	}
	
	return mCuts[n - 1];
}


int main(){
	string s = "aab";
	cout << minCutI(s) << endl;
}