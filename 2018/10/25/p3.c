#include <stdio.h>
#include <stdlib.h>

union u1 {
  char c;
  int i;
};

typedef union u1 u1_t;

void f1(u1_t a, u1_t b) {
  printf("%c %i 0x%x \n", a.c, a.c, a.c);
  printf("%c %i 0x%x \n", b.c, b.c, b.c);
}

void f2(u1_t a, u1_t b) {
  printf("%c %i 0x%x \n", a.i, a.i, a.i);
  printf("%c %i 0x%x \n", b.i, b.i, b.i);
}

int main() {

  u1_t x, y;
  x.c = '\x58';
  y.c = '\xD8';

  f1(x, y);
  //f2(x, y);

  return 0;
  
}
