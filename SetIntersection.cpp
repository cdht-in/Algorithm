/*
  given two unsorted sets, produce a interseted set
*/

#include <vector>
#include <unordered_set>
#include <iostream>
#include <algorithm>

using namespace std;

//O(n) in time and O(n) in space
vector<int> IntersectionI (const vector<int>& a, const vector<int>& b)
{
  vector<int> c;
  unordered_set<int> set;
  for (int i = 0; i < a.size(); i++)
    set.insert (a[i]);
  for (int j = 0; j < b.size(); j++) {
    if (set.find (b[j]) != set.end() )
      c.push_back (b[j]);
  }
  return c;
}


//O(nlog(n)) in time, O(1) in space
vector<int> IntersectionII (vector<int>& a, vector<int>& b)
{
  vector<int> ret;
  sort (a.begin(), a.end() );
  sort (b.begin(), b.end() );
  vector<int>::iterator i = a.begin();
  vector<int>::iterator j = b.begin();
  while (i != a.end() && j != a.end() ) {
    if (*i == *j) {
      ret.push_back (*i);
      i++;
      j++;
    }
    else if (*i < *j)
      i++;
    else
      j++;
  }
  return ret;
}

int main()
{
  vector<int> a ( {1, 2, 3, 4, 3 });
  vector<int> b ( {0, 3, 3, 3, 2, 4, 5});
for (auto i : IntersectionII (a, b) )
    cout << i << endl;
}
