/*
  print the fibonacci sequence of n
*/

#include <cstdio>

void Fibonacci (int n, int* f)
{
  if(n < 1)
    return;
  f[0] = 0;
  if(n == 1)
    return;
  //first two values
  f[1] = 1;
  if (n <= 2)
    return;
  for (int i = 2; i < n; i++) {
    f[i] = f[i - 1] + f[i - 2];
  }
}

int main()
{
  int n = 10;
  int* foo = new int[n];
  Fibonacci(n,foo);
  for(int i = 0; i < n; i++)
    printf("%d ",foo[i]);
  printf("\n");
}
