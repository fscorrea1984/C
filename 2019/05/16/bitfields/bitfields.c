#include <stdio.h>
#include <stdlib.h>

 struct permissions {
   unsigned int u : 3;
   unsigned int g : 3;
   unsigned int o : 3;
 };

typedef struct permissions Perm;

int main (int argc, char **argv) {

  Perm bf = { 06, 04, 04 }; // 110 100 100

  int p = (bf.u * 0100) + (bf.g * 010) + bf.o;

  printf("%#o\n", p);

   return 0;

 }
