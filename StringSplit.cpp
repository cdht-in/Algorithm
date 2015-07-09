/*
	
	split on white spaces except when string is in quote
	
*/

#include <string>
#include <iostream>
#include <vector>

using namespace std;

vector<string> Split(string& s)
{
	vector<string> ret;	
	int l = 0, r = 0;
	while(r <= s.size())
	{
		while(r < s.size() && s[r] != ' ')
		{
			if(s[r] == '"')
			{
				while(r < s.size())
				{
					if(s[++r] == '"')
						break;
				}
				
				if(r == s.size())
					throw "invalid string";
			}
			r++;
		}
		
		ret.push_back(s.substr(l,r - l));
		l = ++r;
	}
	
	return ret;
}

int main()
{
	string s = "haha \"what a fuck\" what a fuck";
	vector<string> ret = Split(s);
	for(int i = 0; i < ret.size(); i++)
	{
		cout << ret[i] << endl;
	}
}