/*
  simple grade-school multipication table
*/

#include <stdio.h>

void PrintTable (int n)
{
  int i = 1;
  for (; i <= n; i++) {
    int j = 1;
    for (; j <= n; j++) {
      printf ("%d ", i * j);
    }
    printf ("\n");
  }
}

int main()
{
  int n = 12;
  PrintTable (n);
}
