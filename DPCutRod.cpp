/*
  give a rod of length n, try to maximize the profit, DP approach

*/

#include <cstdio>


//for length i, the price is Price[i]
const int Price[6] = {0,1,5,8,9,10};

static int Max = 0;
static int* MaxSub;


//O(n^2)
int MaxProfit(int Rlen){
  if(Rlen <= 1)
    return MaxSub[Rlen];
  for(int i = 1;i <= Rlen; i++){
    //if the leftmost cut is length i, the new maxsub is the the bigger of those two
    int tmp = MaxProfit(Rlen - i);
    //MaxSub[i] uses the value previously calculated
    if(MaxSub[i] + tmp > MaxSub[Rlen])
      MaxSub[Rlen] = MaxSub[i] + tmp;
  }
  return MaxSub[Rlen];
}


int main(){
  int Rlen = 4;
  MaxSub = new int[Rlen];
  for(int i = 0; i <= Rlen; i++)
    MaxSub[i] = Price[i];
  printf("%d\n",MaxProfit(Rlen));
}
