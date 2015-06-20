/*
  Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

  For example, given the following triangle

  [
  [2],
  [3,4],
  [6,5,7],
  [4,1,8,3]
  ]
  The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

  Note:
  Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
*/

#include <vector>
#include <iostream>

using namespace std;

//O(n^2)
//find the min at each level, the sum would be the minimal
int MinSum(const vector<vector<int> >& data){
  int sum = 0;
  for(int i = 0; i < data.size(); i++){
    int Max = 99;
    for(int j = 0; j < data[i].size(); j++){
      if(data[i][j] < Max)
	Max = data[i][j];
    }
    sum += Max;
  }
  return sum;
}

int main(){
  vector<vector<int> > foo;
  vector<int> a1(1,2);
  int b1[] = {3,4};
  vector<int> a2(b1,b1 + sizeof(b1) / sizeof(int));
  int b2[] = {6,5,7};
  vector<int> a3(b2,b2 + sizeof(b2) / sizeof(int));
  int b3[] = {4,1,8,3};
  vector<int> a4(b3,b3 + sizeof(b3) / sizeof(int));
  foo.push_back(a1);
  foo.push_back(a2);
  foo.push_back(a3);
  foo.push_back(a4);

  for(int i = 0; i < foo.size(); i++){
    for(int j = 0; j < foo[i].size(); j++)
      cout << foo[i][j] << " ";
    cout << endl;
  }

  cout << "min is " << MinSum(foo) << endl;
}

	   
