/*
  Given an array of strings, return all groups of strings that are anagrams.
  Note: All inputs will be in lower-case.
*/

#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<string> anagrams (vector<string>& strs)
{
  unordered_map<string, vector<string> > map;
  string tmp = "";
  for (int i = 0; i < strs.size(); i++) {
    tmp = strs[i];
    sort (tmp.begin(), tmp.end() );
    if (map.find (tmp) == map.end() )
      map[tmp] = vector<string>();
    map[tmp].push_back (strs[i]);
  }
  vector<string> ret;
  for (unordered_map<string, vector<string> >::iterator it = map.begin(); it != map.end(); ++it) {
    if (it->second.size() > 1){
      for(int i = 0; i < it->second.size(); i++)
	ret.push_back(it->second[i]);
    }
  }
  return ret;
}

int main()
{
}
