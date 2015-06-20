#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

struct EncoderInfo
{
	unordered_set<int> pos;
	string encodedString;
	EncoderInfo(string encodedString,unordered_set<int> pos):pos(pos),encodedString(encodedString){}
};

class Encoder
{
	
private:
	
	int ConvertToInt(const string &s)
	{
		int n = 0;
		for(int i = 0; i < s.size(); i++)
		{
			n *= 10;
			n += (s[i] - '0');
		}
		return n;
	}	

public:
	
	EncoderInfo Encode(const string& s)
	{
		string encodedString = "";
		unordered_set<int> pos;
		
		for(int i = 0; i < s.size(); i++)
		{
			int j = i;
			
			while(j + 1 < s.size() && s[j] != '$' && s[j] == s[j + 1])
			{
				j++;
			}
			
			int c = j - i + 1;
			
			//if there is no consecutive character, don't encode it
			if(s[i] == '$' || c == 1)
			{	
				encodedString += s[i];
			}
			else
			{
				//record the inseted '$' position
				pos.insert(encodedString.size());
				
				//insert '$' to indicate the encoding
				encodedString += "$" + to_string(c) + "x" + s[i];
			}
			
			i = j;
		}
		
		return EncoderInfo(encodedString,pos);		
	}
	
	string Decode(const EncoderInfo& info)
	{
		string s = info.encodedString;
		unordered_set<int> pos = info.pos;
		
		string decodedString = "";
		
		for(int i = 0; i < s.size(); i++)
		{
			//check this condition first to speed up execution assuming non-encoded strings are less than encoded ones
			if(s[i] != '$' || pos.find(i) == pos.end())
			{
				decodedString += s[i];
			}					
			else
			{	
				//consecutive '$'
				while(i + 1 < s.size() && s[i] == s[i + 1])
				{
					decodedString += s[i];
					i++;
				}
				
				//stop at the last '$'
				decodedString += s[i];
				
				//skip digits
				int j = i + 1;
				while(j < s.size() && isdigit(s[j]))
				{
					j++;
				}
				
				//all trailing digits
				if(j == s.size())
				{
					decodedString += s.substr(i + 1, j - (i + 1));
					return decodedString;
				}
				
				//not proper encoded form
				if(s[j] != 'x' || j + 1 == s.size())
				{
					decodedString += s[j];
					i = j;
					continue;
				}
				
				//proper form
				//erase one excess '$'
				decodedString.erase(decodedString.size() - 1);
				int decimal = ConvertToInt(s.substr(i + 1, j - (i + 1)));
				char c = s[j + 1];
				decodedString += string(decimal,c);
				i = j + 1;	
			}
		}
		
		return decodedString;
	}	
};


bool ExpectEqual(string& s, string &t)
{
	return s == t;
}


