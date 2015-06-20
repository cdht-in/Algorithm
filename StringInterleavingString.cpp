/*
  Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

  For example,
  Given:
  s1 = "aabcc",
  s2 = "dbbca",

  When s3 = "aadbbcbcac", return true.
  When s3 = "aadbbbaccc", return false.
  
*/

#include <string>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>


using namespace std;


/*

first implementation

//C(m + n, m) combination of interleaving strings
void PrintAllInterleaving(const char* a,const char* b,char* c,int len){
  //empty string
  if(a[0] == '\0' && b[0] == '\0')
    {
      //print from the beginning of c
      printf("%s\n",c - len);
      return;
    }
  //each position of c has 50/50 chance to be either a and b
  if(a[0] != '\0')
    {
      c[0] = a[0];
      PrintAllInterleaving(a + 1,b,c + 1,len);
    }
  if(b[0] != '\0')
    {
      c[0] = b[0];
      PrintAllInterleaving(a,b + 1,c + 1,len);
    }
}

//O(n)
bool IfInterleave(const string& a, const string& b, const string& c)
{
  int i = 0;
  int j = 0;
  int k = 0;
  //all element needs to match and the order is perserved
  while(i < a.size() && j < b.size()){
    if(a[i] == c[k]){
      i++;
      k++;
    }
    else if(b[j] == c[k]){
      j++;
      k++;
    }
    else
      return false;
  }
  //either a or b is finish and make sure the leftover match
  if(i == a.size()){
    while(j < b.size())
      {
	if(b[j] != c[k])
	  return false;
	j++;
	k++;
      }
  }
  else{
    while(i < a.size())
      {
	if(a[i] != c[k])
	  return false;
	i++;
	k++;
      }
  }
  return true;
}

//approach 2, reduce the interleaved string on the fly, the remaining should match the left over. O(n) but with the string shrinking overhead
bool IfInterleave1(string a,string b,string c){
  int i = 0;
  int k = 0;
  while(i < a.size() && k < c.size()){
    while(a[i] != c[k] && k < c.size())
      k++;
    //erase c[k], note here that c.erase tends to shift everyting to the right left, so no need to increment k here
    c.erase(k,1);
    i++;
  }
  //test if the left over match
  if(c == b)
    return true;
  return false;
}

//O(n)
bool IfInterleave2(const char* a,int ax,const char* b, int bx,const char* c){
  if(strlen(a) == 0)
    return strcmp(b,c) == 0;
  else if(strlen(b) == 0)
    return strcmp(a,c) == 0;

}

*/

//second implementation

bool isInterleave(string s1, string s2, string s3) {
	int n = s1.size();
	int m = s2.size();
	if(n + m != s3.size())
		return false;
	vector<vector<bool> > match(n + 1, vector<bool>(m + 1, false));
	//two empty strings can form a third empty string
	match[0][0] = true;
	
	//init the first row => if s1 is empty, match s2 and s3
	for(int i = 1; i <= m; i++)
	{
		if(s2[i - 1] == s3[i - 1])
			match[0][i] = true;
	}

	//init the first column => if s2 is empty match s1 and s3
	for(int i = 1; i <= n; i++)
	{
		if(s1[i - 1] == s3[i - 1])
			match[i][0] = true;
	}
		
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			char s1Char = s1[i - 1];
			char s2Char = s2[j - 1];
			char s3Char = s3[i + j - 1];
			//the essence is that if(s3[i + j - 1] == either s1[i] or s2[j]), whehter match[i][j] is a match is the same as match[i - 1][j] or match[i][j - 1]
			
			if(s1Char == s3Char)
				match[i][j] = match[i - 1][j];
			
			//the || match[i][j] is needed because s3char could be taken from either s1 or s2
			if(s2Char == s3Char)
				match[i][j] = match[i][j - 1] || match[i][j];
		}
	}	
	
	return match[n][m];
}











































//second implementation
bool isInterleaveI(string s1, string s2, string s3) {
	if(s1.size() + s2.size() != s3.size())
		return false;
	int m = s1.size();
	int n = s2.size();
	
	vector<vector<int> > dp(m + 1, vector<int>(n + 1,false));
	
	dp[0][0] = true;
	
	for(int i = 1; i <= n; i++)
	{
		dp[0][i] = (s2[i - 1] == s3[i - 1]);
	}
	
	for(int i = 0; i <= m; i++)
	{
		dp[i][0] = (s1[i - 1] == s3[i - 1]);
	}
	
	
	
	for(int i = 1; i <= m; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			char s1Char = s1[i - 1];
			char s2Char = s2[j - 1];
			char s3Char = s3[i + j - 1];
			
			if(s1Char == s3Char)
			{
				dp[i][j] = dp[i - 1][j];
			}
			
			if(s2Char == s3Char)
			{
				dp[i][j] = dp[i][j] || dp[i][j - 1];
			}
		}
	}
	
	return dp[m][n];
	
}



int main(){
  const char* foo = "ab";
  const char* bar = "cd";
  const char* combo = "abcd";
  
}
