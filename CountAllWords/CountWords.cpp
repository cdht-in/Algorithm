#include <iostream>
#include <fstream>
#include <unordered_map>
#include <sstream>
#include <string>

/*
  To run: compile with g++ -std=c++11 CountWords.cpp && ./a.out "filename.txt"
  e.g. g++ -std=c++11 CountWords.cpp && ./a.out foo.txt 
*/

using namespace std;

unordered_map<string, unsigned int>* map;

void ReadFile (string name)
{
  string s;
  ifstream f (name);
  string word;
  map = new unordered_map<string, unsigned int>;
  if (f.is_open() ) {
    while ( getline (f, s) ) {
      istringstream is (s);
      while (is >> word)
        (*map) [word]++;
    }
    f.close();
  }
  else
    cout << "Unable to open file" << endl;
  for (unordered_map<string, unsigned int>::iterator it = map->begin(); it != map->end(); it++ )
    cout  << it->first << " : " << it->second << endl;;
  delete map;
}

int main (int argc, char** argv)
{
  if (argc != 2) {
    cout << "please provide a file name" << endl;
    return -1;
  }
  ReadFile (argv[1]);
}
