/*
  Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

  You may assume no duplicates in the array.

  Here are few examples.
  [1,3,5,6], 5 → 2
  [1,3,5,6], 2 → 1
  [1,3,5,6], 7 → 4
  [1,3,5,6], 0 → 0

*/


/*
first implmentation

int searchInsert (int A[], int n, int target)
{
  if(n < 1)
    return 0;
  int mid = 0;
  int l = 0;
  int r = n - 1;
  while (l <= r) {
    mid = (l + r) / 2;
    if (A[mid] == target)
      return mid;
    else if (A[mid] < target)
      l = mid + 1;
    else
      r = mid - 1;
  }
  //the only time that it could reach here is when l and r is off by 1
  return (l > r) ? l : r;
}

*/

//second implementation

int searchInsert(int A[], int n, int target) {
    if(n < 1)
      return 0;
    int mid = 0;
    int l = 0;
    int r = n - 1;
    while (l <= r)
	{
      mid = (l + r) / 2;
      if (A[mid] == target)
        return mid;
      else if (A[mid] < target)
        l = mid + 1;
      else
        r = mid - 1;
    }
	
    //the only time that it could reach here is when l and r is off by 1
    return (l > r) ? l : r;
	
}

int main()
{
}
