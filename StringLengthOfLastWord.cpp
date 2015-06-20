/*
  Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

  If the last word does not exist, return 0.

  Note: A word is defined as a character sequence consists of non-space characters only.

  For example,
  Given s = "Hello World",
  return 5.

*/
#include <stdio.h>

/* 

first implementation

int lengthOfLastWord (const char* s)
{
  const char* p = s;
  while (*p != '\0') {
    p++;
  }
  //starting from the last character
  const char* spacep = --p;
  if (*p == ' ') {
    //find the first non-whitespace
    while (*p == ' ' && p >= s) {
      p--;
    }
    spacep = p;
  }
  while (*spacep != ' ' && spacep >= s) {
    spacep--;
  }
  return p - spacep;
}

*/

//second implementation

int lengthOfLastWord(const char *s) {
	if(s[0] == '\0')
		return 0;
	//trim spaces
	
	int c = 0;
	for(; s[c] != '\0'; c++);
		
	int i = c - 1;
	while(i >= 0 && s[i] == ' '){
		i--;
	}
	
	//all spaces
	if(i == 0)
		return 1;
	else if(i < 0)
		return 0;
	
	int j = i - 1;
	while(j >= 0 && s[j] != ' ')	
	{	
		j--;
	}
	
	return i - (j + 1) + 1;
}



int main()
{
  char s[] = "";
  printf ("%d\n", lengthOfLastWord (s) );
}
