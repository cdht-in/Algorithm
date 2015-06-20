/*
  Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

  For example, given
  s = "leetcode",
  dict = ["leet", "code"].

  Return true because "leetcode" can be segmented as "leet code".
*/


#include <string>
#include <unordered_set>
#include <iostream>
#include <vector>

using namespace std;



//idea is to divide the string by whitespace and if each recurisve call return true, then return true
//O(n)

/*

bool WordBreak (string s)
{
  //if there are empty string
  if (s.size() < 1)
    return true;
  for (int i = 0; i <= s.size(); i++) {
    if (set.find (s.substr (0, i) ) != set.end() )
      //if all of the substrings return true, return true
      return true && WordBreak (s.substr (i) );
  }
  //if can't find a word from this substring, return false
  return false;
}


bool wordBreak(string s, unordered_set<string> &dict) {
	if(s.size() < 1)
		return false;
	int n = s.size() + 1;
	vector<bool> breakable(n, false);
	breakable[0] = true;
	
	for(int i = 1; i < n; i++)
	{
		for(int j = 0; j < i; j++)
		{
			string substr = s.substr(j,i - j);
			if(breakable[j] && dict.find(substr) != dict.end())
				breakable[i] = true;
			//find a breakable substring in [j , i]
			if(breakable[i] == true)
				break;
		}
	}
	return breakable[s.size()];
}
*/

































//second implementation
//brute force,
bool wordBreakHelper(string& s, int start, unordered_set<string> &dict)
{
	if(start >= s.size())
		return true;
	
	for(int i = start + 1; i <= s.size(); i++)
	{
		string substr = s.substr(start, i - start);
		if(dict.find(substr) != dict.end())
		{
			int result = wordBreakHelper(s,i,dict);
			if(result == true)
				return true;		
		}
	}
	return false;
}

bool wordBreak(string s, unordered_set<string> &dict) 
{
	return wordBreakHelper(s,0,dict);
}

//DP
bool wordBreakDP(string s, unordered_set<string> &dict) 
{
	if(s.size() == 0)
		return true;
	int n = s.size();
	vector<bool> breakable(n + 1,false);
	breakable[0] = true;
	
	for(int i = 1; i <= n; i++)
	{
		for(int j = 0; j <= i; j++)
		{
			string substr = s.substr(j,i - j);
			if(breakable[j] && dict.find(substr) != dict.end())
			{
				breakable[i] = true;
				break;
			}
		}
	}
	return breakable[n];
}

int main()
{
  unordered_set<string> set;	
  set.insert ("a");
  set.insert ("b");
  string s = "aaaaaaa";
  cout << wordBreakDP (s,set) << endl;
}
