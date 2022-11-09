#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv) {

  int a[16] = { 32, -23, -435, 55,
		1, 3, 5, 7,
		343, -1, -2, -3,
		255, 34, -1, 0
  };

  for(int i = 0; i < 16; i++)
    printf("%d\n",a[i]);
  
  return 0;
  
}
