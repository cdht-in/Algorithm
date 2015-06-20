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

#include <vector>
#include <iostream>

using namespace std;

void subsetsWithDupHelper(vector<int>& S, int start, int end,vector<int>& subset, vector<vector<int> >& result){
	if(start > end)
	{
		return;
	}
	
	for(int i = start; i < S.size(); i++)
	{
		subset.push_back(S[i]);
		result.push_back(subset);
		
		subsetsWithDupHelper(S,i + 1,end,subset,result);
			
		subset.pop_back();
		
		//skip those duplicates
		while(i < S.size() - 1 && S[i] == S[i + 1])
			i++;
	}	
}

vector<vector<int> > subsetsWithDup(vector<int> &S) {
	vector<vector<int> > result;
	if(S.size() == 0)
		return result;
	vector<int> subset;
	result.push_back(subset);
	
	int start = 0;
	int end = S.size() - 1;
	//sort the integers first so that duplicates are adjacent
	
	sort(S.begin(), S.end());  
	subsetsWithDupHelper(S,start, end,subset,result);
	return result;
}

int main(){
	vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(2);
	
	vector<vector<int> > result = subsetsWithDup(vec);
	
	for(int i = 0; i < result.size(); i++)
	{
			for(int j = 0; j < result[i].size(); j++)
			{
				cout << result[i][j] << " , ";
			}
			cout << endl;
	}	
	
}