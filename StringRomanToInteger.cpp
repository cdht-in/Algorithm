#include <string>

using namespace std;

inline int c2n(char c) {  
 switch(c) {  
   case 'I': return 1;  
   case 'V': return 5;  
   case 'X': return 10;  
   case 'L': return 50;  
   case 'C': return 100;  
   case 'D': return 500;  
   case 'M': return 1000;  
    default: return 0;  
  }  
} 
 
/*	

从前往后扫描，用一个临时变量记录分段数字。
如果当前比前一个大，说明这一段的值应该是当前这个值减去上一个值。比如IV = 5 – 1
否则，将当前值加入到结果中，然后开始下一段记录。比如VI = 5 + 1， II=1+1

*/

int romanToInt(string s) {  
  // Start typing your C/C++ solution below  
  // DO NOT write int main() function  
  int result=0;  
  for(int i =0; i< s.size(); i++)  
  {  
    if(i>0&& c2n(s[i]) > c2n(s[i-1]))  
    {  
      result +=(c2n(s[i]) - 2 * c2n(s[i-1]));  
    }  
    else  
    {  
      result += c2n(s[i]);  
    }  
  }  
  return result;  
}  

int main()
{
	
	
}