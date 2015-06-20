/*
  Given a set of distinct integers, S, return all possible subsets.

  Note:

  Elements in a subset must be in non-descending order.
  The solution set must not contain duplicate subsets.
  For example,
  If S = [1,2,3], a solution is:

  [
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
  ]

*/

#include <cstdio>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

#include <vector>

int set[10];

//O(2^n) complexity to generate all the possible subsets, NOTE that if the set is not sorted in non-decreasing order, sorting it first doesn't affect overall complesity since sorting O(nlog(n)) will be dwarfed by O(2^n)
/*
  void PowerSet(string s,vector<string>& container){
  //NOTE that if the set is distinct, the possible duplicates could only occur when splitting the string into size 1 substring
  if(s.size() <= 1){
  if(set[s[0]] == 0){
  container.push_back(s);
  set[s[0]] = 1;
  }
  return;
  }
  string tmp = "";
  for(auto i:s)
  tmp += i;
  //push into the current size substring, it's unique
  container.push_back(tmp);
  //reduce size by 1, and recursively generate subsets
  for(int i = 0; i < s.size(); i++){
  string tmp = s.substr(0,i) + s.substr(i + 1);
  PowerSet(tmp,container);
  }
  }
*/

void printSet(int array[],int size){
  for (int i = 1;i <= size;i++)
    cout << array[i] << " ";
  cout << std::endl;
}

void powersetRec(int* s, int k, int m, int n) {
  if (m <= n) {
    s[k+1] = m ;
    printSet(s, k+1) ;
    powersetRec(s, k+1, m+1, n) ; /* with m */
    powersetRec(s, k, m+1, n) ; /*  without m */
  }
}



int main(){
  int s[3];
  powersetRec(s,0,1,3);
  /*
    for(auto i:set)
    i = 0;
    string foo = "123";
    vector<string> bar;
    PowerSet(foo,bar);
    for(auto i:bar){
    for(auto j:i)
    cout << j << " ";
    cout << endl;
    }
  */
}
