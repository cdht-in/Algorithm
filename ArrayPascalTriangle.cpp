/*
  Given numRows, generate the first numRows of Pascal's triangle.

  For example, given numRows = 5,
  Return

  [
  [1],
  [1,1],
  [1,2,1],
  [1,3,3,1],
  [1,4,6,4,1]
  ]

*/

#include <iostream>
#include <vector>

using namespace std;

/*

first implementation

void PascalTriangle (int n)
{
  int** data = new int*[n];
  for (int i = 0; i < n ; i++) {
    data[i] = new int[n];
  }
  //each row is one more element than the above row
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i + 1; j++) {
      //the first and last of each row is 1
      if (j == 0 || j == i)
        data[i][j] = 1;
      else
        //the value is the sum of two values above it
        data[i][j] = data[i - 1][j - 1] + data[i - 1][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i + 1; j++) {
      cout << data[i][j] << " ";
    }
    cout << endl;
  }
}

vector<vector<int> > generate (int numRows)
{
  vector<vector<int> > data;
  for (int i = 0; i < numRows; i++) {
    data.push_back (vector<int>() );
  }
  //each row is one more element than the above row
  for (int i = 0; i < numRows; i++) {
    for (int j = 0; j < i + 1; j++) {
      //the first and last of each row is 1
      if (j == 0 || j == i)
        data[i].push_back (1);
      else
        //the value is the sum of two values above it
        data[i].push_back (data[i - 1][j - 1] + data[i - 1][j]);
    }
  }
  return data;
}

*/

//second implemenation
vector<vector<int> > generate(int numRows) {
	vector<vector<int> > result;
	if(numRows == 0)
		return result;
	
	vector<int> row;
	row.push_back(1);
	result.push_back(row);
	
	if(numRows == 1)
	{
		return result; 
	}
	
	for(int i = 1; i < numRows; i++)
	{
		vector<int> row;
		row.push_back(1);
		
		for(int j = 1; j < i; j++)
		{
			row.push_back(result[i - 1][j - 1] + result[i - 1][j]);
		}
		
		row.push_back(1);
		
		result.push_back(row);
	}
	
	return result;
}

int main()
{
  generate (3);
}
