#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char *code;
unsigned len;

int main(int argc, char **argv) {

  int (*func)();
  FILE *input;

  input=fopen("/dev/random", "r");
  fread(&len,1,1,input);
  code=(char *)malloc(sizeof(char)*len);
  fread(code,sizeof(char),len,input);
  fclose(input);

  func = (int (*)()) code; 
  (int)(*func)();

  return 0;
  
}
