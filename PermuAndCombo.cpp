#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <unordered_set>

using namespace std;

void Swap (char* x, char* y)
{
  char tmp;
  tmp = *x;
  *x = *y;
  *y = tmp;
}

//O(n * n!)
void Permutation (char* s, int size)
{
  if (s[0] == '\0') {
    printf ("%s\n", s - size);
    return;
  }
  int i;
  for (i = 0; s[i] != '\0'; i++) {
    Swap (s, s + i);
    Permutation (s + 1, size);
    Swap (s, s + i);
  }
}

/*
void PermutationWithoutDuplicate (char* s, int size)
{
  if (s[0] == '\0') {
    printf ("%s\n", s - size);
    return;
  }
  int i;
  for (i = 0; s[i] != '\0'; i++) {
    Swap (s, s + i);

    Permutation (s + 1, size);
    Swap (s, s + i);
  }
  }*/



//O(n!) n choose k
void NchooseK (int start, int n, int k, vector<int> tmp, vector<vector<int> >& container)
{
  //choose 0 from n, in other words, already got the proper subset
  if (k == 0) {
    container.push_back (tmp);
    return;
  }
  //start with the first element
  for (int i = start; i <= n; i++) {
    //fix the first number position
    tmp.push_back (i);
    NchooseK (i + 1, n, k - 1, tmp, container);
    tmp.pop_back();
  }
}

//all combinaiton with no N at the front
void PrintComboNotStartingWithN (vector<vector<int> >& combo, vector<int>& s, const vector<int>& data, int n)
{
  if (data.size() == 0) {
    //this is one possibility
    if (s[0] != n)
      combo.push_back (s);
    return;
  }
  for (int i = 0; i < data.size(); i++) {
    //every element could start at the first position
    s.push_back (data[i]);
    //the rest got only n - 1 to choose from
    vector<int> tmp = vector<int> (data);
    tmp.erase (tmp.begin() + i);
    PrintComboNotStartingWithN (combo, s, tmp, n);
    //reversed pop the stack, now move the next element to the front
    s.pop_back();
  }
}

//dont' print duplicates if there are some
void PrintComboWithoutDuplicate (vector<vector<int> >& combo, vector<int>& s, const vector<int>& data, int n, int* hashtable)
{
  if (data.size() == 0) {
    //this is one possibility
    if (s[0] != n)
      combo.push_back (s);
    return;
  }
  for (int i = 0; i < data.size(); i++) {
    if (hashtable[i] == 0) {
      hashtable[i] = 1;
      //every element could start at the first position
      s.push_back (data[i]);
      //the rest got only n - 1 to choose from
      vector<int> tmp = vector<int> (data);
      tmp.erase (tmp.begin() + i);
      PrintComboWithoutDuplicate (combo, s, tmp, n, hashtable);
      //reversed pop the stack, now move the next element to the front
      s.pop_back();
    }
    else
      //duplicates, skip this round
      continue;
  }
}

int main()
{
  /*
    vector<int> foo ( {2, 2, 3});
    vector<int> tmp;
    vector<vector<int >> combo;
    int hashtable[10];
    for (int i = 0; i < 10; i++)
    hashtable[i] = 0;
    PrintComboWithoutDuplicate (combo, tmp, foo, 1, hashtable);
    for (auto i: combo) {
    for (auto j: i) {
    cout << j << " ";
    }
    cout << endl;
    }
    vector<vector<int> > bar;
    vector<int> tmp;
    NchooseK (1, 4, 3, tmp, bar);
    for (auto i: bar) {
    for (auto j: i) {
    cout << j << " ";
    }
    cout << endl;
    }*/
  char s[] = "abc";
  int size = strlen(s);
  Permutation(s,size);
}
