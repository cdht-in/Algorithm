/*
	Given an image represented by an NxN matrix, where each pixel in the image is 4 bytes, write a method to rotate the image by 90 degrees. Can you do this in place?

*/

#include <iostream>
using namespace std;

void swap(int &a, int &b){
    int t = a;
    a = b;
    b = t;
}

//counter clockwise,swap the diagnol and swap against the x-axis
void transpose(int a[][4], int n){
    for(int i=0; i<n; ++i)
        for(int j= i + 1; j<n; ++j)
            swap(a[i][j], a[j][i]);
	
    for(int i=0; i<n/2; ++i)
        for(int j=0; j<n; ++j)
            swap(a[i][j], a[n-1-i][j]);
}

//clockwise, swap the diagnol and swap against the y-axis
void transposeI(int a[][4], int n)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			swap(a[i][j],a[j][i]);
		}
	}
	
	for(int i = 0; i < n / 2; i++)
	{
		for(int j = 0; j < n; j++)
		{
			swap(a[j][i],a[j][n - 1 - i]);
		}
	}
}

int main()
{
	int n = 4;
	int a[4][4] = 
	{
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12},
		{13, 14, 15, 16}
	};
	for(int i=0; i<n; ++i){
	    for(int j=0; j<n; ++j)
	        cout<<a[i][j]<<" ";
	    cout<<endl;
	}
	cout<<endl;
	transposeI(a, n);
	for(int i=0; i<n; ++i){
	    for(int j=0; j<n; ++j)
	        cout<<a[i][j]<<" ";
	    cout<<endl;
	}
	return 0;
	
}