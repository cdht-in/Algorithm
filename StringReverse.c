#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//two pointers
char* ReverseI (char* data, int l, int r)
{
  for (; l < r; l++, r--) {
    char tmp = data[l];
    data[l] = data[r];
    data[r] = tmp;
  }
  return data;
}

//one pointer
char* ReverseII (char* data)
{
  int len = strlen (data);
  char tmp;
  int i;
  for (i = 0; i < len / 2; i++) {
    tmp = data[i];
    data[i] = data[len - i - 1];
    data[len - i - 1] = tmp;
  }
  return data;
}

//reverse each string in a long string
void ReverseSubstring (char* s)
{
  if (s[0] == '\0')
    return;
  int i, len = 0;
  //get each substring len
  for (i = 0; s[i] != ' ' && s[i] != '\0'; i++)
    len++;
  //reverse each substring
  for ( i = 0; i < len / 2; i++) {
    char tmp = s[i];
    s[i] = s[len - i - 1];
    s[len - i - 1] = tmp;
  }
  ReverseSubstring (s + len + 1);
}

void ReverseSubstringI (char* s)
{
  int i = 0, j = 0;
  while (1) {
    for (; s[j] != '\0' && s[j] != ' '; j++);
    //reverse the substring
    int k = 0;
    for (; k < (j - i) / 2; k++) {
      char tmp = s[i + k];
      s[i + k] = s[j - k - 1];
      s[j - k - 1] = tmp;
    }
    if (s[j] == '\0')
      return;
    i = ++j;
  }
}

char* ReverseString (char* s, int size)
{
  //allocate from the heap
  char* ret = (char*) malloc ( size * sizeof (char) );
  char* retPtr = ret;
  int i;
  //backward pointer, pointing at the last char
  for (i = size - 1; i >= 0; i--) {
    int len = 0;
    //always have to check the bound in the inner loop, when it is modifying the index as well
    while (i >= 0 && s[i] != ' ') {
      i--;
      len++;
    }
    //skip the whitespace
    memcpy (retPtr, s + i + 1, len);
    retPtr += len;
    *retPtr++ = ' ';
  }
  //terminate the string
  * (retPtr - 1) = '\0';
  return ret;
}


int main()
{
  char s[] = " a bc def ";
  ReverseSubstringI (s);
  printf ("%s\n", s);
  return 0;
}
