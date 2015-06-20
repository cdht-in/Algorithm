/*
  Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

  For example,
  If n = 4 and k = 2, a solution is:

  [
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
  ]
*/

#include <vector>
#include <iostream>

using namespace std;

/*
first implementation

void combineHelper (vector<int>& combo, int level, int k, int index, int n, vector<vector<int> >& container)
{
  if (level == k + 1) {
    container.push_back (combo);
    return;
  }
  for (int i = index; i <= n; i++) {
    combo.push_back (i);
    combineHelper (combo, level + 1, k, i + 1, n, container);
    combo.pop_back();
  }
}

vector<vector<int> > combine (int n, int k)
{
  vector<vector<int> > ret;
  vector<int> combo;
  combineHelper (combo, 1, k, 1, n, ret);
  return ret;
}
*/


//second implementation

vector<vector<int> > combine(int n, int k) {
	vector<vector<int> > result;
	if(n < k)
		return result;
	if(n == k)
	{
		vector<int> subset;
		for(int i = 1; i <= n; i++)
		{
			subset.push_back(i);
		}
		result.push_back(subset);
		return result;
	}
	
	result.push_back(vector<int>());
	vector<int> combo;
	vector<vector<int> > kSet;	
	for(int i = 1; i <= n; i++)
	{
			int size = result.size();
			for(int j = 0; j < size; j++)
			{
				vector<int> newSubSet(result[j]);
				newSubSet.push_back(i);
				
				result.push_back(newSubSet);
				
				//get a subset of the power set, 2^n
				if(newSubSet.size() == k)
					kSet.push_back(newSubSet);
				
			}
	}
	
	return kSet;
	
}





































void combineIHelper(int start, int end, int k, vector<int>& set, vector<vector<int> >& result)
{
	if(start > end)
	{
		return;
	}
	
	for(int i = start; i <= end; i++)
	{
		set.push_back(i);
		
		if(set.size() == k)
		{
			result.push_back(set);
		}
		
		combineIHelper(i + 1, end, k, set, result);
		
		set.pop_back();
	}
}

//second implementation
vector<vector<int> > combineI(int n, int k) 
{
	vector<vector<int> > result;
	vector<int> set;
	if(n < k)
		return result;
	
	combineIHelper(1,n,k,set,result);
	
	return result;
}

int main()
{
	vector<vector<int> > result = combineI(4,2);
	for(int i = 0; i < result.size(); i++)
	{
		for(int j = 0; j < result[i].size(); j++)
		{
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
}
