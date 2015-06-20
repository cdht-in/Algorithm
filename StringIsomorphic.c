/*
 * Given two (dictionary) words as Strings, determine if they are isomorphic. Two words are called isomorphic
 * if the letters in one word can be remapped to get the second word. Remapping a letter means replacing all
 * occurrences of it with another letter while the ordering of the letters remains unchanged. No two letters
 * may map to the same letter, but a letter may map to itself.
 *
 * Example:
 * given "foo", "app"; returns true
 * we can map 'f' -> 'a' and 'o' -> 'p'
 *
 * given "bar", "foo"; returns false
 * we can't map both 'a' and 'r' to 'o'
 *
 * given "turtle", "tletur"; returns true
 * we can map 't' -> 't', 'u' -> 'l', 'r' -> 'e', 'l' -> 'u', 'e' ->'r'
 *
 * given "ab", "ca"; returns true
 * we can map 'a' -> 'c', 'b' -> 'a'
 */
#include <stdio.h>

int IsIsomorphic (const char* s1, const char* s2)
{
  //asumption is that they have the same length
  unsigned char map[26] = {0};
  int i;
  for (i = 0; s1[i] != '\0'; i++) {
    //if this char hasn't been mapped before
    if (map[s2[i] - 'a'] == 0) {
      map[s2[i] - 'a'] = s1[i];
    }
    else {
      //if the previous mapping is not the current mapping
      if (map[s2[i] - 'a'] != s1[i])
        return 0;
    }
  }
  return 1;
}

int main()
{
  char s1[] = "ab";
  char s2[] = "ca";
  printf ("%d\n", IsIsomorphic (s1, s2) );
}
