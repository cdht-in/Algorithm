#include <vector>
#include <string>
#include <iostream>

using namespace std;

void PowerSetHelper(vector<string>& s, int start, int end, vector<vector<string> >& result,vector<string> set)
{
  if(start > end)
  {
    return;
  }
  
  for(int i = start; i <= end; i++)
  {
    set.push_back(s[i]);
    
    result.push_back(set);
    
    PowerSetHelper(s,i + 1, end,result,set);
  
    set.pop_back(); 
		
  } 
  
}


vector<vector<string> > PowerSet(vector<string>& s)
{
  vector<vector<string> > result;
  if(s.size() == 0)
  {
    result.push_back(vector<string>());
    return result;
  }
  
  result.push_back(vector<string>());
  
  vector<string> set;
  PowerSetHelper(s,0,s.size() - 1,result,set);
  
  return result;
}


int main()
{
	vector<string> s;
	s.push_back("apple");
	s.push_back("banana");
	s.push_back("cherry");
	
	vector<vector<string> > result = PowerSet(s);
	
	for(int i = 0; i < result.size(); i++)
	{
		for(int j = 0; j < result[i].size(); j++)
		{
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
	
}