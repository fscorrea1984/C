#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv) {

  int *M;

  int d1 = (int) strtol(argv[1],NULL,10);
  int d2 = (int) strtol(argv[2],NULL,10);

  M = (int *) malloc(sizeof(int)*3*5);

  for(int i = 0; i < 3; i++)
    for(int j = 0; j < 5; j++)
      *(M+i+j-1) = i + j;

  for(int i = 0; i < 3; i++) {
    putchar('\n');
    for(int j = 0; j < 5; j++) {
      printf(" %d\n",*(M+i+j-1));
	}
  }
  
  free(M);
  
  return 0;
  
}

