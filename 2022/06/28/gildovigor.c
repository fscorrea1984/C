#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv) {

  /*  char c = '\x58';
  char d = '\xD8';
  printf("%c %d 0x%x\n",c,c,c);
  printf("%c %d 0x%x\n",d,d,d);*/

  int *vi = (int *) malloc (8*sizeof(int));
  for(int i = 0; i < 8; i++)
    *(vi++) = (9*i)+990;

  for(int i = 0; i < 8; i++)
    printf("%d\n",*(vi++));

  return 0;
  
}
