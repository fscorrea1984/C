#include <stdio.h>
#include <stdlib.h>

 struct permissions {
   unsigned int u : 3;
   unsigned int g : 3;
   unsigned int o : 3;
 };

typedef struct permissions Perm;

 int main (int argc, char **argv) {
   
   Perm bf = { 02, 04, 04 };
   //Perm bf = { 06, 04, 04 };

   int x = bf.u;

   switch(x) {
   case 0:
     puts("no read, no write, no exec");
     break;
   case 1:
     puts("no read, no write, exec");
     break;
   case 2:
     puts("no read, write, no exec");
     break;
   case 3:
     puts("no read, write and exec");
     break;
   case 4:
     puts("read, no write, no exec");
     break;
   case 5:
     puts("read and exec, no write");
     break;
   case 6:
     puts("read and write, no exec");
     break;
   case 7:
     puts("read, write and exec");
     break;
   default:
     puts("Permission Value Unknown");
   }

   return 0;

 }
