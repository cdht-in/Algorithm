/*
	
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6.

*/
#include <iostream>

using namespace std;


int maxSubArray(int A[], int n) {
	
	if(n == 0)
		return 0;
	if(n == 1)
		return A[0];
	
	int max = A[0];
	int submax = A[0];
	
	int r = 0;
	int l = 0;
	for(int i = 1; i < n; i++)
	{
		//The changing condition for dynamic programming is "We should ignore the sum of the previous n-1 elements if nth element is greater than the sum."
		if(A[i] >= submax + A[i])
		{
			cout << "sadsa" << endl;
			submax = A[i];
		}
		else
		{
			submax += A[i];
		}
		
		if(submax >= max)
		{
			max = submax;
			r = i;
		}
	}
	cout << "l: " << l << " r: " << r << endl;
	return max;
	
	/*
	int sum = 0;  
	int max = INT_MIN;  
	for(int i = 0; i < n ; i ++)  
	{  
	  sum +=A[i];        
	  if(sum>max)  
	     max = sum;  
	   if(sum < 0)  
	     sum = 0;  
	 }  
	 return max;  
	*/
	 
}









































//third implementation
int maxSubArrayI(int A[], int n) {
	int sum = INT_MIN;
	int subSum = 0;
	for(int i = 0; i < n; i++)
	{
		//if the previous is smaller than A[i] it could be replaced with Ap[i]
		if(subSum + A[i] < A[i])
		{
			subSum = A[i];
		}
		else
		{
			subSum += A[i];
		}
		
		if(subSum > sum)
			sum = subSum;
	}
	return sum;
}


int Max(int a,int b, int c)
{
	a = (a > b)? a : b;
	a = (a > c)? a : c;
	return a;
}


//Divide and conquer O(nlogn)
int maxSubArrayI(int A[],int l, int r)
{	
	if(l == r)
	{
		return A[l];
	}
	
	int mid = (l + r) / 2;
	
	int lSum = maxSubArrayI(A,l,mid);
	
	int rSum = maxSubArrayI(A,mid + 1,r);
			
	//midSum
	int sum = INT_MIN;
	int tmpl = 0;
	for(int i = mid; i >= l; i--)
	{
		tmpl += A[i];
		if(tmpl > sum)
			sum = tmpl;
	}
	tmpl = sum;
	
	sum = INT_MIN;
	int tmpr = 0;
	for(int i = mid + 1; i <= r; i++)
	{
		tmpr += A[i];
		if(tmpr > sum)
			sum = tmpr;
	}
	tmpr = sum;
	
	sum = Max(tmpl,tmpr, tmpl + tmpr);
	
	sum = Max(lSum,sum,rSum);
	
	return sum;
}


int main(){
	
	int foo[] = {-1,-2,4};
	int size = sizeof(foo) / sizeof(int);
	cout << maxSubArrayI(foo,0,size - 1) << endl;
	
}