int main()
{
	Encoder e;
	
	bool result = true;
	
	string s1 = "abc";
	EncoderInfo s1e = e.Encode(s1);	
	string s1d = e.Decode(s1e);
	result &= ExpectEqual(s1,s1d);
	
	string s2 = "$abc";
	EncoderInfo s2e = e.Encode(s2);	
	string s2d = e.Decode(s2e);
	result &= ExpectEqual(s2,s2d);
	
	string s3 = "abc$";
	EncoderInfo s3e = e.Encode(s3);	
	string s3d = e.Decode(s3e);
	result &= ExpectEqual(s3,s3d);
	
	string s4 = "$$abc$";
	EncoderInfo s4e = e.Encode(s4);	
	string s4d = e.Decode(s4e);
	result &= ExpectEqual(s4,s4d);
		
	string s5 = "$$abc$$";
	EncoderInfo s5e = e.Encode(s5);	
	string s5d = e.Decode(s5e);
	result &= ExpectEqual(s5,s5d);
	
	string s6 = "aabc";
	EncoderInfo s6e = e.Encode(s6);	
	string s6d = e.Decode(s6e);
	result &= ExpectEqual(s6,s6d);
	
	string s7 = "abcc";
	EncoderInfo s7e = e.Encode(s7);	
	string s7d = e.Decode(s7e);
	result &= ExpectEqual(s7,s7d);
	
	string s8 = "aabcc";
	EncoderInfo s8e = e.Encode(s8);	
	string s8d = e.Decode(s8e);
	result &= ExpectEqual(s8,s8d);
		
	string s9 = "aabbcc";
	EncoderInfo s9e = e.Encode(s9);	
	string s9d = e.Decode(s9e);
	result &= ExpectEqual(s9,s9d);
		
	string s10 = "aab$bcc";
	EncoderInfo s10e = e.Encode(s10);	
	string s10d = e.Decode(s10e);
	result &= ExpectEqual(s10,s10d);
		
	string s11 = "aabb$$cc";
	EncoderInfo s11e = e.Encode(s11);	
	string s11d = e.Decode(s11e);
	result &= ExpectEqual(s11,s11d);
	
	string s12 = "aa$$b$$cc";
	EncoderInfo s12e = e.Encode(s12);	
	string s12d = e.Decode(s12e);
	result &= ExpectEqual(s12,s12d);
	
	string s13 = "aa$$bb$$cc";
	EncoderInfo s13e = e.Encode(s13);	
	string s13d = e.Decode(s13e);
	result &= ExpectEqual(s13,s13d);
	
	string s14 = "a$abbcc";
	EncoderInfo s14e = e.Encode(s14);	
	string s14d = e.Decode(s14e);
	result &= ExpectEqual(s14,s14d);
	
	string s15 = "aabbc$c";
	EncoderInfo s15e = e.Encode(s15);	
	string s15d = e.Decode(s15e);
	result &= ExpectEqual(s15,s15d);
	
	string s16 = "xx$xxc";
	EncoderInfo s16e = e.Encode(s16);	
	string s16d = e.Decode(s16e);
	result &= ExpectEqual(s16,s16d);
	
	string s17 = "$3xa";
	EncoderInfo s17e = e.Encode(s17);
	string s17d = e.Decode(s17e);	
	result &= ExpectEqual(s17,s17d);
	
	string s18 = "$3xa$$$$";
	EncoderInfo s18e = e.Encode(s18);
	string s18d = e.Decode(s18e);	
	result &= ExpectEqual(s18,s18d);
			
	string s19 = "$3xxxx$$$";
	EncoderInfo s19e = e.Encode(s19);
	string s19d = e.Decode(s19e);	
	result &= ExpectEqual(s19,s19d);
	
	string s20 = "$$$$";
	EncoderInfo s20e = e.Encode(s20);
	string s20d = e.Decode(s20e);	
	result &= ExpectEqual(s20,s20d);
	
	string s21 = "55553x5$$$$";
	EncoderInfo s21e = e.Encode(s21);
	string s21d = e.Decode(s21e);	
	result &= ExpectEqual(s21,s21d);
	
	string s22 = "$3xc3x5$$$$";
	EncoderInfo s22e = e.Encode(s22);
	string s22d = e.Decode(s22e);	
	result &= ExpectEqual(s22,s22d);
	
	string s23 = "$$xxxxx$$aaaa";
	EncoderInfo s23e = e.Encode(s23);
	string s23d = e.Decode(s23e);	
	result &= ExpectEqual(s23,s23d);
	
	string s24 = "123333a";
	EncoderInfo s24e = e.Encode(s24);
	string s24d = e.Decode(s24e);	
	result &= ExpectEqual(s24,s24d);
	
	string s25 = "aaaaaaaaaaaaa";
	EncoderInfo s25e = e.Encode(s25);
	
	cout << s25e.encodedString << endl;
	
	string s25d = e.Decode(s25e);	
	
	result &= ExpectEqual(s25,s25d);
	
	if(result)
		cout << "passed all unit tests" << endl;
	else
		cout << "failed all unit tests" << endl;
			
}
