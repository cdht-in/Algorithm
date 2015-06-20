/*

Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

  [
    ["aa","b"],
    ["a","a","b"]
  ]
	
*/

#include <vector>
#include <string>
#include <iostream>

using namespace std;

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
void partitionHelper(string& s,int start, vector<string>& partition, vector<vector<string> >& result)
{
	//reached the end
	if(start >= s.size())
	{
		result.push_back(partition);
		return;
	}
	
	for(int i = start + 1; i <= s.size(); i++)
	{
		//substr doesn't include i
		string substr = s.substr(start,i - start);
		if(IsPalindrome(substr) == true)
		{
			partition.push_back(substr);
			partitionHelper(s,i,partition,result);
			partition.pop_back();
		}
	}
}

vector<vector<string> > partition(string s) {
	vector<vector<string> > result;
	if(s.size() == 0){
		return result;
	}
	vector<string> partition;
	partitionHelper(s,0,partition,result);
	return result;
}






































void partitionIHelper(string& s, int start, int end, vector<vector<bool> >& isPal, vector<vector<string> >& result, vector<string>& palindrome)
{
	if(start > end)
	{
		result.push_back(palindrome);
		return;
	}
	
	for(int i = start; i <= end; i++)
	{
		if(isPal[start][i])
		{
			palindrome.push_back(s.substr(start,i - start + 1));
			partitionIHelper(s,i + 1, end,isPal,result,palindrome);
			palindrome.pop_back();
		}	
	}
}

//second implementation
vector<vector<string> > partitionI(string s) 
{
	vector<vector<string> > result;
	if(s.size() == 0)
		return result;
	
	//preprocess the palindrome matrix
	int n = s.size();
	vector<vector<bool> > isPal(n,vector<bool>(n,false));
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j <= i ; j++)
		{
			if(s[i] == s[j] && ((i - j <= 1) || isPal[j + 1][i - 1]))
			{
				isPal[j][i] = true;
			}			
		}
	}
	
	vector<string> palindrome;
	partitionIHelper(s,0,n - 1, isPal,result,palindrome);
	return result;
}


int main(){
	string s = "aab";
	vector<vector<string> > result = partitionI(s);
	for(int i = 0; i < result.size(); i++)
	{
		for(int j = 0; j < result[i].size(); j++)
		{
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
}