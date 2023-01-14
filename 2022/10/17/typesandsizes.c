#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv) {

  // Standard Signed Integer Types
  printf("%lu\n",sizeof(char));
  printf("%lu\n",sizeof(short));
  printf("%lu\n",sizeof(int));
  printf("%lu\n",sizeof(long));
  printf("%lu\n",sizeof(long long));
  
  putchar('\n');

  // Real Floating Types
  printf("%lu\n",sizeof(float));
  printf("%lu\n",sizeof(double));
  printf("%lu\n",sizeof(long double));

  return 0;
  
}

/* 0101 1000 = 8+16+64 = 24+64 = 88
1101 1000 = -88
  010

1101 1000 = 216
----------------  
1101 1000
0010 0111
        1
---------
0010 1000 = 8+32 = 40


1101 1000 = -40


  0x58
  0xD8 
*/
