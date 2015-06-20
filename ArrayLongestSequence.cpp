/*
  Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

  For example,
  Given [100, 4, 200, 1, 3, 2],
  The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

  Your algorithm should run in O(n) complexity.
*/

#include <cstdio>
#include <unordered_set>
#include <unordered_map>
#include <vector>

using namespace std;

int longestConsecutive (vector<int>& num)
{
  // Start typing your C/C++ solution below
  // DO NOT write int main() function
  unordered_map<int, bool>mp;
  for (int i = 0; i < num.size(); i++) {
    mp[num[i]] = true;
  }
  int res = 0;
  for (int i = 0; i < num.size(); i++) {
    int mx = 1;
    int fd = num[i];
    mp.erase (num[i]);
    while (mp.find (fd + 1) != mp.end() ) {
      mx++;
      mp.erase (fd + 1);
      fd++;
    }
    fd = num[i];
    while (mp.find (fd - 1) != mp.end() ) {
      mx++;
      mp.erase (fd - 1);
      fd--;
    }
    if (mx > res) {
      res = mx;
    }
  }
  return res;
}

int main()
{
}


