/*
  A String is given ilke--abdecadc...szx..any thing..like this...element in this given pattern can be any this(like int also and letter till z also)
  you have to arrange in pattern--aabbcclike....ie.same charactor together..
*/

#include <stdio.h>
#include <stdlib.h>

//counting sort O(n)
char* Sort(char* s){
  char* p = s;
  int len = 0;
  while(*p){
    //printf("%c\n",*p);
    len++;
    p++;
  }
  char* count = (char*)malloc(sizeof(char) * 26);
  int i;
  for(i = 0; i < 26; i++)
    count[i] = 0;
  p = s;
  while(*p){
    count[*p - 'a']++;
    p++;
  }
  char* ret = (char*)malloc(sizeof(char) * (len + 1));
  ret[len] = '\0';
  char* q = ret;
  for(i = 0; i < 26; i++){
    if(count[i]){
      int j;
      for(j = 0; j < count[i]; j++){
	*q = 'a' + i;
	q++;
      }
    }
  }
  free(count);
  return ret;
}


int main()
{
  char s[] = "abdecadc";
  //int size = sizeof (s) / sizeof (char);
  char* ret = Sort(s);
  printf("%s\n",ret);
  free(ret);
}
