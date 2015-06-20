/*
  if i is 3's multiple,print fizz, if i is 5's multiple, print buzz, if it is divisible by 3 and 5, print fizz buzz
  ,print the rest numbers
 */

#include <cstdio>

void FizzBuzz (int n)
{
  for (int i = 1; i <= n; i++) {
    if (i % 3 == 0 && i % 5 == 0)
      printf ("fizzbuzz\n");
    else {
      if (i % 3 == 0)
        printf ("fizz\n");
      else if (i % 5 == 0)
        printf ("buzz\n");
      else
        printf ("%d\n", i);
    }
  }
}

int main()
{
  FizzBuzz (100);
}
