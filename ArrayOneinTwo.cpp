/*
  Question: Odd Man Out You're given an unsorted array of integers where every integer appears exactly twice, except for one integer which appears only once.  Write an algorithm (in a language of your choice) that finds the integer that appears only once.
*/

#include <cstdio>
#include <set>

//using xor, since xor is communative, so every pair of the same integer would result in 0

//O(n) time and O(1) space
int FindUnique(int* data,int size){
  int unq = 0;
  for(int i=0;i<size;i++){
    unq ^= data[i];
  }
  return unq;
}

//use a hashset to keep track of seen ones
//O(n) time and O(n) space
int FindUnique1(int* data,int size){
  std::set<int> set;  
  int Sum = 0;
  std::pair<std::set<int>::iterator,bool> ret;
  for(int i = 0;i < size;i++){
    //in the set
    ret = set.insert(data[i]);
    if(ret.second == false)
      Sum += data[i];
    else
      Sum -= data[i];
  }
  return Sum;
}


int main(){
  int foo[] = {1,1,3,3,55,2,2,55,5};
  printf("%d\n",FindUnique(foo,9));
}
