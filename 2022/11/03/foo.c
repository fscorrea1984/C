#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*typedef struct {
  int a;
  int b;
  } foo;*/

int f(int *x) {
  return ++(*x);
}

int main(int argc, char **argv) {

  int a[4] = { 7, -7, 13, 19 };
  int x = 2;
  int y = f(&x);
  unsigned z = (unsigned)y;
  unsigned Z = 0;
  /*
  unsigned char c1 = '\x3A';
  unsigned char c2 = '\x35';
  unsigned char c3 = '\x03';
  
  putchar(c1 & c2);
  putchar(c1 ^ c3);
  putchar(c1 | c2);
  putchar('\n');*/
    
    /*unsigned char
    unsigned char
    unsigned char
    unsigned char
    */
  /*
  int b[5];
  b[0] = a[0] + a[2]; // 20
  b[1] = a[0] - a[2]; // -6
  b[2] = a[0] * a[2]; // 91
  b[3] = 15/2; // 7
  b[4] = a[3] % a[2]; // 6

  for(int i = 0; i < 5; i++)
    printf("%d\n",b[i]);
  */
  
  //foo mystruct = { .a = 5, .b = 7 };
  //foo *pfoo = &mystruct;
  /*
  printf("%d\n",z >> 1);
  printf("%d\n",z >> 2);
  printf("%d\n",z >> 4);
  printf("%d\n",z << 1);
  printf("%d\n",z << 2);
  printf("%d\n",z << 4);
  */

  int A=50, B=10;
  //A = 50;
  //B = 20;

  //(A < B)? puts("A menor que B") : puts("B menor que A");

  int C = (A < B)? A : B;

  printf("%d\n",C);
  
  return 0;
  
}

