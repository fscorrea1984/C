#include <stdio.h>
#include <stdlib.h>

 int main (int argc, char **argv) {

   unsigned char x = '\xD8';
   int count = 0;

   for (int i = 0; i <= 7; i++) {
     count += (x % 2 == 1) ? 1 : 0;
     x = x >> 1;
   }

   printf("%d\n", count);

   return 0;

 }

// 1101 1000 = 0xD8
// 0110 1100
// 0011 0110

