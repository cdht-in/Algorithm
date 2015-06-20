/*
  Given a sorted array of unique elements R, that are letters of English alphabet and an input character x. The elements in R are sorted with the least element appearing first. Find the minimum r in R such that r > x. If there is no r > x, find the first element of the array (wrap around).

  e.g. R = ['c', 'f', 'j', 'p', 'v']
  if x equals:
  'a'
  => return 'c'
  'c' => return 'f'
  'k' => return 'p'
  'z' => return 'c' (wrap around case)

  R = ['c', 'f', 'f', 'j', 'p', 'v'];
*/

#include <stdio.h>


char find_ins_point (const char* sortedStr, unsigned int sortedStrLength, char c)
{
  if (sortedStrLength < 1)
    return 0;
  // implementation goes here.
  int l = 0;
  int r = sortedStrLength - 1;
  int mid = 0;
  while (l <= r) {
    mid = (l + r) / 2;
    if (sortedStr[mid] == c) {
      int i = mid + 1;
      if (i == sortedStrLength)
        return sortedStr[0];
      return sortedStr[i];
    }
    else if (sortedStr[mid] < c) {
      l = mid + 1;
    }
    else {
      r = mid - 1;
    }
  }
  printf("%d\n",r);
  //if l == sortedStrLength > r, wrap around
  if (l == sortedStrLength)
    return sortedStr[0];
  return sortedStr[l];
}

int main()
{
  /*
    e.g. R = ['c', 'f', 'j', 'p', 'v']
  if x equals:
  'a'
  => return 'c'
  'c' => return 'f'
  'k' => return 'p'
  'z' => return 'c' (wrap around case)
  R = ['c', 'f', 'f', 'j', 'p', 'v'];
  */
  char R[] = {'c', 'f', 'f', 'j', 'p', 'v'};
  int size = sizeof (R) / sizeof (char);
  printf ("%c\n", find_ins_point (R, size, 'a') );
}
