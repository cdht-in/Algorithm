/*
  Problem:
  1. String s is called unique if all the characters of s are different.
  2. String s2 is producible from string s1, if we can remove some characters of s1 to obtain s2.
  3. String s1 is more beautiful than string s2 if the length of s1 is greater than the length of s2 or, if they have equal length, if s1 is lexicographically greater than s2.
  Given a string s, you have to find the most beautiful and unique string that is producible from s.

*/
#include <string>
#include <iostream>
#include <vector>
#include <unordered_set>


using namespace std;

unordered_set<string> substring;

string BeatifulStringHelper(vector<string>& vec,vector<vector<int> >& count){
  string ret = "";
  string tmp = "";
  vector<string> vecnext;
  vector<vector<int> > countnext;
  for(int i = vec.size() - 1; i >= 0; i--){
    for(int j = 0; j < vec[i].size(); j++){
      bool flag = true;
      //get the string for the next round
      tmp = vec[i].substr(0,j) + vec[i].substr(j + 1);
      if(substring.find(tmp) == substring.end())
	substring.insert(tmp);
      else
	break;
      vector<int> set = count.back();
      set[(int)(vec[i][j] - 'a')]--;
      vecnext.push_back(tmp);
      countnext.push_back(set);
      //check for uniqueness
      for(int k = 0; k < 26; k++){
	if(set[k] > 1)
	  {
	    flag = false;
	    break;
	  }
      }
      //if unique
      if(flag){
	if(tmp > ret)
	  ret = tmp;
      }
      else
	//restore the count
	set[(int)(vec[i][j] - 'a')]++;
    }
  }
  //there is a winner
  if(ret != "")
    return ret;
  return BeatifulStringHelper(vecnext,countnext);
  
}

string BeatifulString(string s)
{
  vector<int> set(26,0);
  for(int i = 0; i < 26; i++){
    set[i] = 0;
  }
  for(int i = 0; i < s.size(); i++){
    set[(int)(s[i] - 'a')]++;
  }
  vector<string> vec;
  vec.push_back(s);
  vector<vector<int> > count;
  count.push_back(set);
  return BeatifulStringHelper(vec,count);
}

int main(){
  //string foo;
  //getline (cin, foo);
  string foo = "bacd";
  cout << "most beaufiful unique string is " << BeatifulString(foo) << endl;
  //tsocrpkijgdqnbafhmle
}
