/*
  implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

  If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

  The replacement must be in-place, do not allocate extra memory.

  Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
  1,2,3 → 1,3,2
  3,2,1 → 1,2,3
  1,1,5 → 1,5,1
*/
#include <vector>
#include <iostream>

using namespace std;

/*

From the wikipedia, one classic algorithm to generate next permutation is:
Step 1: Find the largest index k, such that A[k]<A[k+1]. If not exist, this is the last permutation. (in this    problem just sort the vector and return.)
Step 2: Find the largest index l, such that A[l]>A[k].
Step 3: Swap A[k] and A[l].
Step 4: Reverse A[k+1] to the end.
	
*/

//math problem

void nextPermutation(vector<int> &num) {
	int n = num.size();
	int k = -1;
	int l;
	//step1
	for (int i = 0;i< n -1;i++){
	    if (num[i] < num[i+1]){
	        k = i;
	    }
	}
	//decresing sequence, the last permuation
	if (k == -1){
		reverse(num.begin(),num.end());
	    return;
	}
   	//step2
	for (int i = k+1;i<n;i++){
	    if (num[i] > num[k]){
	        l = i;
	    }
	}
	//step3        
	int tmp = num[l];
	num[l]=num[k];
	num[k]=tmp;
	//step4
	reverse(num.begin() + k + 1,num.end());
}

int main()
{
	int foo[] = {1,3,2};
		//{5,4,7,5,3,2};
	int n = sizeof(foo) / sizeof(int);
	vector<int> vec(foo, foo + n);
	nextPermutation(vec);
	for(int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << " ";
	}
	cout << endl;
}
