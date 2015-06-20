/*
  onsider the following 6 activities.
  start[]  =  {1, 3, 0, 5, 8, 5};
  finish[] =  {2, 4, 6, 7, 9, 9};
  The maximum set of activities that can be executed
  by a single person is {0, 1, 3, 4}
*/
#include <stdlib.h>
#include <stdio.h>

typedef struct {
  int start;
  int end;
} Activity;


int Compare (const void* a, const void* b)
{
  return ( ( (Activity*) a)->end - ( (Activity*) b)->end );
}

//assume the activities are sorted in their finishing time in ascending order
//O(nlog(n)) time complexity
void ActivitySelection (Activity* act, int size)
{
  if (size == 0) {
    printf ("no activity\n");
    return;
  }
  Activity* p = act;
  printf ("select (%d,%d)\n", p->start, p->end);
  int i;
  for (i = 1; i < size; i++) {
    if (act[i].start >= p->end) {
      printf ("select (%d,%d)\n", act[i].start, act[i].end);
      p = act + i;
    }
  }
}

int main()
{
  int size = 6;
  Activity act[size];
  act[0].start = 1;
  act[0].end = 2;
  act[1].start = 3;
  act[1].end = 4;
  act[2].start = 0;
  act[2].end = 6;
  act[3].start = 5;
  act[3].end = 7;
  act[4].start = 8;
  act[4].end = 9;
  act[5].start = 5;
  act[5].end = 9;
  qsort (act, size, sizeof (Activity), Compare);
  /*
  start[]  =  {1, 3, 0, 5, 8, 5};
  finish[] =  {2, 4, 6, 7, 9, 9};
  The maximum set of activities that can be executed
  by a single person is {0, 1, 3, 4}
  */
  ActivitySelection (act, size);
  int i;
  for (i = 0 ; i < size; i++) {
    printf ("%d ", act[i].end);
  }
  printf ("\n");
}
