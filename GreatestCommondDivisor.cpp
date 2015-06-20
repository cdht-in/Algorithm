#include <cstdio>


int GreatestCommonDivisor(int x,int y){
  int smaller = 0;
  int bigger = 0;
  if(x >= y)
    {
      bigger = x;
      smaller = y;
    }
  else{
    bigger = y;
    smaller = x;
  }
  if(bigger % smaller == 0)
    return smaller;
  else
    return GreatestCommonDivisor(bigger - smaller, smaller);
}


int main(){
  printf("GCD of %d and %d is %d\n",101,4,GreatestCommonDivisor(101,4));
  printf("%d",0 % 0);
}
