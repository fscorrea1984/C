#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {

  const int M[8][8] = { {0,0,0,0,0,0,0,0},
			{0,1,1,1,1,1,1,0},
			{0,1,1,1,0,0,1,0},
			{0,0,0,1,0,0,1,0},
			{0,0,1,1,0,0,1,0},
			{0,0,0,1,1,1,0,0},
			{0,0,0,1,1,0,0,0},
			{0,0,0,0,0,0,0,0} };
  
  int count = 0;

  for(int i = 0; i < 8; i++)
    for(int j = 0; j < 8; j++)
      count += (M[i][j])? 1 : 0;

  printf("count = %d\n",count);

  return 0;
  
}
