/*
  Given an index k, return the kth row of the Pascal's triangle.

  For example, given k = 3,
  Return [1,3,3,1].

  Note:
  Could you optimize your algorithm to use only O(k) extra space?
*/

#include <iostream>
#include <vector>

using namespace std;

/*
vector<int> nRowPascal (int n)
{
  vector<int> nRow;
  for (int i = 0; i <= n; i++) {
    for (int j = i - 1; j > 0; j--) {
      nRow[j] += nRow[j - 1];
    }
    nRow.push_back (1);
  }
  return nRow;
}
*/


//second implementation

vector<int> getRow(int rowIndex) {
	
    vector<int> nRow;
    for (int i = 0; i <= rowIndex; i++) {
      for (int j = i - 1; j > 0; j--) {
        nRow[j] += nRow[j - 1];
      }
      nRow.push_back (1);
    }
    return nRow;
}

int main()
{
  vector<int> foo = nRowPascal (3);
  for (int i = 0; i < foo.size(); i++) {
    cout << foo[i] << " ";
  }
  cout << endl;
}
