#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {

  char username[20];

  printf("Enter your name: ");
  scanf("%s",username);
  printf("Hello %s\n",username);
  printf("Program exited normally");

  return 0;

}
