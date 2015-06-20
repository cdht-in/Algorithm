/*
	
	There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

*/

#include <iostream>

using namespace std;

//approach 1, merge two approach first then find the median, O(n) in time and space
double findMedianSortedArraysI(int A[], int m, int B[], int n) 
{
	int size = m + n;
	//merge the two array
	int C[size];
	int i = 0;
	int j = 0;
	while(i < m && j < n)
	{
		if(A[i] < B[j])
		{
			C[i + j] = A[i];
			i++;
		}
		else
		{
			C[i + j] = B[j];
			j++;
		}
	}
	
	while(i < m)
	{
		C[i + j] = A[i];
		i++;
	}
	
	while(j < n)
	{
		C[i + j] = B[j];
		j++;
	}
	
	if((size & 0x01) == 1)
	{
		return C[(size - 1) / 2];
	}
	else
	{
		return (C[(size - 1) / 2] + C[(size - 1) / 2 + 1]) / 2.0;
	}
	
}

//approach 2, improved version using O(k) time and space
double findMedianSortedArraysII(int A[], int m, int B[], int n) 
{
	int size = m + n;
	//merge the two array
	int k = (size / 2) + 1;
	int C[k];
	int i = 0;
	int j = 0;
	while(i < m && j < n)
	{
		if(A[i] < B[j])
		{
			C[i + j] = A[i];
			i++;
		}
		else
		{
			C[i + j] = B[j];
			j++;
		}
		
		if(i + j >= k - 1)
			break;		
	}
	
	while(i < m)
	{
		C[i + j] = A[i];
		i++;
		if(i + j >= k - 1)
			break;		
	}
	
	while(j < n)
	{
		C[i + j] = B[j];
		j++;
		if(i + j >= k - 1)
			break;		
	}
		
	if((size & 0x01) == 1)
	{
		return C[k - 2];
	}
	else
	{
		return (C[k - 2] + C[k - 1]) / 2.0;
	}
}





int GetKSmallest(int a[], int n, int b[], int m, int k)  
{  
     if (n <= 0) return b[k-1];  
     if (m <= 0) return a[k-1];  
     if (k <= 1) return min(a[0], b[0]);   
	
     if ((n/2 + m/2) >= k - 1)  
	 {
		 //exclude the region [m/2,m]
		 if (b[m/2] >= a[n/2])  
	     {  
			 return GetKSmallest(a, n, b, m/2, k);  
      	 }
		 //exclude the region [n/2,n]
		 else
		 {
		 	return GetKSmallest( a, n/2,b, m, k);  
		 }
		 
	 }
	 else
	 {
		 //exclude the region [n/2 + 1,n]
		 if (b[m/2] >= a[n/2])  
	     {  
			 return GetKSmallest(a + n/2 + 1, n - (n/2 + 1), b, m, k - (n/2 + 1));  
      	 }
		 //exclude the region [m/2 + 1,m]
		 else
		 {
		 	return GetKSmallest( a, n, b + m/2 + 1, m - (m/2 + 1),k - (m/2 + 1));  
		 }
	 }
} 

double findMedianSortedArrays(int A[], int m, int B[], int n) {
	if((n+m) % 2 ==0)  
	{ 
		//median of even size array is the average of (m + n)/ 2 and (m + n)/2 + 1
	  return (GetKSmallest(A,m,B,n, (m+n)/2) + GetKSmallest(A,m,B,n, (m+n)/2+1))/2.0;  
	}  
	// odd size array is the (m + n)/ + 1
	else  
	  return GetKSmallest(A,m,B,n, (m+n)/2+1);     
}


int main()
{
	int A[] = {};
	int m = sizeof(A) / sizeof(int);
	
	int B[] = {2,3};
	int n = sizeof(B) / sizeof(int);
	
	double rec = findMedianSortedArraysII(A,m,B,n);
	
	cout << rec << endl;

}