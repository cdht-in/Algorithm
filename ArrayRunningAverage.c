/*
Write a function to generate a second array of numbers containing running average of N elements from the original array

So for instance if the original array is,
2,6,4,2,3 and N=3

result = 2,4,3,4,3
you can assume the corner elements can be filled with original elements where there are not enough elements to take avg of N elements
 */

#include <stdio.h>

//O(n)
void RunningAverage (int* a, int size, int N)
{
  int sum = 0;
  int ret[size];
  int i;
  for (i = 0; i < size; i++) {
    if (i < N) {
      sum += a[i];
      ret[i] = sum / (i + 1);
    }
    else {
      sum = sum - a[i - N] + a[i];
      ret[i] = sum / N;
    }
  }
  for (i = 0; i < size; i++) {
    printf ("%d ", ret[i]);
  }
  printf ("\n");
}

int main()
{
  int a[] = {2, 6, 4, 2, 3};
  int size = sizeof (a) / sizeof (int);
  int N = 3;
  RunningAverage (a, size, N);
}
