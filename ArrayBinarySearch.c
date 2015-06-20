#include <stdio.h>


//recursive O(logn)
int BinarySearch (int x, int* data, int l, int r)
{
  if (l > r)
    return -1;
  int mid = (l + r) / 2;
  if (data[mid] == x)
    return mid;
  else if (data[mid] < x)
    return BinarySearch (x, data, mid + 1, r);
  else
    return BinarySearch (x, data, l, mid - 1);
}

//iterative
int BinarySearchI (int x, int* a, int size)
{
  int l = 0;
  int r = size;
  int mid;
  while (l <= r) {
    mid = (l + r) / 2;
    if (a[mid] == x)
      return mid;
    if (a[mid] < x)
      l = mid + 1;
    else
      r = mid - 1;
  }
  return -1;
}

int main()
{
  int foo[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int size = sizeof (foo) / sizeof (int);
  int i;
  for (i = -5; i <= 12; i++) {
    printf ("%d\n", BinarySearchI (i, foo, size) );
  }
}
