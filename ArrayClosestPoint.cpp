#include <cstdio>
#include <stack>
#include "QuickSelect.h"

struct Point {
  double x;
  double y;
};

//using a heap, O(nlogk)
static Point* closestk ( Point* myList, int n, int k )
{
  std::stack<Point*> s;
  std::stack<Point*> tmp;
  Point p;
  p.x = 999;
  p.y = 999;
  s.push (&p);
  double topvalue = 0;
  double curvalue = 0;
  for (int i = 0; i < n; i++) {
    topvalue = s.top()->x * s.top()->x + s.top()->y * s.top()->y;
    curvalue = myList[i].x * myList[i].x + myList[i].y * myList[i].y;
    if (curvalue < topvalue)
      s.push (myList + i);
    else {
      while ( (s.top()->x * s.top()->x + s.top()->y * s.top()->y) < curvalue) {
        tmp.push (s.top() );
        s.pop();
      }
      s.push (myList + i);
      while (!tmp.empty() ) {
        s.push (tmp.top() );
        tmp.pop();
      }
    }
  }
  //now the top k values are the closest k values
  Point* ret = new Point[k];
  for (int i = 0; i < k; i++) {
    ret[i] = * (s.top() );
    s.pop();
  }
  return ret;
}

//approach II, quick select k times, O(n)


int main()
{
  int n = 10;
  int k = 5;
  Point* foo = new Point[n];
  for (int i = 0; i < n; i++) {
    foo[i].x = i + 1;
    foo[i].y = i + 1;
  }
  Point* bar = closestk (foo, n, k);
  for (int i = 0; i < k; i++) {
    printf ("%0.2f %0.2f\n", bar[i].x, bar[i].y);
  }
}
