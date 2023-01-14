#include <stdio.h>
#include <stdlib.h>

union u1 {
  char c;
  int i;
};

typedef union u1 u1_t;

int main(int argc, char **argv) {

  u1_t x, y;
  x.c = '\x58';
  y.c = '\xD8';

  printf("%c %i 0x%x \n", x.c, x.c, x.c);
  printf("%c %i 0x%x \n", y.c, y.c, y.c);
  putchar('\n');
  printf("%c %i 0x%x \n", x.i, x.i, x.i);
  printf("%c %i 0x%x \n", y.i, y.i, y.i);

  return 0;
  
}
