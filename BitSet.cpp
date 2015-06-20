/*
  O(1) time to determine if seen one bite of data
*/

#include <bitset>
#include <cstdio>
#include <cmath>
#include <cstring>

std::bitset<256> Bits;

//home made BitSet
class BitSet {

  unsigned char* Bit;
  unsigned int size;

public:
  //# bits
  BitSet (int x) : size() {
    size = (unsigned int) ceil (x / 8);
    Bit = new unsigned char[size];
    memset (Bit, 0, size);
  }

  void SetBit (int pos, int value) {
    int ncell = (int) ceil (pos / 8.0);
    unsigned char* slot = Bit + (size - ncell);
    int nshifts = (int) ( (pos % 8) - 1);
    *slot |= (0x01 << nshifts);
  }

  //need future work on this
  void ResetBit (int pos) {
    *Bit &= ~ (0x01 << pos);
  }

  //print all bits
  void PrintBit() {
    int nbits = 8 * size;
    int nshifts = 0;
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < 8; j++) {
        nshifts = 8 - j - 1;
        if ( ( ( (0x01 << nshifts) & Bit[i]) >> nshifts) == 0x00)
          printf ("0");
        else
          printf ("1");
      }
    }
  }
};

//default c++ implementation
bool SeenByte (char x)
{
  unsigned int Pos = (unsigned int) x;
  if (Bits.test (Pos) == 1 )
    return true;
  else {
    Bits.set (Pos, 1);
    return false;
  }
}

int main()
{
  unsigned char a = '5';
  unsigned char b = '6';
  unsigned char c = '7';
  BitSet foo (256);
  foo.PrintBit();
  foo.SetBit (2, 1);
  printf ("\n");
  foo.PrintBit();
  printf ("\n");
  /*
    foo.ResetBit(2);
    foo.PrintBit();
    printf("\n");
  */
}
