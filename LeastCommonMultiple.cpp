#include <cstdio>

int LeastCommonMultiple(int x, int y){
  int smaller = 0;
  int bigger = 0;
  if(x <= y){
    smaller = x;
    bigger = y;
  }
  else{
    smaller = y;
    bigger = x;
  }

  if(bigger % smaller == 0)
    return bigger;
  else
    return bigger * smaller;
}

int main(){
  printf("LMM is %d\n",LeastCommonMultiple(2,23));
}
