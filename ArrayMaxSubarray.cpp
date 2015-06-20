/*
  Question: Maximal Subarray Given an array, describe an algorithm to identify the subarray with the maximum sum.  For example, if the input is [1, ‐3, 5, ‐2, 9, ‐8, ‐6, 4], the output would be [5, ‐2, 9].
*/
#include <stdio.h>

//check for the max of any adjacent subarray of size 3
int MaxSub (int* data, int size)
{
  if (size < 4)
    return data[0] + data[1] + data[2];
  int sum = data[0] + data[1] + data[2];
  int tmp = sum;
  int i, index = 0;
  for (i = 3; i < size; i++) {
    tmp +=  data[i] - data[i - 3];
    if (tmp > sum) {
      sum = tmp;
      index = i;
    }
  }
  printf ("%d\n", index);
  return sum;
}

//naive O(n^2)
int MaxSubI (int* data, int size)
{
  int sum = 0;
  int Max = 0;
  int i, j, tmp = 0;
  for (i = 0; i < size; i++) {
    sum = data[i];
    tmp = sum;
    for (j = i + 1; j < size; j++) {
      tmp += data[j];
      if (tmp > sum)
        sum = tmp;
    }
    if (sum > Max)
      Max = sum;
  }
  return Max;
}

//O(n), NOTE subarray is continuous, and if the entire array is negative, return the first entry
int MaxSubII (int* a, int size, int* begin, int* end)
{
  if (size == 0)
    return 0;
  if(size == 1)
    return a[0];
  //size >= 2
  int max_so_far = a[0], max_ending_here = a[0];
  int i, begin_temp = 0;
  // the maximum sum in the first I elements is
  //either the maximum sum in the first I-1 elements (which we'll call MaxSoFar), or it is that of a
  //subvector that ends in position I (which we'll call MaxEndingHere).
  for (i = 1; i < size; i++) {
    // calculate max_ending_here
    if (max_ending_here < 0) {
      max_ending_here = a[i];
      begin_temp = i;
    }
    else {
      max_ending_here += a[i];
    }
    // calculate max_so_far
    if (max_ending_here > max_so_far ) {
      max_so_far  = max_ending_here;
      *begin = begin_temp;
      *end = i;
    }
  }
  return max_so_far ;
}

/*
  Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

  For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
  the contiguous subarray [4,−1,2,1] has the largest sum = 6.

  click to show more practice.

  More practice:
  If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/

int maxSubArray(int A[], int n) {
  //n >= 1
  int max = A[0];
  int tmpmax = max;
  for(int i = 1; i < n; i++){
    if(tmpmax >= 0)
      tmpmax += A[i];
    else{
      tmpmax = A[i];
    }
    if(tmpmax > max)
      max = tmpmax;
  }
  return max;
}

int main()
{
  int foo[] = {5, 1, 2, 3, -1, 2, 5};
  int begin = 0;
  int end = begin;
  int max = MaxSubII (foo, sizeof (foo) / sizeof (int), &begin, &end);
  printf ("sum is %d, begin: %d end:%d\n", max, begin, end );
}

