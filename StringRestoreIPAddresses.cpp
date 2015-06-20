/*
  Given a string containing only digits, restore it by returning all possible valid IP address combinations.

  For example:
  Given "25525511135",

  return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)

*/

#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

/*
first implementation

bool valid (string s)
{
  //note that 000, 00x, 0x is not valid ip address
  if (s.size() == 3 && (atoi (s.c_str() ) > 255 || atoi (s.c_str() ) == 0) ) {
    return false;
  }
  if (s.size() == 3 && s[0] == '0') {
    return false;
  }
  if (s.size() == 2 && atoi (s.c_str() ) == 0) {
    return false;
  }
  if (s.size() == 2 && s[0] == '0') {
    return false;
  }
  return true;
}

void getRes (string s, string r, vector<string>& res, int k)
{
  if (k == 0) {
    //when reach here, a valid ip address should have nothing left
    if (s.empty() )
      res.push_back (r);
    return;
  }
  else {
    for (int i = 1; i <= 3; i++) {
      if (s.size() >= i && valid (s.substr (0, i) ) ) {
        //if it is the last number of the
        if (k == 1)
          getRes (s.substr (i), r + s.substr (0, i), res, k - 1);
        else
          getRes (s.substr (i), r + s.substr (0, i) + ".", res, k - 1);
      }
    }
  }
}

vector<string> restoreIpAddresses (string s)
{
  vector<string> res;
  getRes (s, "", res, 4);
  return res;
}

  bool isValidIP(const char* IP, int len){
  char tmp[4];
  int ip = atoi(strncpy(tmp,IP,len));
  if(len == 3 || len == 2 && IP[0] == '0')
  return false;
  if(ip > 255 || ip < 0)
  return false;
  return true;
  }

  void PrintIP(const char* s,char* IP,int IPlen,int Recur, vector<char*>& container){
  if(Recur == 0){
  int lastlen = strlen(s);
  if(isValidIP(s,lastlen))
  container.push_back(IP);
  //else
  //delete[] IP;
  return;
  }
  for(int i = 1; i <= 3; i++){
  if(Recur != 1)
  {
  IP = new char[16];
  if(isValidIP(s,i))
  {
  strncpy(IP + IPlen,s,i);
  memcpy(IP + IPlen,".",1);
  IPlen += (i + 1);
  s += i;
  PrintIP(s,IP,IPlen,Recur - 1,container);
  }
  }
  else{
  if(isValidIP(s,i))
  {
  strncpy(IP + IPlen,s,i);
  IPlen += i;
  s += i;
  PrintIP(s,IP,IPlen,Recur - 1,container);
  }
  }
  }
  }
*/

//second implementation

bool IsValidIP(string& s)
{
	/*
	string::size_type sz;   // alias of size_t
	int dec = std::stoi (s,&sz);
	if(0 <= dec && dec <= 255)
		return true;
	return false;
	*/
	
    //note that 000, 00x, 0x is not valid ip address
    if (s.size() == 3 && (atoi (s.c_str() ) > 255 || atoi (s.c_str() ) == 0) ) {
      return false;
    }
    if (s.size() == 3 && s[0] == '0') {
      return false;
    }
    if (s.size() == 2 && s[0] == '0') {
      return false;
    }
    if (s.size() == 2 && atoi (s.c_str() ) == 0) {
      return false;
    }
    
    return true;
}

void restoreIpAddresseshelper(string& s,int start,vector<string>& substring,vector<string>& vec)
{
	//if all digits are used
	if(substring.size() == 4)
	{
		string IP = "";
		int size = 0;
		for(int i = 0; i < substring.size(); i++)
		{
			size += substring[i].size();
			IP += substring[i] + ".";
		}
		IP.erase(IP.size() - 1,1);
		
		if(size == s.size())
		{
			vec.push_back(IP);
		}
		return;
	}
	
	//NOTE the i <= s.size() because i indicates the right bound of the substr and it is excluded	
	for(int i = start + 1; i <= s.size() && i < start + 4; i++)
	{
		string substr = s.substr(start,i - start);
		if(IsValidIP(substr))
		{
			substring.push_back(substr);
				
			restoreIpAddresseshelper(s,i,substring,vec);
			
			substring.pop_back();
		}
	}
}

vector<string> restoreIpAddresses(string s) {
	vector<string> result;
	if(s.size() == 0)
		return result;
	vector<string> substring;
	restoreIpAddresseshelper(s,0,substring,result);
	return result;
}

int main()
{
  string foo = "25525511135";
  vector<string> bar = restoreIpAddresses (foo);
  for (int i = 0; i < bar.size(); i++) {
    cout << bar[i] << endl;
  }
}
