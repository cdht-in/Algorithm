
#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

/*
	quick select version I
int Partition (int* data, int l, int r)
{
  int pivot = l;
  int i = l;
  int j = r;
  int tmp = 0;
  while (i < j) {
    while (data[i] <= data[pivot])
      i++;
    while (data[j] > data[pivot])
      j--;
    if (i < j) {
      tmp = data[i];
      data[i] = data[j];
      data[j] = tmp;
    }
  }
  tmp = data[j];
  data[j] = data[pivot];
  data[pivot] = tmp;
  return j;
}

//O(n)
int KSmallest (int k, int* data, int l, int r)
{
  //note that split is zero-based index
  int split = Partition (data, l, r);
  //offset from the left
  int length = split - l;
  //note that
  if (length  == k - 1)
    return data[split];
  //k - 1 - length smallest in the right part
  else if (length < k - 1)
    return KSmallest (k - 1 - length, data, split + 1, r);
  else
    return KSmallest (k, data, l, split - 1);
}

*/
	
//Quick selection version II

void swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

int partition(vector<int>& vec, int l, int r, int pivot)
{
	int pivotValue = vec[pivot];
	swap(vec[r], vec[pivot]);	
	
	//everything to the left of divide is smaller than pivotValue
	int divide = l;
	while(l <= r - 1)
	{
		if(vec[l] < pivotValue)
		{
			swap(vec[l],vec[divide]);
			divide++;
		}
		l++;
	}
	//put the pivot in its final position
	swap(vec[divide],vec[r]);
	return divide;
}

//O(n) => the sum of geomeric seirs O(n) = 1 + 1/2  + 1/4 + 1/8 + ... given the good pivot selection
int KSmartest(vector<int>& vec, int k)
{
	if(vec.size() == 0)
		return 0;
	int pivot = 0;
	int l = 0;
	int r = vec.size() - 1;
	
	int p = 0;
	while(1)
	{
		p = partition(vec, l, r, pivot);
		if(p == k - 1)
		{
			break;
		}
		else if(p < k - 1)
		{
			l = p + 1;
		}
		else
		{
			r = p - 1;
		}	
	}
	return vec[p];
}


void Print(int* data, int size){
  int i = 0;
  for(; i < size; i++){
    printf("%d ",data[i]);
  }
  printf("\n");
}

//VersionI
int* QuickSortI(int* data, int l, int r){
  if(l >= r)
    return data;
  //the first one to the pivot
  int i = l;
  int j = r;
  int pivot = i;
  int tmp = 0;
  while(i < j){
    // <= to skip the pivot itself
    while(data[i] <= data[pivot])
      i++;
    while(data[j] > data[pivot])
      j--;
    if(i < j){
      tmp = data[i];
      data[i] = data[j];
      data[j] = tmp;
    }
  }
  tmp = data[pivot];
  data[pivot] = data[j];
  data[j] = tmp;
  QuickSortI(data,l,j - 1);
  QuickSortI(data,j + 1,r);
  return data;
}

//Version II
void QuickSortII(vector<int>& vec, int l, int r){
  
	if(l >= r)
		return;
	
	int p = partition(vec, l, r, l);	
	QuickSortII(vec,l, p - 1);
	QuickSortII(vec,p + 1, r);
}

int main(){
  int foo[] = {2,3,5,1,7,8,9,10,24};
  int n = sizeof(foo) / sizeof(int);
  vector<int> vec(foo, foo + n);
  
  QuickSortII(vec,0,n - 1);  
  
  for(int i = 0; i < n; i++)
  {
	  cout << vec[i] << " ";
  }
  cout << endl;
}
