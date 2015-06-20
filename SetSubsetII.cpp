/*
  Given a collection of integers that might contain duplicates, S, return all possible subsets.

  Note:

  Elements in a subset must be in non-descending order.
  The solution set must not contain duplicate subsets.
  For example,
  If S = [1,2,2], a solution is:

  [
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
  ]
*/

#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

unordered_set<string> history;

int Compare(int a, int b){
  return a < b;
}

void Subset(vector<int> set, vector<vector<int> >& container){
  for(int i = 0;i < set.size(); i++){
    vector<int> tmp;
    tmp.push_back(set[i]);
    //concataed to be hashable
    string s = string(tmp.begin(),tmp.end());
    if(history.find(s) == history.end()){
      container.push_back(tmp);
      history.insert(s);
    }
    for(int j = i + 1; j < set.size(); j++){
      if(set[j] >= set[i]){
	tmp.push_back(set[j]);
	s = string(tmp.begin(),tmp.end());
	if(history.find(s) == history.end()){
	  container.push_back(tmp);
	  history.insert(s);
	}
      }
      else
	break;
    }
  }
}

int main(){
  int foo[] = {1,2,3};
  vector<int> bar(foo,foo + sizeof(foo) / sizeof(int));
  vector<vector<int> > container;
  Subset(bar,container);
  for(auto i:container){
    for(auto j:i)
      cout << j << " ";
    cout << endl;    
  }
}



