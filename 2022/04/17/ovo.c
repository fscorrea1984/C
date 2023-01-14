#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void func(void* x) {
  double* pd = (double*) x;
  printf("%lf\n",*pd);
}

int main(int argc, char **argv) {

  double d = 2.5;
  func((void*) &d);
  return 0;
  
}
