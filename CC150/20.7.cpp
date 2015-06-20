/*

	Write a program to find the longest word made of other words.

*/
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

int cmp(string& s1, string s2)
{
	return s1.size() > s2.size();
}

//O(n^2) at worst
bool isConcat(string& s,int start, int end,unordered_set<string>& set)
{
	if(start > end)
		return true;
	for(int i = start; i <= end; i++)
	{
		string substr = s.substr(start, i - start + 1);
		
		if(set.find(substr) != set.end())
		{	
			if(isConcat(s,i + 1,end,set))
				return true;
		}
	}
	
	return false;
}

//O(nlogn + n + n^2)
string FindWord(string* s,int n)
{
	sort(s,s + n,cmp);
	unordered_set<string> set;
	
	for(int i = 0; i < n; i++)
	{
		//cout << s[i] << endl;
		set.insert(s[i]);
	}
	
	for(int i = 0; i < n; i++)
	{
		set.erase(s[i]);
		
		if(isConcat(s[i],0,s[i].size() - 1, set))
			return s[i];
		
		set.insert(s[i]);
	}
	
	return "";
}

int main()
{
	int n = 13;
	string s[] = {"test", "tester", "testertest", "testing", 
	            "apple", "seattle", "banana",  "batting", "ngcat", 
	            "batti","bat", "testingtester", "testbattingcat"};
	

	cout << FindWord(s,n) << endl;
	
}