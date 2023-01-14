#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv) {

  int x;
  int **a = (int **)malloc(3*5*sizeof(int *)); // a[3][5]
  *a = (int *)malloc(5*sizeof(int));
  *(a+1) = (int *)malloc(5*sizeof(int));
  *(a+2) = (int *)malloc(5*sizeof(int));
  int *p;

  for(int i = 0; i < 3; i++)
    for(int j = 0; j < 5; j++) {
      a[i][j] = i+j;
    }
  
  for(int i = 0; i < 3; i++)
    for(int j = 0; j < 5; j++)
      printf("%d\n",**(a+i+2));

  free(a);

  return 0;
  
}

/*



*/
