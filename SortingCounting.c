/*
  counting sort implementation
*/

/*
  precondition is if the range of number is known before hand
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void CountingSort (int* a, int size, int k)
{
  int* count = (int*) malloc (k * sizeof (int) );
  int i;
  for (i = 0; i < k; i++) {
    count[i] = 0;
  }
  for (i = 0; i < size ; i++) {
    count[a[i]]++;;
  }
  int p = 0;
  for (i = 0; i < k; i++) {
    if (count[i] > 0) {
      int j;
      for (j = 0; j < count[i]; j++) {
        a[ (p++) + j] = i;
      }
    }
  }
  free (count);
}

int main()
{
  int size = 5;
  int* a = (int*) malloc (size * sizeof (int) );
  int foo[] = {2, 1, 6, 5, 4};
  memcpy (a, foo, size * sizeof (int) );
  int i, k = 7;
  for (i = 0; i < size; i++) {
    printf ("%d ", a[i]);
  }
  printf ("\n");
  CountingSort (a, size, k);
  for (i = 0; i < size; i++) {
    printf ("%d ", a[i]);
  }
  printf ("\n");
  free (a);
  return 0;
}
