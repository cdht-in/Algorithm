/*
	
	Write an algorithm such that if an element in an MxN matrix is 0, its entire row and column is set to 0.

*/

#include <vector>

using namespace std;

void zero(int **a, int m, int n){
    bool row[m], col[n];    
    memset(row, false, sizeof(row));
    memset(col, false, sizeof(col)); 
    for(int i=0; i < m; ++i)
        for(int j=0; j < n; ++j)
            if(a[i][j] == 0){
                row[i] = true;
                col[j] = true;
            }
			
	
    for(int i=0; i<m; ++i)
        for(int j=0; j<n; ++j)
            if(row[i] || col[j])
                a[i][j] = 0;
}

int main()
{
	
	
}