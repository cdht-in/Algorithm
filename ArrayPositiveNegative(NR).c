/*An array contains both positive and negative numbers in random order. Rearrange the array elements so that positive and negative numbers are placed alternatively. Number of positive and negative numbers need not be equal. If there are more positive numbers they appear at the end of the array. If there are more negative numbers, they too appear in the end of the array.

  For example, if the input array is [-1, 2, -3, 4, 5, 6, -7, 8, 9], then the output should be [9, -7, 8, -3, 5, -1, 2, 4, 6]

*/
#include <stdio.h>


void Swap (int* a, int* b)
{
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void PrintArray (int* a, int size)
{
  int i = 0;
  for (; i < size; i++)
    printf ("%d ", a[i]);
  printf ("\n");
}

//O(n) time O(1) space
void RearrangeArray (int* a, int size)
{
  //first partiion the array into positive and negative
  int i = 0;
  int j = size - 1;
  while (i < j) {
    if (a[i] < 0) {
      Swap (a + i, a + j);
      j--;
    }
    else
      i++;
  }
  PrintArray (a, size);
  //positive pointer, and the first negative
  int pos = 0, neg = i;
  printf("%d\n",a[neg]);
  for (; neg < size && pos < neg; pos += 2, neg++) {
    Swap (a + pos, a + neg);
  }
  PrintArray (a, size);
}

/*
  void rearrange (int arr[], int n)
  {
  // The following few lines are similar to partition process
  // of QuickSort.  The idea is to consider 0 as pivot and
  // divide the array around it.
  int i = -1, j = 0;
  for (; j < n; j++) {
  if (arr[j] < 0) {
  i++;
  printf("%d %d\n",i,j);
  Swap (&arr[i], &arr[j]);
  }
  }
  }*/

int main()
{
  int a[] = { -1, 2, -4, 3,3};
  int size = sizeof (a) / sizeof (int);
  RearrangeArray (a, size);
}
