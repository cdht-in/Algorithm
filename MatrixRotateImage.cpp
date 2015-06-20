/*
	
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?

*/

#include <vector>

using namespace std;

/*
	
如下图，首先沿逆对角线翻转一次，然后按x轴中线翻转一次。
http://fisherlei.blogspot.com/2013/01/leetcode-rotate-image.html
	
*/

void swap(int& a1, int&a2)  
{  
  int temp = a1;  
  a1=a2;  
  a2=temp;  
}  

void rotate(vector<vector<int> > &matrix) {
	//n x n matrix
	int n = matrix[0].size();  
	for(int i = 0; i < n - 1; i++)  
	{  
	  	for(int j = 0; j < n - i;j++)  
	  	{  
	    	swap(matrix[i][j], matrix[n - 1 - j][n - 1 - i]);  
	   	}  
	}  
	 
	for(int i = 0; i< n / 2; i++)  
	{  
	   for(int j = 0;j < n; j++)  
	   {  
	     swap(matrix[i][j], matrix[n - i - 1][j]);  
	   }  
	 } 
	  
}

int main()
{
	
	
}