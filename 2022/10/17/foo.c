#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv) {

  char c1 = '\x58';
  char c2 = '\xD8';
  
  printf("%c\n",c1);
  printf("%d\n",c1);
  printf("0x%x\n",c1);

  printf("%c\n",c2);
  printf("%d\n",c2);
  printf("0x%x\n",c2);

  return 0;
  
}
