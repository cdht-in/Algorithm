/*
  Given a collection of numbers that might contain duplicates, return all possible unique permutations.

  For example,
  [1,1,2] have the following unique permutations:
  [1,1,2], [1,2,1], and [2,1,1].
*/
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

/*
first implementation

void swap (vector<int>& num, int i, int j)
{
  int tmp = num[i];
  num[i] = num[j];
  num[j] = tmp;
}

void permuteHelper (vector<int>& num, int p, vector<vector<int> >& container)
{
  if (p >= num.size() ) {
    container.push_back (num);
    return;
  }
  for (int i = p; i < num.size(); i++) {
    //p is the position in the array
    swap (num, i, p);
    permuteHelper (num, p + 1, container);
    swap (num, i, p);
  }
}

vector<vector<int> > permuteUnique (vector<int>& num)
{
  vector<vector<int> > ret;
  sort (num.begin(), num.end() );
  permuteHelper (num, 0, ret);
  return ret;
}
*/

//second implementation

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

//note here the vector<int> is not passed by reference, and the Swap function isn't called twice.
//write out the outputs for [1,1,2,2] to see how it skips duplicates
void permuteHelper(vector<int> num, int start,int end,vector<vector<int> >& result)
{
	if(start > end)
	{
		result.push_back(num);
		return;
	}
	
	for(int i = start; i <= end; i++)
	{
		//duplicates
		if(i != start && num[i] == num[start])
			continue;
		
		Swap(num,i,start);
		
		permuteHelper(num,start + 1,end,result);
		
	}
}

//NOTE the different between permutation and combination, order matters in permutation
vector<vector<int> > permuteUnique(vector<int> &num) {
	vector<vector<int> > result;
	sort(num.begin(),num.end());
	
	permuteHelper(num,0,num.size() - 1,result);
	
	return result;
}


int main()
{
  int foo[] = {1,1,2,2};
  vector<int> permu(foo, foo + sizeof(foo) / sizeof(int));
  
  vector<vector<int> > ret = permuteUnique (permu);
  for (auto i: ret) {
    for (auto j: i) {
      cout << j << " " ;
    }
    cout << endl;
  }
}
