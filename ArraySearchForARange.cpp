/*
  Given a sorted array of integers, find the starting and ending position of a given target value.

  Your algorithm's runtime complexity must be in the order of O(log n).

  If the target is not found in the array, return [-1, -1].

  For example,
  Given [5, 7, 7, 8, 8, 10] and target value 8,
  return [3, 4].

*/
#include <vector>
#include <iostream>


using namespace std;

/*
first implementation

int bisearch (int A[], int l, int r, int target)
{
  int mid = 0;
  while (l <= r) {
    mid = (l + r) / 2;
    if (A[mid] == target)
      return mid;
    else if (A[mid] < target)
      l = mid + 1;
    else
      r = mid - 1;
  }
  return - 1;
}

vector<int> searchRange (int A[], int n, int target)
{
  vector<int> ret;
  int l = 0;
  int r = 0;
  int s = bisearch (A, 0, n - 1, target);
  if (s == -1) {
    ret.push_back (-1);
    ret.push_back (-1);
    return ret;
  }
  for (int i = s; i >= 0; i--) {
    if (A[s] == A[i])
      l = i;
    else
      break;
  }
  for (int i = s; i < n; i++) {
    if (A[s] == A[i])
      r = i;
    else
      break;
  }
  ret.push_back(l);
  ret.push_back(r);
  return ret;
}

*/

//second implementation

int biSearch(int A[], int l, int r, int target)
{
	int mid = 0;
	while(l <= r)
	{
		mid = (l + r) / 2;
		if(A[mid] == target)
		{
			return mid;
		}
		else if(A[mid] < target)
		{
			l = mid + 1;
		}
		else
		{
			r = mid - 1;
		}
	}
	return -1;
}
	
vector<int> searchRange(int A[], int n, int target) {
	vector<int> vec;
	
	int p = 0;
	if(n == 0 || (p = biSearch(A,0,n - 1,target)) == -1)
	{
		vec.push_back(-1);
		vec.push_back(-1);
		return vec;
	}
		
	//search the left and right
	int l = p;
	int tmp = p;
	while(tmp != -1)
	{
		l = tmp;
		tmp = biSearch(A,0,tmp - 1,target);
	}
	
	int r = p;
	tmp = p;
	while(tmp != -1)
	{
		r = tmp;
		tmp = biSearch(A,tmp + 1,n - 1,target);
	}
		
	vec.push_back(l);
	vec.push_back(r);
	return vec;

}

int main()
{
	int foo[] = {1,4,4};
	int n = sizeof(foo) / sizeof(int);
	int target = 4;
	vector<int>  vec = searchRange(foo,n,target);
	for(int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << " ";
	}
	cout << endl;
}
