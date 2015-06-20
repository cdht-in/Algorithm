/*
   Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

   The same repeated number may be chosen from C unlimited number of times.

   Note:
   All numbers (including target) will be positive integers.
   Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
   T                                                                                                                                                                        he solution set must not contain duplicate combinations.
   For example, given candidate set 2,3,6,7 and target 7,
   A solution set is:
   [7]
   [2, 2, 3]

Elements in a combination (a1, a2, … , ak) must be in non-desce*/

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

/*

first implementation

void combinationSumHelper (vector<int>& candidate, int index, int sum, int target, vector<int>& path, vector<vector<int> >& container)
{
  if (sum == target) {
    container.push_back (path);
    return;
  }
  else if (sum > target)
    return;
  for (int i = index; i < candidate.size(); i++) {
    sum += candidate[i];
    path.push_back (candidate[i]);
    combinationSumHelper (candidate, i, sum, target, path, container);
    sum -= candidate[i];
    path.pop_back();
  }
}

vector<vector<int> > combinationSum (vector<int>& candidates, int target)
{
  vector<vector<int> > ret;
  vector<int> path;
  sort(candidates.begin(),candidates.end());
  combinationSumHelper (candidates, 0, 0, target, path, ret);
  return ret;
}

*/

void combinationSumHelper(vector<int> &candidates, int start,int target,int sum,vector<int>& vec,vector<vector<int> >& result) {
	
	if(target == sum)
	{
		result.push_back(vec);
		return;
	}

	if(start >= candidates.size()) 
	{
		return;
	}	
		
	for(int i = start; i < candidates.size(); i++)
	{
		//candidates are sorted, so the rest of the list could only get bigger
		if(sum + candidates[i] > target)
			return;
		
		vec.push_back(candidates[i]);
		
		//passing i instead of i + 1 makes sure the candidates[i] can be used repeatively
		combinationSumHelper(candidates,i,target, sum + candidates[i],vec,result);
		
		vec.pop_back();
	}
}

//second implementation
vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
	vector<vector<int> > result;
	if(candidates.size() < 1)
		return result;
	vector<int> vec;
	sort(candidates.begin(),candidates.end());
	combinationSumHelper(candidates,0,target,0,vec,result);
	return result;
}







































void combinationSumIHelper(vector<int> &candidates,int start, int end, int sum, int target,vector<int>& set, vector<vector<int> >& result) 
{
	if(sum == target)
	{
		result.push_back(set);
		return;
	}
	
	if(start > end)
		return;
	
	for(int i = start; i <= end; i++)
	{
		if(sum + candidates[i] > target)
			return;
		
		sum += candidates[i];
		set.push_back(candidates[i]);
		
		//NOTE here how the recursion keeps adding the same number until it gets bigger than the sum and try the next number
		combinationSumIHelper(candidates, i, end, sum, target, set, result);
		
		sum -= candidates[i];
		set.pop_back();
		
	}
}

//third implementation
vector<vector<int> > combinationSumI(vector<int> &candidates, int target) 
{
	vector<vector<int> > result;
	if(candidates.size() < 1)
		return result;
	
	sort(candidates.begin(),candidates.end());
	
	vector<int> set;
	
	combinationSumIHelper(candidates,0,candidates.size() - 1, 0,target,set,result);
	
	return result;
}


int main()
{
  vector<int> vec;
  vec.push_back (2);
  vec.push_back (3);
  vec.push_back (6);
  vector<vector<int> > ret = combinationSum (vec, 6);
  for (int i = 0; i < ret.size(); i++) {
    for (int j = 0; j < ret[i].size(); j++)
      cout << ret[i][j] << " ";
    cout << endl;
  }
}
