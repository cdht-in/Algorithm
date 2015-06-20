/*
  Ransom Note
  Let's say you've just kidnapped Alyssa Hacker you want to leave a ransom note for 
  Ben Bitdiddle, saying that if he ever wants to see her again, he needs to swear to 
  never use Scheme again.  You don't want to write the note by hand, since they would 
  be able to trace your handwriting.  You're standing in Alyssa's apartment and you 
  see a million computer magazines.  You need to write your note by cutting letters 
  out of the magazines and pasting them together to form a letter.  Here's the 
  question: given an arbitrary ransom note string and another string containing all the 
  contents of all the magazines, write a function that will return true if the ransom
  note can be made from the magazines; otherwise, it will return false.  Remember, 
  every letter found in the magazine string can only be used once in your ransom note.
*/

#include <cstdio>

bool ConsistOf(char* a, int s1, char* b, int s2){
  int acii = 256;
  int count[acii];
  for(int i = 0;i < acii; i++)
    count[i] = 0;
  for(int i = 0; i < s2; i++)
    count[(int)(b[i])]++;
  for(int i = 0; i < s1; i++){
    count[(int)(a[i])]--;
    if(count[(int)(a[i])] < 0)
      return false;
  }
  return true;
}


//traverse the two string simultaneously O(n)
bool ConsistOf1(char* a, int s1, char* b, int s2){
  int acii = 256;
  int count[acii];  
  for(int i = 0;i < acii; i++)
    count[i] = 0;
  int i = 0;
  int j = i;
  for(; i < s1 ;i++){
    if(count[(int)a[i]] > 0)
      count[(int)a[i++]]--;
    else{
      for(;b[j] != a[i] && j < s2; j++)
	count[(int)b[j]]++;
      if(j == s2)
	return false;
    }
  }
  return true;
}

int main(){
  char foo[] = "ransom";
  char bar[] = "rsoabmeabeccd";
  printf("%d\n",ConsistOf1(foo,sizeof(foo) - 1,bar, sizeof(bar) - 1));
}
