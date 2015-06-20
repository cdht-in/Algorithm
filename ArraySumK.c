/*
  non negative subarray sums to k
 */

#include <stdio.h>

//O(n)
void SumK (int* a, int size, int k)
{
  int i = 0;
  int j = 0;
  int sum = 0;
  for (; i < size; i++) {
    sum += a[i];
    if (sum == k)
      printf ("%d at %d %d\n", sum, j, i);
    else if (sum > k) {
      //substract the a[j] until find the sum
      for (; j < i; j++) {
        sum -= a[j];
        if (sum == k) {
	  //advance j to indicate correct starting point
          j++;
          printf ("%d at %d %d\n", sum, j, i);
          break;
        }
      }
    }
  }
}


int main()
{
  int a[] = {1,2};
  int size = sizeof (a) / sizeof (int);
  SumK (a, size, 2);
}
