/*

  Minimal coins to sum up to a sum

*/

#include <cstdio>

int Min[101];

int Denomination[5] = {1,5,10,50,100};

int MinCoin(int Sum){
  //base case: 0 coins for $0
  if(Sum == 0)
    return 0;
  int n = 0;
  int i = 4;
  //start with the largest denomination first since it gaurantees the minimum number of bills
  for(;i >= 0;i--){
    n = Sum / Denomination[i];
    if(n > 0)
      {
	//record the number of this bill
	Min[Denomination[i]] = n;
	break;
      }
  }
  //recursively solve for the remaining value
  return n + MinCoin(Sum % Denomination[i]);
}


int main(){
  for(int i = 0; i < 101; i++)
    Min[i] = 0;
  int Sum = 21;
  printf("%d\n",MinCoin(Sum));
  for(int i = 0; i < 101; i++){
    if(Min[i] != 0){
      for(int j = 0; j < Min[i]; j++)
	printf("%d  ",i);
    }
  }
  printf("\n");
}
