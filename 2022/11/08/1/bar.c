#include<stdio.h>
#include<stdlib.h>

extern int e = 55;

void f() {
  for(int i = 0; i < 5; i++){
    //int a = 10;
    int a;
    static int b = 5;
    a++;
    b++;
    printf("%d %d\n",a,b);
  }
}

int main(int argc, char **argv) {

  //printf("%d\n",b);
  f();

  f();

  printf("%d\n",g(5));
  
  return 0;
  
}

/*

extern
static
auto
register

*/
