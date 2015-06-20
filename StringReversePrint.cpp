/*
print string without a loop
*/

#include <stdio.h>

void Print(const char* s){
  if(s[0] == '\0' )
    return;
  putchar(s[0]);
  Print(s + 1);
}

int main(){
  char s[] = "abc";
  Print(s);
}

