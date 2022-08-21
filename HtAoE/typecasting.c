#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {

  int a,b;
  float c,d;

  a = 13;
  b = 5;

  c = a / b; // Divide using integers
  d = (float) a / (float) b; // Divide using typecast as floats

  printf("[integers]\t a = %d\t b = %d\n",a,b);
  printf("[floats]\t c = %f\t d = %f\n",c,d);
  
}
