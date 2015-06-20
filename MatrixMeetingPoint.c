/*

  here is an infinite integer grid at which N people have their houses on. They decide to unite at a common meeting place, which is someone's house. From any given cell, all 8 adjacent cells are reachable in 1 unit of time. eg: (x,y) can be reached from (x-1,y+1) in a single unit of time. Find a common meeting place which minimizes the sum of the travel times of all the persons
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long x[400000], y[400000], i, n, sx = 0, sy = 0, mx, min, my, sum = 0, pos_min, pos_med = 0, minTemp = 0;

long long Abss (long long h)
{
  return (h > 0 ? h : - (h) );
}

long long max (long long f, long long g)
{
  return ( (f > g) ? f : g);
}

int main()
{
  scanf ("%lld", &n);
  for ( i = 0; i < n; i++ ) {
    scanf ("%lld %lld", &x[i], &y[i]);
  }
  for ( i = 0; i < n; i++ ) {
    sx += x[i];
    sy += y[i];
  }
  //find the center point
  mx = sx / n;
  my = sy / n;
  //find the mean distance to the center point
  min = sqrt ( (mx - x[0]) * (mx - x[0]) + (my - y[0]) * (my - y[0]) );
  for ( i = 1; i < n; i++ ) {
    double diff = sqrt ( (mx - x[i]) * (mx - x[i]) + (my - y[i]) * (my - y[i]) );
    if (diff < min) {
      min = diff;
      pos_min = i;
    }
  }
  //minimal steps for each point to the center point
  for (i = 0; i < n; i++ ) {
    sum += max ( (Abss (x[pos_min] - x[i]) ), (Abss (y[pos_min] - y[i]) ) );
  }
  printf ("%llu", sum);
  return 0;
}
