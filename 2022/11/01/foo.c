#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct s {
  int a, b;
} foo;

typedef union u {
  unsigned char c;
  unsigned int x;
} bar;

unsigned int f(unsigned int a, unsigned int b) {
  return (a < b)? a : b;
}

int main(int argc, char **argv) {

  foo mystruct = { .a = 7, .b = 11 };
  foo *pfoo = &mystruct;

  bar myunion = { .x = 0x30 };
  
  int *a = (int *)malloc(3*5*sizeof(int));

  for(int i = 0; i < 3; i++)
    for(int j = 0; j < 5; j++)
      *(a+i*5+j) = i+j;

  for(int i = 0; i < 3; i++)
    for(int j = 0; j < 5; j++) {
      printf("%d", *(a+i*5+j));
      fputc( ((j == 4)? '\x0A' : '\x20'), stdout);
    }

  printf("%d\n",mystruct.a+mystruct.b);
  printf("%d\n",pfoo->a*pfoo->b);
  printf("%c %u\n",myunion.c,f(myunion.x,0));
    
  free(a);
  
  return 0;
  
}
