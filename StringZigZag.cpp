/*
  The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

  P   A   H   N
  A P L S I I G
  Y   I   R
  And then read line by line: "PAHNAPLSIIGYIR"
  Write the code that will take a string and make this conversion given a number of rows:

  string convert(string text, int nRows);
  convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
*/


#include <iostream>
#include <string>

using namespace std;

string convert (string s, int nRows)
{
  int dif1 = s.size() / nRows;
  int dif2 = s.size() % nRows;
  int rem = s.size();
  for (int i = 0; i < nRows; i++) {
  }
      
}

int main()
{
}

