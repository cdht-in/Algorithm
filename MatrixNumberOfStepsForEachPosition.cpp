/*

	given a matrix where each B cell is for a block and G cell is for a gaurd, compute the minimal distance to other cells.
	
*/
#include <vector>
#include <queue>
#include <climits>
#include <iostream>

using namespace std;

#define x first
#define y second
#define MakePair(x,y) make_pair<int,int>(x,y)

typedef vector<vector<char> > Matrix;
typedef vector<vector<int> > Distant;

typedef pair<int,int> Pair;

void MinDistance(Matrix& mat)
{
	int m = mat.size();
	int n = mat[0].size();
	
	Distant distant(m,vector<int>(n,INT_MAX));;
	
	//find the gaurd position
	vector<Pair> gaurdPos;
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(mat[i][j] == 'G')
			{
				gaurdPos.push_back(MakePair(i,j));
				distant[i][j] = 0;
			}			
		}
	}
	
	queue<Pair> q;
	for(int i = 0; i < gaurdPos.size(); i++)
	{
		int cur = 1;
		int next = 0;
		int level = 0;
		Matrix visited(m,vector<char>(n,'0'));
		q.push(gaurdPos[i]);
		
		while(q.empty() == false)
		{
			Pair head = q.front();
			q.pop();
			cur--;
			int row = head.x;
			int col = head.y;
			
			if(row >= 1 && mat[row - 1][col] != 'B' && visited[row - 1][col] == '0')
			{
				q.push(MakePair(row - 1, col));
				next++;
			}
			
			if(col >= 1 && mat[row][col - 1] != 'B' && visited[row][col - 1] == '0')
			{
				q.push(MakePair(row, col - 1));
				next++;
			}
		
			if(row < m - 1 && mat[row + 1][col] != 'B' && visited[row + 1][col] == '0')
			{
				q.push(MakePair(row + 1, col));	
				next++;
			}
			
			if(col < n - 1 && mat[row][col + 1] != 'B' && visited[row][col + 1] == '0')
			{
				q.push(MakePair(row, col + 1));	
				next++;
			}
			
			distant[row][col] = (distant[row][col] < level)?  distant[row][col] : level;
			
			if(cur == 0)
			{
				level++;
				cur = next;
				next = 0;
			}
			
			visited[row][col] = '1';
		}
	}

	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{	
			if(distant[i][j] == INT_MAX)
			{
				cout << 9 << " ";
			}
			else
				cout << distant[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	int m = 4;
	int n = 4;
	Matrix mat(m,vector<char>(n,'.'));
	mat[0][1] = 'B';
	mat[1][2] = 'G';
	mat[2][1] = 'G';
	
	MinDistance(mat);
}