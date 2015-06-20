/*
  Given a collection of numbers, return all possible permutations.
  For example,
  [1,2,3] have the following permutations:
  [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
*/

#include <vector>

using namespace std;

/*

first implementation

void swap (vector<int>& num, int i, int j)
{
  int tmp = num[i];
  num[i] = num[j];
  num[j] = tmp;
}

void permuteHelper (vector<int>& num, int p, vector<int>& permu, vector<vector<int> >& container)
{
  if (p >= num.size() ) {
    container.push_back (permu);
    return;
  }
  for (int i = p; i < num.size(); i++) {
    //p is the position in the array
    swap (num, i, p);
    permu.push_back (num[p]);
    permuteHelper (num, p + 1, permu, container);
    permu.pop_back();
    swap (num, i, p);
  }
}

vector<vector<int> > permute (vector<int>& num)
{
  vector<vector<int> > ret;
  vector<int> permu;
  permuteHelper (num, 0, permu, ret);
  return ret;
}

*/

//second implementation

void Swap(vector<int>& num, int i, int j)
{
	int tmp = num[i];
	num[i] = num[j];
	num[j] = tmp;
}

void permuteHelper(vector<int>& num, int start,vector<vector<int> >& result){
	
	if(start >= num.size())
	{
		result.push_back(num);
		return;
	}
	
	for(int i = start; i < num.size(); i++)
	{
		Swap(num,i,start);
		
		permuteHelper(num,start + 1,result);
		
		Swap(num,i,start);
	}
}

vector<vector<int> > permute(vector<int> &num) {
	vector<vector<int> > result;
	if(num.size() < 1)
	{
		return result;
	}
	permuteHelper(num,0,result);
	return result;
}





































void permuteIHelper(vector<int> &num, int start, int end, vector<vector<int> >& result)
{
	if(start > end)
	{
		result.push_back(num);
		return;
	}
	
	for(int i = start; i <= end; i++)
	{
		//there are end - start choices for the current i
		Swap(num,start,i);
		permuteIHelper(num,start + 1, end, result);
		Swap(num,start,i);
	}
}

//second implementation
vector<vector<int> > permuteI(vector<int> &num) 
{
	vector<vector<int> > result;
	permuteIHelper(num,0,num.size() - 1, result);
	return result;
}

int main()
{
}
