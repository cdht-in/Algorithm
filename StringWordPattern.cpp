/*
	
Given a pattern and a string str, find if str follows the same pattern.

Examples:
pattern = "abba", str = "dog cat cat dog" should return true.
pattern = "abba", str = "dog cat cat fish" should return false.
pattern = "aaaa", str = "dog cat cat dog" should return false.
pattern = "abba", str = "dog dog dog dog" should return false.
Notes:
Both pattern and str contains only lowercase alphabetical letters.
Both pattern and str do not have leading or trailing spaces.
Each word in str is separated by a single space.
Each letter in pattern must map to a word with length that is at least 1.
	
*/

#include "./commonHeader.h"

bool wordPattern(string pattern, string str) 
{
	int c = 0;
	for(int i = 0; i < str.size(); i++)
	{
		if(str[i] == ' ')
		{
			c++;
		}
	}
	
	//one word in str
	if(c == 0)
	{
		return (pattern.size() == 1)? true : false;
	}
	
	if(pattern.size() != c + 1)
	{
		return false;
	}
	
	unordered_map<char,string> map;
	unordered_set<string> set;
	
	int l = 0, r = 0, p = 0;
	
	while(p < pattern.size())
	{
		while(r < str.size() && str[r] != ' ')
		{
			r++;
		}
		
		//not 1 to 1 mapping
		/*
		if((r == str.size() && p != pattern.size() - 1) || (p == pattern.size() - 1 && r != str.size()))
		{
			return false;
		}
		*/
		
		string substr = str.substr(l, r - l);
		if(map.find(pattern[p]) == map.end())
		{
			//has been mapped
			if(set.find(substr) != set.end())
			{
				return false;
			}
			
			map[pattern[p]] = substr;
			set.insert(substr);
		}
		else
		{
			if(map[pattern[p]] != substr)
			{
				cout << "!" << endl;
				return false;
			}
		}
		
		r++;
		l = r;
		p++;
	}
	
	return true;
}


int main()
{
	string pattern = "abba";
	string str = "dog cat cat dog";
	cout << wordPattern(pattern,str) << endl;
}