/*
  detect two overlapping rectanglars

  Question: Axis­Aligned Rectangles
  Describe an algorithm that takes an unsorted array of axis‐aligned rectangles and 
  returns any pair of rectangles that overlaps, if there is such a pair.  Axis‐aligned 
  means that all the rectangle sides are either parallel or perpendicular to the x‐ and 
  y‐axis.  You can assume that each rectangle object has two variables in it: the x‐y 
  coordinates of the upper‐left corner and the bottom‐right corner.

*/

#include <cstdio>

struct Rec{
  //coordinate
  int topleft[2];
  int bottomright[2];
  Rec(int x1,int y1,int x2,int y2){
    topleft[0] = x1;
    topleft[1] = y1;
    bottomright[0] = x2;
    bottomright[1] = y2;
  }
};

bool isOverlapped(Rec* a,Rec* b){
  int length = a->bottomright[0] - a->topleft[0];
  int width = a->topleft[1] - a->bottomright[1];
  
  /*
    A's Left Edge to left of B's right edge  And
    A's right edge to right of B's left edge And
    A's top above B's bottom And
    A's bottom below B's Top
  */
  
  if(a->topleft[0] < b->bottomright[0] && a->bottomright[0] > b->topleft[0] &&
     a->topleft[1] > b->bottomright[1] && a->bottomright[1] < b->topleft[1]
     )
    return true;
  return false;
}
  
int main(){
  Rec foo(1,4,3,2);
  Rec bar(2,6,5,3);
  printf("%d\n",isOverlapped(&foo,&bar));
}

