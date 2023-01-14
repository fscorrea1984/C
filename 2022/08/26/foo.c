#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define UR 256u
#define UW 128u
#define UX 64u

#define GR 32u
#define GW 16u
#define GX 8u

#define OR 4u
#define OW 2u
#define OX 1u

// size of "unsigned" type is of 4 bytes = 32 bits

void rightrot(unsigned n, int k);

void invert(unsigned n, int p, int k);

void setbits(unsigned n1, int p, int k, unsigned n2) {
  unsigned endmaskn1 = ( ~0u << (p+1-k));
  endmaskn1 ~= endmaskn1;
  unsigned endbitsn1 = n1 & endmaskn1;
  unsigned endmaskn2 = ( ~0u << (k));
  endmaskn2 ~= endmaskn2;
  unsigned endbitsn2 = n2 & endmaskn2;
  unsigned midmaskn1 = ( ~0u << (p+1));
  unsigned z = n1 & midmaskn1;
  unsigned midmaskz = endbitsn2 << (p+1-k);
  z |= midmaskz;
  z |= endbitsn1;
  printf("z = %u\n", z);
}

// getbits: get k bits from position p
unsigned getbits(unsigned n, int p, int k) {
  return (n >> (p+1-k)) & ~( ~0u << k);
}

void setklsbbits(unsigned n, int k) {
  unsigned m = (1u << k);
  m--;
  n |= m;
  printf("n is %u\n", n);
}

/*-- 
alternative void getfirstlsbset(unsigned n){
  unsigned N = ~n;
  n++;
  unsigned res = n & N;
  int pos = 0;
  while(res % 2 == 0) {
    res >>= 1;
    ++pos
  }
  printf("%d-th bit is the first one set from the right\n", pos);
}
--*/

void getfirstlsbset(unsigned n) {
  unsigned N = ~n;
  N++;
  unsigned res = n & N;
  double k = log2((double)res);
  printf("%d-th bit is the first one set from the right\n", (int)k);
}

void togglebit(unsigned n, int k) {
  n ^= (1u << k);
  printf("n is %u\n", n);
}

void resetbit(unsigned n, int k) {
  n &= ~(1u << k);
  printf("n is %u\n", n);
}

void setbit(unsigned n, int k) {
  n |= (1u << k);
  printf("n is %u\n", n);
}

void checkbit(unsigned n, int k) {
  printf("Bit %d is ", k);
  unsigned res = n & (1u << k);
  (res == 0) ? printf("0") : printf("1");
  putchar('\n');
}

void showbits(unsigned n) {
  for(int i = 31; i >= 0; i--) {
    unsigned m = 1u << i;
    ((n & m) == 0) ? printf("0") : printf("1");
  }
  putchar('\n');
}

int main(int argc, char **argv) {

  unsigned x = 0u;
  unsigned perm = 436u;

  /*
  x = 438u;
  showbits(x);
  x = 436u;
  showbits(x);
  x = 292u;
  showbits(x);
  x = 216u;
  showbits(x);
  x = 88u;
  showbits(x);
  x = 40u;
  showbits(40u);
  */

  /*
  x = 436u;
  checkbit(x,0);
  checkbit(x,2);
  checkbit(x,7);
  x = 292u;
  checkbit(x,7);
  x = 216u;
  checkbit(x,7);
  x = 88u;
  checkbit(x,7);
  checkbit(x,6);
  checkbit(x,5);
  checkbit(x,4);
  checkbit(x,3);
  x = 40u;
  checkbit(x,7);
  checkbit(x,6);
  checkbit(x,5);
  checkbit(x,4);
  checkbit(x,3);
  */

  /*
  x = 88u;
  setbit(x,7);
  //printf("x is %u\n", x);
  x = 216u;
  resetbit(x,7);
  //printf("x is %u\n", x);
  */
  
  /*
  x = 436u;
  togglebit(x,1);
  */
  
  /*
  x = 40u;
  getfirstlsbset(x);
  x = 256u;
  getfirstlsbset(x);
  */
  
  /*
  x = 40u;
  setklsbbits(x,3);
  x = 40u;
  setklsbbits(x,5);
  x = 40u;
  setklsbbits(x,7);
  x = 40u;
  setklsbbits(x,8);
  */
  
  /*  
  printf("perm = %u\n", perm); // rw-rw-r--
  perm &= ~(UW | GW | OW); // "chmod -w"
  printf("perm = %u\n", perm); // r--r--r--
  perm |= (UW | GW | OW); // "chmod +w"
  printf("perm = %u\n", perm); // rw-rw-rw-
  perm |= (UX); // "chmod u+x"
  printf("perm = %u\n", perm); // rwxrw-rw-
  
  if((perm & (UX | GX | OX)) == 0)
    puts("then file is not executable. Not by user/owner, neither group, nor the others.");
  else
    puts("file is executable by some among user, group and other");
  */
  
  return 0;
  
}

