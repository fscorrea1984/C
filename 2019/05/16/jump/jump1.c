#include <stdio.h>
#include <stdlib.h>

 struct permissions {
   unsigned int u : 3;
   unsigned int g : 3;
   unsigned int o : 3;
 };

typedef struct permissions Perm;

 int main (int argc, char **argv) {
   
   //Perm bf = { 02, 04, 04 };
   Perm bf = { 06, 04, 04 };

   int a = ((bf.u & 04) >> 2);
   int b = ((bf.g & 04) >> 2);
   int c = ((bf.o & 04) >> 2);
   
   if (a && b && c)
     puts("Readable");
   else
     puts("Not Readable");

   return 0;

 }
