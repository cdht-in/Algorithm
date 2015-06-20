/*
Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"].
 */
#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>
#include <algorithm>


using namespace std;

unordered_set<string> set;

//O(n^2)
void WordBreakII (string s, string sen, vector<string>& vec)
{
  //<= s.size() is necessary to include the end of string chracter
  for (int i = 0; i <= s.size(); i++) {
    //in the dict
    string word = s.substr (0, i);
    if (set.find (word ) != set.end() ) {
      sen += word + " ";
      //the rest of the string
      string rest = s.substr (i);
      if (rest.size() > 1)
        WordBreakII (rest, sen, vec);
      else
        vec.push_back (sen);
      //like stack, pop the previous one, add one to skip the whitespace
      sen = sen.erase(0,sen.find(' ') + 1);
    }
  }
}


//DFS to enumerate all possibilities
void wordBreakIHelper(vector<string>& vec, int start, string& localString, string& s, unordered_set<string> &dict){
	if(start >= s.size())
	{
		//remove the last space
		localString.erase(localString.size() - 1,1);
		vec.push_back(localString);
		return;
	}
	for(int i = start + 1; i <= s.size(); i++)
	{
		//search the left half for a possible word
		string substr = s.substr(start, i - start );
		if(dict.find(substr) != dict.end())
		{
			int pos = localString.size();
			
			localString += substr + " ";
			
			//recursively search the rest
			wordBreakIHelper(vec,i,localString,s,dict);
		
			//clean up the localString for next available combination
			localString.erase(pos,substr.size() + 1);
		}
	}
}

//brute force
vector<string> wordBreakI(string s, unordered_set<string> &dict) {
	vector<string> result;
	if(s.size() < 1)
		return result;
	
	//test if the string is breakable
	vector<bool> breakable(s.size() + 1,false);
	//empty string is breakable
	breakable[0] = true;
	for(int i = 1; i < s.size() + 1; i++)
	{
		for(int j = 0; j < i; j++){
			breakable[i] = breakable[j] && (dict.find(s.substr(j,i - j)) != dict.end());
			if(breakable[i] == true)
				break;
		}
	}
	
	//unbreakable
	if(breakable[s.size()] == false)
		return result;
	
	string localString = "";
	wordBreakIHelper(result,0,localString,s,dict);
	return result;
	
}


























void wordBreakHelper(string& s, int start, unordered_set<string> &dict,vector<string>& paths,string& path)
{
	if(start >= s.size())
	{
		path.erase(path.size() - 1,1);
		paths.push_back(path);
		return;
	}

	for(int i = start + 1; i <= s.size(); i++)
	{
		string substr = s.substr(start, i - start);
		
		if(dict.find(substr) != dict.end())
		{
			int pos = path.size();

			path += substr + " ";
			
			wordBreakHelper(s,i,dict,paths,path);
			
			path.erase(pos, substr.size() + 1);
		}
	}
}

vector<string> wordBreak(string s, unordered_set<string> &dict) 
{
	
	vector<string> paths;
	
	if(s.size() < 1)
		return paths;
	
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
	if(breakable[n] == false){
		return paths;
	}
	
	string path = "";
	wordBreakHelper(s,0,dict,paths,path);
	return paths;
}














//second implementation


int main()
{
  set.insert ("a");
 
  string s = "a";
  
  vector<string> vec = wordBreak(s,set);
  
  for (int i = 0; i < vec.size(); i++) {
    cout << vec[i] << endl;
  }
}