/**--

111 110 110 = 0001 1111 0110 = 0x1F6 = 502
110 110 110 = 0001 1011 0110 = 0x1B6 = 438
110 110 100 = 0001 1011 0100 = 0x1B4 = 436
100 100 100 = 0001 0010 0100 = 0x124 = 292
1101 1000 = 0xD8 = 216
0101 1000 = 0x58 = 88
0010 1000 = 0x28 = 40

showbits(438u) = 00000000000000000000000110110110
showbits(436u) = 00000000000000000000000110110100
showbits(292u) = 00000000000000000000000100100100
showbits(216u) = 00000000000000000000000011011000
showbits(88u) = 00000000000000000000000001011000
showbits(40u) = 00000000000000000000000000101000

checkbit(436u,0) = 0
checkbit(436u,2) = 1
checkbit(436u,7) = 1
checkbit(292u,7) = 0
checkbit(216u,7) = 1
checkbit(88u,7) = 0
checkbit(88u,6) = 1
checkbit(88u,5) = 0
checkbit(88u,4) = 1
checkbit(88u,3) = 1
checkbit(40u,7) = 0
checkbit(40u,6) = 0
checkbit(40u,5) = 1
checkbit(40u,4) = 0
checkbit(40u,3) = 1

setbit(88u,7) = 216u (11011000)
resetbit(216u,7) = 88u (01011000)

togglebit(436u,1) = 438u (110110110)

getfirstlsbset(40u) = 3
getfirstlsbset(256u) = 8

setklsbbits(40u,3) = 47u (101111)
setklsbbits(40u,5) = 63u (111111)
setklsbbits(40u,7) = 127u (1111111)
setklsbbits(40u,8) = 255u (11111111)

perm = 436u (110 110 100)
perm &= ~(UW | GW | OW)
perm = 292u (100 100 100)

perm |= (UW | GW | OW)
perm = 438u (110 110 110)

if((perm & (UX | GX | OX)) == 0) then file is not executable. Not by user/owner, neither group, nor the others.

UR = 100000000 = 0x0100 = 256u
UW = 10000000 = 0x80 = 128u
UX = 1000000 = 0x40 = 64u
-----------
GR = 100000 = 0x20 = 32u
GW = 10000 = 0x10 = 16u
GX = 1000 = 0x08 = 8u
-----------
OR = 100 = 0x04 = 4u
OW = 10 = 0x02 = 2u
OX = 1 = 0x01 = 1u

TODO:

x &= 0177; // sets to zero all but the low-order seven bits of x
x |= SET_ON; // sets to one in x the bits that are set to one in SET_ON
x &= ~077; // sets the last six bits of x to zero

getbits(x,4,3); returns the three bits in positions 4, 3, and 2, right-adjusted
setbits();
invert();
rightrot();

x = 101 01
getbits(x,4,3) = 101
getbits(x,4,2) = 10
x = 110 01
getbits(x,4,3) = 110
getbits(x,4,2) = 11

--------------------------------------------------

x = 10111001 = 185u
y = 10110011 = 179u
setbits(x,4,3,y);
x[4]=1
x[3]=1
x[2]=0
------
y[2]=0
y[1]=1
y[0]=1

101 110 01 ---> 101 011 01 - 10101101 = 173u

setbits(x,4,3,y) = 173u

unsigned endmaskx = ~0u << (p+1-k) // 11111111 << (4+1-3) = 11111111 << (5-3) = 11111111 << (2) = 11111100
endmaskx ~= endmaskx // endmaskx = ~(endmaskx) = 00000011
unsigned endbitsx = x & endmaskx // endbitsx = 10111001 & 00000011 = 00000001
unsigned endmasky = ~0u << (k) // 11111111 << (3) = 11111000
endmasky ~= endmasky // endmasky = ~(endmasky) = 00000111
unsigned endbitsy = y & endmasky // endbitsy = 10110011 & 00000111 = 00000011
unsigned midmaskx = ~0u << (p+1) // midmaskx = 11111111 << (5) = 11100000
//midmaskx ~= midmaskx // midmaskx = ~(midmaskx) = 00011111
z = x & midmaskx // z = 10111001 & 11100000 = 10100000
unsigned midmaskz = endbitsy << (p+1-k) // midmaskz = 00000011 << (2) = 00001100
z |= midmaskz // z = 10100000 | 00001100 = 10101100
z |= endbitsx // z = 10101100 | 00000001 = 10101101

--------------------------------------------------

x = 10101001 = 169u
y = 10110011 = 179u
setbits(x,4,2,y);
x[4]=0
x[3]=1
------
y[1]=1
y[0]=1

101 01 001 ---> 101 11 001 - 10111001 = 185u

setbits(x,4,2,y) = 185u

unsigned endmaskx = ~0u << (p+1-k) // 11111111 << (4+1-2) = 11111111 << (5-2) = 11111111 << (3) = 11111000
endmaskx ~= endmaskx // endmaskx = ~(endmaskx) = 00000111
unsigned endbitsx = x & endmaskx // endbitsx = 10101001 & 00000111 = 00000001
unsigned endmasky = ~0u << (k) // 11111111 << (2) = 11111100
endmasky ~= endmasky // endmasky = ~(endmasky) = 00000011
unsigned endbitsy = y & endmasky // endbitsy = 10110011 & 00000111 = 00000011
unsigned midmaskx = ~0u << (p+1) // midmaskx = 11111111 << (5) = 11100000
z = x & midmaskx // z = 10101001 & 11100000 = 10100000
unsigned midmaskz = endbitsy << (p+1-k) // midmaskz = 00000011 << (3) = 00011000
z |= midmaskz // z = 10100000 | 00011000 = 10111000
z |= endbitsx // z = 10111000 | 00000001 = 10111001

--**/
