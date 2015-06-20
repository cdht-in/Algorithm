
/*
  remove duplicates from a sorted array
*/
#include <cstdio>

int RemoveDuplicates (int* data, int size, int* out)
{
  if (size <= 1)
    return 0;
  //two pointers to remove duplicates
  int f = 0;
  int s = f;
  //new array size
  int a = 0;
  while (1) {
    for (; f < size && data[s] == data[f]; f++) {}
    //now add s to ret
    out[a++] = data[s];
    //test if reach the end
    if (f >= size)
      return a;
    //update s
    s = f;
  }
}

/*
  Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

  Do not allocate extra space for another array, you must do this in place with constant memory.

  For example,
  Given input array A = [1,1,2],

  Your function should return length = 2, and A is now [1,2].
*/

int removeDuplicates (int A[], int n)
{
  if (n < 2)
    return n;
  int i = 0;
  int j = 1;
  while (1) {
    while (j < n && A[j] == A[j - 1])
      j++;
    A[i++] = A[j - 1];
    if (j == n)
      break;
    else // j < n
      j++;
  }
  return i;
}



int main()
{
  int foo[] = {1, 2, 3, 3};
  int size = sizeof (foo) / sizeof (int);
  int bar[size];
  int len = RemoveDuplicates (foo, size, bar);
  for (int i = 0; i < len; i++) {
    printf ("%d ", bar[i]);
  }
  printf ("\n");
}
