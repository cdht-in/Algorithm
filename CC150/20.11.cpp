/*
	
	Imagine you have a square matrix, where each cell is filled with either black or white. Design an algorithm to find the maximum subsquare such that all four borders are filled with black pixels.
	
*/
#include <vector>
#include <iostream>

using namespace std;


enum Color
{
	white = 0,
	black = 1
};

//approach I O(n^2)
int MaxBlackSquare(const vector<vector<Color> >& mat)
{
	//preprocess
	int n = mat.size();
	
	//process for row, longest black row starting at position i,j
	vector<vector<int> > blackRow(n,vector<int>(n,0));
	for(int i = n - 1; i >= 0; i--)
	{
		for(int j = n - 1; j >= 0; j--)
		{		
			//to right
			if(mat[i][j] == black)
			{
				if(j == n - 1)
				{
					blackRow[i][j] = 1;
				}
				else
				{
					blackRow[i][j] = blackRow[i][j + 1] + 1;
				}				
			}
		}
	}
	
	//process for col, longest black col starting at position i,j
	vector<vector<int> > blackCol(n,vector<int>(n,0));
	for(int i = n - 1; i >= 0; i--)
	{
		for(int j = n - 1; j >= 0; j--)
		{
			//to bottom
			if(mat[j][i] == black)
			{
				if(j == n - 1)
				{
					 blackCol[j][i] = 1;
				}
				else
				{
					blackCol[j][i] = blackCol[j + 1][i] + 1;
				}				
			}
			
		}
	}
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cout << blackRow[i][j] << " ";
		}	
		cout << endl;
	}
	
	cout << endl;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cout << blackCol[i][j] << " ";
		}	
		cout << endl;
	}
	
	int max = 0;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(mat[i][j] == black)
			{
				//use the topBorder to find the max square
				int topBorder = blackRow[i][j];
				
				int len = blackRow[i][j] - 1;
				
				int leftBorder = blackCol[i][j];
				
				//not a square
				if(i + len >= n)
					break;
				
				int bottomBorder = blackRow[i + len][j];
				
				//not a square
				if(j + len >= n)
					break;
				
				int rightBorder = blackCol[i][j + len];
				
				//cout << topBorder << " " << leftBorder << " " << bottomBorder << " " << rightBorder << endl;
				//if it is a square
				if(topBorder <= leftBorder && topBorder <= bottomBorder && topBorder <= rightBorder)
				{
					int area = topBorder * topBorder;
					if(area > max)
						max = area;
				}
			}
		}
	}
	
	return max;
}


int main()
{
	int n = 2;
	vector<vector<Color> > mat(n,vector<Color>(n,black));
	
	mat[1][0] = white;
	
	/*
	mat[1][1] = black;
	mat[1][2] = black;
	mat[2][1] = black;
	mat[2][2] = black;
	
	mat[0][0] = black;
	mat[0][1] = black;
	mat[0][2] = black;
	*/
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cout << mat[i][j] << " ";
		}	
		cout << endl;
	}
	
	cout << endl;
	cout << MaxBlackSquare(mat) << endl;
}