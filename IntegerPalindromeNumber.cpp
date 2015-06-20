/*
	
Determine whether an integer is a palindrome. Do this without extra space.

click to show spoilers.

Some hints:
Could negative integers be palindromes? (ie, -1)

If you are thinking of converting the integer to string, note the restriction of using extra space.

You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?

There is a more generic way of solving this problem.

*/
#include <iostream>

using namespace std;

bool isPalindrome(int x) 
{
   if(x < 0)
	  return false;  
   int div = 1;  
   //get the most significant bit
   while(x / div >= 10)
       div *= 10;
   
   while(x > 0)  
   {  
        int l = x / div;  
        int r = x % 10;  
        if(l != r) 
			return false;  
        x = x % div / 10;  
        div /= 100;
    }  
    return true;
}

//a much clearer logic
bool isPalindrome(int x) 
{  
	if(x<0)
		return 0;  
	int n = 0,temp=x,big=1,small=1;  
	while(temp != 0)  
	{  
	    n++;  
	    temp /= 10;  
	    if(temp)
			big *= 10;  
	}  
  	
	for(int i=0; i < n/2;++i)  
	{  
	    if((x / big) % 10 != (x / small) % 10)
			return false;  
	    big/=10;  
	    small*=10;  
	}  
	return true;  
}  


//recursive approach
/*
	
bool isPalindrome(int x, int &y) {
  if (x < 0) return false;
  if (x == 0) return true;
  if (isPalindrome(x/10, y) && (x%10 == y%10)) {
    y /= 10;
    return true;
  } else {
    return false;
  }
}
bool isPalindrome(int x) {
  return isPalindrome(x, x);
}
	
*/

int main()
{
	cout << isPalindrome(121) << endl;
	
}