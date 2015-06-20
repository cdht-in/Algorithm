/*
  You are given a string, S, and a list of words, L, that are all of the same length. Find all starting indices of substring(s) in S that is a concatenation of each word in L exactly once and without any intervening characters.

  For example, given:
  S: "barfoothefoobarman"
  L: ["foo", "bar"]

  You should return the indices: [0,9].
  (order does not matter).
*/

#include <vector>
#include <string>
#include <iostream>
#include <unordered_set>
#include <unordered_map>

using namespace std;

/*
  unordered_set<string> set;

  void swap (string& s1, string& s2)
  {
  string tmp = s2;
  s2 = s1;
  s1 = tmp;
  }

  void concat (vector<string>& L, int index, vector<int>& container, string& S)
  {
  if (index >= L.size() ) {
  string s = "";
  for (int i = 0; i < L.size(); i++)
  s += L[i];
  if (set.find (s) == set.end() ) {
  set.insert (s);
  size_t found = S.find (s);
  while (found != string::npos) {
  container.push_back (found);
  found = S.find (s, found + 1);
  }
  }
  return;
  }
  for (int i = index; i < L.size(); i++) {
  swap (L[index], L[i]);
  concat (L, index + 1, container, S);
  swap (L[index], L[i]);
  }
  }
  //naive approach, generate all combinations and check if S has it. O(n!)
  vector<int> findSubstring1 (string S, vector<string>& L)
  {
  vector<int> ret;
  concat (L, 0, ret, S);
  return ret;
  }

*/

vector<int> findSubstring (string S, vector<string>& L)
{
  unordered_map<string, int> map;
  for (int i = 0; i < L.size(); i++) {
    if (map.find (L[i]) == map.end() )
      map[L[i]]++;
  }
  int len = L[0].size();
  int substr = len * L.size();
  vector<int> ret;
  //NOTE here, if copy the entire hashmap, it would generate a lot of overheads.
  for (int i = 0; i <= (int) S.size() - substr; i++) {
    unordered_map<string, int> tmpmap;
    int j = i;
    for (; j < i + substr; j += len) {
      string s = S.substr (j, len);
      if (map.find (s) != map.end() ) {
        tmpmap[s]++;
        if (tmpmap[s] > map[s])
          break;
      }
      else
        break;
    }
    if (j == i + substr)
      ret.push_back (i);
  }
  return ret;
}

int main()
{
  vector<string> L;
  L.push_back ("a");
  string S = "a";
  vector<int> ret = findSubstring (S, L);
  for (int i = 0; i < ret.size(); i++) {
    cout << ret[i] << " ";
  }
  cout << endl;
}
