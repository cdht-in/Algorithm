/*
  O(n*k) algorithm to generate least # of coins for the amount n

*/


#include <cstdio>
#include <algorithm>
#include <cstring>


int Notes[] = {1,5,10,25};

int Coins[4];

int globalmin = 99;

//try out all the combinations
void Changes(int n,int index,int k){
  //reach the smallest denomination
  if(index < 1){
    Coins[index] = n ;
    //count if this is the minimal
    int min = 0;
    for(int j = 0;j < k; j++)
      min += Coins[j];
    globalmin = std::min(globalmin,min);
    return;
  }
  //start with the largest deminomination, try every possible combinations
  for(int i = n / Notes[index]; i >=0; i--){
    //fill in # of largest denomination
    Coins[index] = i;
    //calculate the remainning
    Changes(n - i *  Notes[index],index - 1,k);
  }
}

int main(){
  Changes(65,sizeof(Notes) / sizeof(int) - 1,sizeof(Notes) / sizeof(int));
  printf("min is %d\n",globalmin);
  
}
