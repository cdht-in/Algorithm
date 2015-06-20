/*
  print string without using loop
*/
#include <stdio.h>

void Print(const char* s){
  if(*s == '\0')
    return;
  putchar(*s);
  Print(s + 1);
}

int main(){
  char s[] = "abcde";
  Print(s);
  putchar('\n');
}

