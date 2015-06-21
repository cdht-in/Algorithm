#include <vector>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

/*
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

*/

/*
bool operator==(vector<int>& a,vector<int>& b)
{
	if(a.size() != b.size())
		return false;
	for(int i = 0; i < a.size(); i++)
	{
		if(a[i] != b[i])
			return false;
	}
	return true;
}
*/

ostream& operator<<(ostream& out, vector<int>& vec){
	for(int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << " ";
	}
	cout << endl;
	return out;
}

vector<int> Merge(vector<int>& a,vector<int>& b)
{
	vector<int> c;
	int i = 0;
	int j = 0;
	while(i < a.size() && j < b.size())
	{
		if(a[i] <= b[j])
		{
			c.push_back(a[i]);
			i++;
		}
		else
		{
			c.push_back(b[j]);
			j++;
		}
	}
	
	if(i == a.size())
	{
		while(j < b.size())
		{
			c.push_back(b[j]);
			j++;
		}
	}
	else
	{
		while(i < a.size())
		{
			c.push_back(a[i]);
			i++;
		}
	}
	
	return c;
}

vector<int> MergeSortHelper(vector<int>& vec,int l, int r)
{
	if(l == r)
	{
		vector<int> part;
		part.push_back(vec[l]);
		return part;
	}
	
	int mid = (l + r) / 2;
	vector<int> lPart = MergeSortHelper(vec,l,mid);
	vector<int> rPart = MergeSortHelper(vec,mid + 1,r);	
	
	return Merge(lPart,rPart);
}

//top down mergeSort
void MergeSort(vector<int>& vec)
{
	
	vector<int> sorted = MergeSortHelper(vec,0,vec.size() - 1);
	
	if(is_sorted(sorted.begin(),sorted.end()))
	{
		cout << "merge sort is correct" << endl;
	}
	else
	{
		cout << sorted << endl;
		cout << "something wrong with the merge sort" << endl;
	}	
}

void MergeI(vector<int>& vec,vector<int>& aux,int l, int mid, int r)
{
	copy(vec.begin(),vec.end(),aux.begin());
	int i = l, j = mid + 1;
	for (int k = l; k <= r; k++) 
	{
		if(i > mid)
			vec[k] = aux[j++];  // this copying is unneccessary
		else if (j > r)      
			vec[k] = aux[i++];
		else if (aux[j] < aux[i])
			vec[k] = aux[j++];
		else      
			vec[k] = aux[i++];
	}
}

//bottom up
void MergeSortBU(vector<int>& vec)
{
	int N = vec.size();
	vector<int> aux(N,0);
	for (int n = 1; n < N; n *= 2) 
	{
		for (int i = 0; i < N - n; i += 2 * n) 
		{
			int l = i;
			int r = std::min(i + 2*n - 1,N - 1);
			int mid = i + n - 1;		
			MergeI(vec,aux,l,mid,r);
		}
	}
	
	if(is_sorted(vec.begin(),vec.end()))
	{
		cout << "merge sort is correct" << endl;
	}
	else
	{
		cout << "something wrong with the merge sort" << endl;
	}
}

int main()
{
	//vector<int> vec({2,1});
 	vector<int> vec({1,3,2,4,5,10,7,11,2});
	MergeSortBU(vec);
}
  
