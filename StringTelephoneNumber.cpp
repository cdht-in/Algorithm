/*
  get a telephone number in string, generate all combination

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char** keyboard;

void GenerateChar (int* number, int pos, int n, char* map)
{
  if (pos == n) {
    printf ("%s\n", map);
    return;
  }
  int j;
  for (j = 0; keyboard[number[pos]][j] != '\0'; j++) {
    map[pos] = keyboard[number[pos]][j];
    GenerateChar (number, pos + 1, n, map);
  }
}

*/

#include <string>

vector<string> letterCombinations(string digits) {

}

/*
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

*/

vector<string> letterCombinations(string digits) {

}
int main()
{
  /*
  int ndigits = 10;
  keyboard = ( char**) malloc (ndigits * sizeof (char**) );
  keyboard[0] = (char*) malloc (2 * sizeof (char) );
  keyboard[0][1] = '\0';
  keyboard[1] = (char*) malloc (2 * sizeof (char) );
  keyboard[1][1] = '\0';
  int i;
  for (i = 2; i < ndigits; i++) {
    keyboard[i] = (char*) malloc (4 * sizeof (char) );
    keyboard[i][3] = '\0';
  }
  memcpy (keyboard[0], "0", 1);
  memcpy (keyboard[1], "1", 1);
  memcpy (keyboard[2], "ABC", 3);
  memcpy (keyboard[3], "DEF", 3);
  memcpy (keyboard[4], "GHI", 3);
  memcpy (keyboard[5], "JKL", 3);
  memcpy (keyboard[6], "MNO", 3);
  memcpy (keyboard[7], "PRS", 3);
  memcpy (keyboard[8], "TUV", 3);
  memcpy (keyboard[9], "WXY", 3);
  int number[] = {8};
  int n = sizeof (number) / sizeof (int);
  char map[n + 1];
  map[n] = '\0';
  GenerateChar (number, 0, n, map);
  for (i = 0; i < ndigits; i++) {
    free (keyboard[i]);
  }
  free (keyboard);
  */
}
