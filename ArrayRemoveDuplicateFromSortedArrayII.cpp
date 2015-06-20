/*
  remove duplicate from a non sorded array
*/
#include <unordered_set>
#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

/*
first implementation

int RemoveDuplicates (int* data, int size, int* out)
{
  if (size <= 1)
    return 0;
  std::unordered_set<int> set;
  int a = 0;
  for (int i = 0; i < size; i++) {
    if (set.find (data[i]) == set.end() ) {
      out[a++] = data[i];
      set.insert (data[i]);
    }
  }
  return a;
}

//assumption is that the array is all positive, and we can use it this method to find the duplicates
void PrintDuplicate (int* a, int size)
{
  for (int i = 0; i < size; i++) {
    if (a[abs (a[i])] >= 0) {
      //printf("%d\n",a[abs(a[i])]);
      a[abs (a[i])] = -a[abs (a[i])];
    }
    else
      printf ("%d ", a[i]);
  }
  printf ("\n");
}


  Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?
For example,
  Given sorted array A = [1,1,1,2,2,3],
  Your function should return length = 5, and A is now [1,1,2,2,3]

int removeDuplicatesII (int A[], int n)
{
  //no duplicates
  if (n <= 1)
    return n;
  int p = 0;
  int i = 0;
  while(i < n){
    int c = 0;
    while(i < n - 1 && A[i] == A[i + 1]){
      i++;
      c++;
    }
    if(c >= 1){
      //at least two duplicates
      A[p++] = A[i];
      A[p++] = A[i];
    }
    else
      //no duplicates
      A[p++] = A[i];
    i++;
  }
  return p;
}

*/

//second implementation

int removeDuplicates(int A[], int n) {
	if(n <= 2)
		return n;
	int insertP = 0;
	for(int i = 0; i < n; i++)
	{
		int c = 0;
		while(i + 1 < n && A[i] == A[i + 1])
		{
			c++;
			i++;
		}
		
		//more than two duplicates
		if(c >= 1)
		{
			//copy only two
			for(int k = 0; k < 2; k++){
				A[insertP++] = A[i];
			}
		}
		else
		{
			A[insertP++] = A[i];
		}
	}
	return insertP;
}


int main()
{
  int foo[] = {1,1,1,1,2,2,3,4,5,6,6,6,7};
  int len = removeDuplicates (foo, sizeof(foo) / sizeof(int));
  for(int i = 0; i < len; i++)
    cout << foo[i] << " ";
  cout << endl;
}


