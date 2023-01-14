#include<stdio.h>
#include<stdlib.h>

union union_t {
  unsigned int d;
  unsigned char c;
};

typedef union union_t u_t;

int main(int argc, char **argv) {

  u_t u = { .d = '\x58' };
  printf("%u\n",u.d);
  printf("%c\n",u.c);
  return 0;
  
}
