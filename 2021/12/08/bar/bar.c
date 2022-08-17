#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {

  const int M[9][9] = { {1,0,0,1,0,1,0,0,1},
			{0,1,0,1,0,1,0,1,0},
			{0,0,1,1,1,1,1,0,0},
			{0,1,1,0,0,0,1,1,0},
			{0,0,1,0,0,0,1,0,0},
			{0,1,1,0,0,0,1,1,0},
			{0,1,0,0,0,0,0,1,0},
			{0,0,1,1,1,1,1,1,0},
			{1,0,0,1,0,1,0,0,1} };
  
  int count = 0;

  for(int i = 0; i < 9; i++)
    for(int j = 0; j < 9; j++)
      count += (M[i][j])? 1 : 0;
  /*
  for(int i = 0; i < 9; i++)
    for(int j = 0; j < 9; j++)
      count += (M[i][j])? 1 : 0;
*/
  printf("count = %d\n",count);
  //printf("count[0] = %d\n",count[0]);
  //printf("count[1] = %d\n",count[1]);

  return 0;
  
}
