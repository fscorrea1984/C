#include<stdio.h>
#include<stdlib.h>

int f(int x, int y) {
  int result;
  result = result + (x + y);
  return x+y;
}

int main(int argc, char **argv) {

  int x=2, y=3;

  printf("%d\n",f(x,y));

  return 0;
  
}

/*

extern
static
auto
register

*/
