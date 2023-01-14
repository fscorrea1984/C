#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int func(int x) {
  float f;
  memcpy(&f,&x,sizeof(f));
  printf("%f\n", f);
}

int main(int argc,char**argv) {
  float f = 2.5;
  int x;
  memcpy(&x,&f,sizeof(f));
  func(x);
  return 0;
}
