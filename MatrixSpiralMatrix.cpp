/*

Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].
	
*/
#include <vector>
#include <iostream>

using namespace std;

bool IsEnd(vector<vector<bool> > &visited,int i, int j, int m, int n) 
{
	if(i < 0 || i >= m || j < 0 || j >= n)
		return true;
	
	bool topBlocked = true;
	if(i > 0)
	{
		topBlocked = (visited[i - 1][j] == true)? true : false;
	}
	
	bool rightBlocked = true;
	if(j < n - 1)
	{
		rightBlocked = (visited[i][j + 1] == true)? true : false;
	}
	
	bool bottomBlocked = true;
	if(i < m - 1)
	{
		bottomBlocked = (visited[i + 1][j] == true)? true : false;
	}
	
	bool leftBlocked = true;
	if(j > 0)
	{
		leftBlocked = (visited[i][j - 1] == true)? true : false;
	}
	
	return topBlocked && rightBlocked && bottomBlocked && leftBlocked;
}

vector<int> spiralOrder(vector<vector<int> > &mat) {
	vector<int> result;
	if(mat.size() == 0 || mat[0].size() == 0)
		return result;
	
	int m = mat.size();
	int n =  mat[0].size();
	int i = 0;
	int j = 0;
	vector<vector<bool> > visited(m, vector<bool>(n, false));
	while(1)
	{
		//move right
		while(j < n && visited[i][j] == false)
		{
			result.push_back(mat[i][j]);
			visited[i][j] = true;
			j++;
		}
		j--;
		if(IsEnd(visited,i,j,m,n))
			break;
		i++;
				
		//move down
		while(i < m && visited[i][j] == false)
		{
			result.push_back(mat[i][j]);
			visited[i][j] = true;
			i++;
		}
		
		i--;		
		if(IsEnd(visited,i,j,m,n))
			break;
		j--;
		
		
		//move left
		while(j >= 0 && visited[i][j] == false)
		{
			result.push_back(mat[i][j]);
			visited[i][j] = true;
			j--;;
		}
		
		j++;
		if(IsEnd(visited,i,j,m,n))
			break;
		i--;
		
		
		//move up
		while(i >= 0 && visited[i][j] == false)
		{
			result.push_back(mat[i][j]);
			visited[i][j] = true;
			i--;;
		}
		
		i++;
		if(IsEnd(visited,i,j,m,n))
			break;
		j++;
	}
	
	return result;	   
}

int main()
{
	vector<vector<int> > mat;
	mat.push_back(vector<int>(1,3));
	mat.push_back(vector<int>(1,2));
	vector<int> vec = spiralOrder(mat);
	for(int i = 0; i < vec.size(); i++)
		cout << vec[i] << " ";
	cout << endl;
}