/*
  Question: Target Sum
  Given an integer x and an unsorted array of integers, describe an algorithm to 
  determine whether two of the numbers add up to x.  (In this case, say that the 
  interviewer hates hash tables.)
*/

#include <cstdio>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <iostream>

using namespace std;

bool Compare (int x, int y)
{
  return x < y;
}

//O(n) time and O(n) space
bool TwoSumI (int x, int* data, int size)
{
  //O(n) to construct the hashtable
  std::unordered_map<int, int> mymap;
  for (int i = 0; i < size; i++) {
    if (mymap.find (data[i]) == mymap.end() )
      mymap[data[i]] = 1;
  }
  for (int i = 0; i < size; i++) {
    if (mymap.find (x - data[i]) != mymap.end() )
      return true;
  }
  return false;
}

vector<int> twoSum (vector<int>& numbers, int target)
{
  unordered_set<int> set;
  for (int i = 0; i < numbers.size(); i++) {
    if (set.find (target - numbers[i]) != set.end() ) {
      vector<int> ret;
      for (int j = 0; j < numbers.size(); j++) {
        //find its index
        if (numbers[j] == (target - numbers[i]) ) {
          ret.push_back (j);
          break;
        }
      }
      ret.push_back (i);
      return ret;
    }
    else
      set.insert (numbers[i]);
  }
  return vector<int>();
}


//O(nlog(n)) time and O(1) space
bool TwoSumII (int x, int* data, int size)
{
  //sort the data first O(nlog(n))
  std::vector<int> vec (data, data + size);
  std::sort (vec.begin(), vec.end(), Compare);
  //two pointers from the start and the end, takes O(n)
  std::vector<int>::iterator i = vec.begin();
  std::vector<int>::iterator j = vec.end();
  for (; i <= j;) {
    if (*i + *j == x)
      return true;
    else if (*i + *j < x)
      i++;
    else
      j--;
  }
  return false;
}

//O(n) time and space, if all numbers of unique, only one scan is required
bool TwoSumIII (int x, int* data, int size)
{
  std::unordered_set<int> set;
  for (int i = 0; i < size; i++) {
    if (set.find (x - data[i]) != set.end() ) {
      printf ("%d %d\n", data[i], x - data[i]);
      return true;
    }
    else
      set.insert (data[i]);
  }
  return false;
}

/*
  Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

  Note:
  Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
  The solution set must not contain duplicate triplets.
  For example, given array S = {-1 0 1 2 -1 -4},

  A solution set is:
  (-1, 0, 1)
  (-1, -1, 2)
*/

//O(n^2) naive approach
/*
  vector<vector<int> > threeSum1 (vector<int>& num)
  {
  vector<vector<int> > ret;
  sort (num.begin(), num.end(), Compare);
  unordered_set<string> combo;
  for (int i = 0; i < num.size(); i++) {
  int sum = - num[i];
  vector<int> tmp;
  for (int j = i + 1; j < num.size(); j++) {
  if (set.find (sum - num[j]) != set.end() ) {
  string str = to_string (num[i]) + to_string (sum - num[j])
  + to_string (num[j]);
  if (combo.find (str) == combo.end() ) {
  combo.insert (str);
  tmp.push_back (num[i]);
  tmp.push_back (sum - num[j]);
  tmp.push_back (num[j]);
  ret.push_back (tmp);
  }
  }
  else
  set.insert (num[j]);
  }
  }
  return ret;
  }
*/

vector<vector<int> > threeSum1 (vector<int>& num)
{
  vector<vector<int> > ret;
  sort (num.begin(), num.end(), Compare);
  for (int i = 0; i < num.size(); i++) {
    int sum = - num[i];
    int j = i + 1;
    int k = num.size() - 1;
    while (j < k) {
      if (num[j] + num[k] == sum) {
        vector<int> tmp;
        tmp.push_back (num[i]);
        tmp.push_back (num[j]);
        tmp.push_back (num[k]);
        ret.push_back (tmp);
        //filter out duplicates
        j++;
        k--;
        while (j < k && num[j] == num[j - 1])
          j++;
        while (j < k && num[k] == num[k + 1])
          k--;
      }
      else if (num[j] + num[k] < sum)
        j++;
      else
        k--;
    }
    //find the first non-duplicate
    while (i < num.size() && num[i] == num[i + 1])
      i++;
  }
  return ret;
}

int main()
{
  vector<int> foo ( { -1, -1, -1, 2, 2});
  vector<vector<int >> ret = threeSum1 (foo);
  for (int i = 0; i < ret.size(); i++) {
    for (int j = 0; j < ret[i].size(); j++) {
      cout << ret[i][j] << " ";
    }
    cout << endl;
  }
}
