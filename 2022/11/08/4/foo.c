#include<stdio.h>
#include<stdlib.h>

extern int e = 55;

void f() {
  for(int i = 0; i < 5; i++){
    int a = 10;
    static int b = 5;
    printf("%d %d\n",++a,++b);
  }
}

int main(int argc, char**argv) {

  f();

  printf("%d\n",g(5));

  f();

  /*register int x = 7;
    int *p = &x;*/
  return 0;
  
}


/*



 */
