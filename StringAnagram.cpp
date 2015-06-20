/*
  1.generate all the anagram of a string
  2.test if two string are anagram of each other
 */
#include <vector>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <stack>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <map>

using namespace std;

/*

first implementation

int Compare (const void* a, const void* b)
{
  return * ( (char*) a) > * ( (char*) b);
}

bool isAnagram (char* a, int alen, char* b, int blen)
{
  qsort (a,  alen, sizeof (char), Compare);
  qsort (b,  blen, sizeof (char), Compare);
  printf ("%s\n", a);
  printf ("%s\n", b);
  if (strcmp (a, b) == 0)
    return true;
  return false;
}

//permutation in this case
void GenerateAnagrams (std::string s, std::vector<char>& vec)
{
  if (s == "") {
    //print stack
    for (int i = 0; i < vec.size(); i++)
      printf ("%c ", vec[i]);
    printf ("\n");
  }
  for (int i = 0; i < s.size(); i++) {
    vec.push_back (s[i]);
    GenerateAnagrams (s.substr (0, i) + s.substr (i + 1), vec);
    vec.pop_back();
  }
}

//push anagrams into a tree
void anagrams (vector<string>& strs)
{
  unordered_map<string, vector<string> > map;
  for (int i = 0; i < strs.size(); i++) {
    string s = strs[i];
    sort (s.begin(), s.end() );
    if (map.find (s) == map.end() )
      map[strs[i]] = vector<string>();
    else
      map[strs[i]].push_back (s);
  }
  
}

*/

//second implementation

//O(n^2 * log(n))
vector<string> anagrams(vector<string> &strs) {
	vector<string> result;
	if(strs.size() == 0)
	{
		return result;
	}
	
	map<string,vector<string> > map;
	for(int i = 0; i < strs.size(); i++)
	{
		string str = strs[i];
		sort(str.begin(),str.end());
		if(map.find(str) == map.end())
		{
			vector<string> anagrams;
			anagrams.push_back(strs[i]);
			map[str] = anagrams;
		}
		else
		{
			map[str].push_back(strs[i]);
		}
	}
	
	for(auto it = map.begin() ; it != map.end(); it++)
	{
		if(it->second.size() > 1)
		{
			for(int i = 0; i < it->second.size(); i++)
			{
				result.push_back(it->second[i]);
			}
		}
	}
	return result;
}

int main()
{
  vector<string> strs;
  strs.push_back ("abc");
  strs.push_back ( "cba");
  strs.push_back ( "acb");
  strs.push_back ( "de" );
  strs.push_back ( "ed" );
  
}
