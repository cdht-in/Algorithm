/*

  Suppose a sorted array is rotated at some pivot unknown to you beforehand.

  (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

  You are given a target value to search. If found in the array return its index, otherwise return -1.

  What if duplicates are allowed?

  Would this affect the run-time complexity? How and why?

  Write a function to determine if a given target is in the array.
*/

#include <vector>
#include <iostream>

using namespace std;

/*first implementation

bool bisearch (int A[], int l, int r, int target)
{
  int mid = 0;
  while (l <= r) {
    mid = (l + r) / 2;
    if (A[mid] == target)
      return true;
    else if (A[mid] < target)
      l = mid + 1;
    else
      r = mid - 1;
  }
  return false;
}

bool search (int A[], int n, int target)
{
  if (n < 1)
    return false;
  int i = 0;
  for (; i < n - 1 && A[i] <= A[i + 1]; i++);
  int ret = bisearch (A, 0, i, target);
  if (ret)
    return true;
  return bisearch (A, i + 1, n - 1, target);
}

*/


//second implementation

bool searchHelper(int A[], int start, int end, int target)
{
	if(start > end)
		return false;
	
	int mid = (start + end) / 2;
	if(A[mid] == target)
		return true;
	
	//skip the duplicates
	while(mid - 1 >= start && A[mid] == A[mid - 1])
		mid--;
	if(searchHelper(A,start,mid - 1, target))
		return true;
	
	while(mid + 1 <= end && A[mid] == A[mid + 1])
		mid++;
	if(searchHelper(A,mid + 1, end, target))
		return true;
	
	return false;
}


bool search(int A[], int n, int target) {
	if(n == 0)
		return false;
	
	return searchHelper(A,0,n - 1, target);
}


//third implementation
int findMin(vector<int>& nums)
{
	int mid = 0;
	int l = 0;
	int r = nums.size() - 1;
	int min = INT_MAX;
	while(l <= r)
	{
		mid = (l + r) / 2;
		//skip the duplicates
		while(mid < r)
		{
			if(nums[mid] == nums[mid + 1])
			{
				mid++;
			}
			else
			{
				mid++;
				break;
			}
		}
		
		//right side is sorted
		if(nums[mid] <= nums[r])
		{
			min = (min < nums[mid]) ? min : nums[mid];
			r = mid - 1;
		}
		//left side is sorted
		else
		{
			min = (min < nums[l]) ? min : nums[l];
			l = mid + 1;
		}
	}
	
	return min;	
}



int main()
{
	vector<int> foo = {3,3,4,5,0,1,3};
	cout << findMin(foo) << endl;
}
