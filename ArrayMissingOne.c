/*

  Write a program to find the missing element in second array(Array2):
  Array1:
  5 15 2 20 30 40 8 1
  Array2:
  2 20 15 30 1 40 0 8

*/

#include <stdio.h>

//assumption is that a has one more element than b does
int FindMissing (int* a, int* b,int size)
{
  int i,ret = 0;
  for(i = 0; i < size - 1; i++){
    ret ^= a[i];
    ret ^= b[i];
  }
  //now ret ^ a[i] is the extra one
  return ret ^ a[i];
}


int main()
{
  int a[] = {5, 15, 2, 20, 30, 40, 8, 1};
  int b[] = {2, 20, 15, 30, 1, 40,8};
  int size = sizeof(a) / sizeof(int);
  printf("%d\n",FindMissing(a,b,size));
}
