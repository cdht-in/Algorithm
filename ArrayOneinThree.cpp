/*
  Given an array of integers, every element appears twice except for one. Find that single one.
*/


#include <cstdio>

//same number XOR to zero
int SingleNumer(int* a, int size){
  int ret = 0;
  for(int i = 0; i < size; i++){
    ret ^= a[i];
  }
  return ret;
}


/*
  Given an array of integers, every element appears three times except for one. Find that single one.
*/

int SingleNumerII(int* a, int size){
  int ones = 0;
  int twos = 0;
  int commonbit = 0;
  for(int i = 0; i < size; i++){
    //turn on the bits that appear even number of times
    twos |= (a[i] & ones);
    //record the bits that appear odd number of times
    ones ^= a[i];
    //get the common bits of ones and twos
    commonbit = ~(ones & twos);
    //turns off those common bits in ones
    ones &= commonbit;
    //turns off those common bits in twos
    twos &= commonbit;
  }
  return ones;
  
}

int main(){
  int foo[] = {2,3,3,3,2,2,5,4,4,4,1,1,1};
  printf("%d\n",SingleNumerII(foo,sizeof(foo) / sizeof(int)));
}
