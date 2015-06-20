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

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

/*
first implementation

void subsetsHelper (vector<int>& S, int index, vector<int>& set, vector<vector<int> >& ret)
{
  for (int i = index; i < S.size(); i++) {
    set.push_back (S[i]);
    subsetsHelper (S, i + 1, set, ret);
    ret.push_back (set);
    set.pop_back();
    //skip those duplicates
    while((i < S.size() - 1) && S[i] == S[i + 1])
      i++;
  }
}

vector<vector<int> > subsets (vector<int>& S)
{
  vector<vector<int> > ret;
  vector<int> set;
  sort (S.begin(), S.end() );
  subsetsHelper (S, 0, set, ret);
  ret.push_back(vector<int>());
  return ret;
}
*/

//second implementation

void subsetsHelper(vector<int> &S,int start, int end, vector<int>& subset,vector<vector<int> >& result)
{
	if(start > end)
	{
		return;
	}
		
	for(int i = start; i <= end; i++)
	{
		subset.push_back(S[i]);
		result.push_back(subset);
		
		subsetsHelper(S,i + 1, end,subset,result);
		
		subset.pop_back();
	}
}

vector<vector<int> > subsets(vector<int> &S) {
	vector<vector<int > > result;
	if(S.size() == 0)
		return result;
	sort(S.begin(),S.end());
	
	result.push_back(vector<int>());
	vector<int> subset;
	
	subsetsHelper(S,0,S.size() - 1, subset,result);
	
	return result;
}

//iterative approach
vector<vector<int> > subsetsI(vector<int> &S) {
	vector<vector<int > > result;
	if(S.size() == 0)
		return result;
	sort(S.begin(),S.end());
	
	result.push_back(vector<int>());
	
	for(int i = 0; i < S.size(); i++)
	{
		//add the current elemnt to existing subsets
		int size = result.size();
		for(int j = 0; j < size; j++)
		{
			//copy constructor
			vector<int> newSubSet (result[j]);
			newSubSet.push_back(S[i]);
			result.push_back(newSubSet);
		}
	}
	return result;
}



int main()
{
  vector<int> set;
  set.push_back (1);
  set.push_back (2);
  
  vector<vector<int> > ret = subsets (set);
  for (int i = 0; i < ret.size(); i++) {
    for (int j = 0; j < ret[i].size(); j++) {
      cout << ret[i][j] << " ";
    }
    cout << endl;
  }
}
