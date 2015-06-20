#include <vector>
#include <iostream>
#include <cstring>
#include <cstdio>

void PrintData(int* data, int size){
  for(int i = 0; i < size; i++){
    printf("%d ",data[i]);
  }
}


int* MergeSort(int* data, int size){

  if(size <= 1)
    return data;
  int mid = size / 2;
  //create the first half
  int s1 = mid;
  int* f = new int[s1];
  memcpy(f,data,s1 * sizeof(int));
  int s2 = size - mid;
  int* s = new int[s2];
  memcpy(s,data + s1,s2 * sizeof(int));
  int* Fhalf = MergeSort(f,s1);
  int* Shalf = MergeSort(s,s2);
  int* result = new int[s1 + s2];
  int i = 0;
  int j = i;
  //merge
  for(;i < s1 && j < s2;){
    if(Fhalf[i] < Shalf[j]){
      result[i + j] = Fhalf[i];
      i++;
    }
    else{
      result[i + j] = Shalf[j];
      j++;
    }
  }
  if(i < s1){
    while(i < s1){
      result[i + j] = Fhalf[i];
      i++;
    }
  }
  else{
    while(j < s2){
      result[i + j] = Shalf[j];
      j++;
    }
  }
  delete[] f;
  delete[] s;
  return result;
  
}

std::vector<int> MergeSort(std::vector<int> data){
  if (data.size() <= 1)
    return data;
  int mid = data.size() / 2;
  std::vector<int> fh = MergeSort(std::vector<int>(data.begin(),data.begin() + mid));
  std::vector<int> sh = MergeSort(std::vector<int>(data.begin() + mid,data.end()));
  //Merge
  std::vector<int>::iterator f = fh.begin();
  std::vector<int>::iterator s = sh.begin();
  std::vector<int> result;
  while(f != fh.end() && s != sh.end()){
    if(*f < *s){
      result.push_back(*f);
      f++;
    }
    else{
      result.push_back(*s);
      s++;
    }
  }
  if(f != fh.end())
    {
      while(f != fh.end()){
	result.push_back(*f);
	f++;
      }
    }
  else{
    while(s != sh.end()){
      result.push_back(*s);
      s++;
    }
  }
  return result;
}

int main(){
  int foo[] = {1,3,2,4,5,10,7,11,2};
  PrintData(foo,sizeof(foo) / sizeof(int));
  printf("\n");
  
  std::vector<int> bar(foo,foo + sizeof(foo) / sizeof(int));
  bar = MergeSort(bar);
  for(std::vector<int>::iterator i = bar.begin(); i != bar.end();i++){
    std::cout << *i << " ";
  }
  std::cout << std::endl;
  int* bar1 = MergeSort(foo,sizeof(foo) / sizeof(int));
  PrintData(bar1,sizeof(foo) / sizeof(int));
  printf("\n");
}
