/*
  Determine whether an integer is a palindrome. Do this without extra space.

  click to show spoilers.

  Some hints:
  Could negative integers be palindromes? (ie, -1)

  If you are thinking of converting the integer to string, note the restriction of using extra space.

  You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?

  There is a more generic way of solving this problem.  
*/


int reverse (int x)
{
  int ret = 0;
  int rem = 0;
  bool neg = false;
  if (x < 0) {
    neg = true;
    x = -x;
  }
  while (x) {
    ret *= 10;
    rem = (x % 10);
    ret += rem;
    x = x / 10;
  }
  if (neg)
    return -ret;
  else
    return ret;
}

bool isPalindrome(int x) {
  if(x < 0)
    return false;
  if(x == reverse(x))
    return true;
  return false;
}

int main(){
  
}
