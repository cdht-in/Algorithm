/*
  given number from 1 to N, there is one duplicate, and others occur only once

*/

#include <stdio.h>

int FindDuplicate (int* data, int len)
{
  int a = 0;
  int b = 0;
  for (int i = 1; i <= len; i++) {
    a += i;
    b += data[i - 1];
  }
  return b - (a - len);
}


int main()
{
  int foo[] = {1, 2, 3, 4, 7, 7, 6, 5, 9, 8};
  printf ("%d\n", FindDuplicate (foo, sizeof (foo) / sizeof (int) ) );
}
