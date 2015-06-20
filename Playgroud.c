
#include <stdio.h>
#include <stdlib.h>


void Swap (char* a, char* b)
{
  char tmp;
  tmp = *b;
  *b = *a;
  *a = tmp;
}

void Permutation (char* s, int size)
{
  if (s[0] == '\0') {
    printf ("%s\n", s - size);
    return;
  }
  int i;
  for (i = 0; s[i] != '\0'; i++) {
    Swap (s, s + i);
    Permutation (s + 1, size);
    Swap (s, s + i);
  }
}

int main()
{
  char s[] = "ABC";
  Permutation (s, 3);
}
