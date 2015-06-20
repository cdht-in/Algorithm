/*
  Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

  Each number in C may only be used once in the combination.

  Note:
  All numbers (including target) will be positive integers.
  Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
  The solution set must not contain duplicate combinations.
  For example, given candidate set 10,1,2,7,6,1,5 and target 8,
  A solution set is:
  [1, 7]
  [1, 2, 5]
  [2, 6]
  [1, 1, 6]
*/

#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

/*
first implementation

void combinationSumHelper (vector<int>& candidate, int index, int sum, int target, vector<int>& path, vector<vector<int> >& container)
{
  if (sum == target) {
    container.push_back(path);
    return;
  }
  else if (sum > target)
    return;
  for (int i = index; i < candidate.size(); i++) {
    sum += candidate[i];
    path.push_back (candidate[i]);
    combinationSumHelper (candidate, i + 1, sum, target, path, container);
    sum -= candidate[i];
    path.pop_back();
    while(i < candidate.size() - 1 && candidate[i] == candidate[i + 1])
      i++;
  }
}

vector<vector<int> > combinationSum2 (vector<int>& num, int target)
{
  vector<vector<int> > ret;
  vector<int> path;
  sort (num.begin(), num.end() );
  combinationSumHelper (num, 0, 0, target, path, ret);
  return ret;
}
*/

//second implementation
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
		
		combinationSumHelper(candidates,i + 1,target, sum + candidates[i],vec,result);
		
		vec.pop_back();
		
		//skip the duplicates
		while(i + 1 < candidates.size() && candidates[i] == candidates[i + 1])
			i++;
	}
}

//second implementation
vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
	vector<vector<int> > result;
	if(candidates.size() < 1)
		return result;
	vector<int> vec;
	sort(candidates.begin(),candidates.end());
	combinationSumHelper(candidates,0,target,0,vec,result);
	return result;
}







































//third implementation
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
		combinationSumIHelper(candidates, i + 1, end, sum, target, set, result);
		
		sum -= candidates[i];
		set.pop_back();
		
		while(i + 1 <= end && candidates[i] == candidates[i + 1])
			i++;
		
	}
}

//third implementation
vector<vector<int> > combinationSum2I(vector<int> &candidates, int target) 
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
}
