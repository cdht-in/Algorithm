/*
  give a sorted array, return the next big number
*/
#include <cstdio>

//O(n)
int NextI (int* data, int size, int n)
{
  //requires (n-1) * 2 comparisons
  for (int i = 0; i < size - 1; i++) {
    if (data[i] <= n && data[i + 1] > n)
      return data[i + 1];
  }
  //if no bigger one
  return -1;
}

//one optimization that can be done is this to reduced the number of comparison
int NextII (int* data, int size, int n)
{
  //only the first range check needs to compare both boundaries,requires 2 + n - 1 = n + 1 comparisons. OF COURSE, assumption is that size is at least 2 in this case.
  if (data[0] <= n && data[1] > n)
    return data[1];
  for(int i = 1; i < size - 1; i++){
    if(data[i + 1] > n)
      return data[i+1];
  }
  return 0xDEADBEEF;
}


int main()
{
  int foo[] = {1, 5, 6, 8, 9};
  int size = sizeof (foo) / sizeof (int);
  printf ("%d\n", NextII (foo, size, 9) );
}
