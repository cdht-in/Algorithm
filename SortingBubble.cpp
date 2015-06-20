/*
bubble sort
*/

#include <cstdio>

void Swap(int* a, int* b){
  int tmp = 0;
  tmp = *a;
  *a = *b;
  *b = tmp;
}

//O(n^2)
void BubbleSort(int* data, int len){
  for(int i = 0; i < len - 1; i++){
    for(int j = i + 1; j < len; j++){
      if(data[i] > data[j])
	Swap(data + i, data + j);
    }
  }
}

int main()
{
  int foo[] = {1,2,4,5,6,3,3,3,10};
  int len = sizeof(foo) / sizeof(int);
  BubbleSort(foo,len);
  for(int i = 0; i < len; i++)
    printf("%d ",foo[i]);
  printf("\n");
}
