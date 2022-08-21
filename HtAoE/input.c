#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {

  char message[13];
  int count, i;

  strcpy(message,"Hello World!");
  message[12] = '\0';
  
  printf("Repeat how many tymes? ");
  scanf("%d",&count);

  for(i = 0; i < count; i++)
    printf("%3d - %s\n",i,message);
  
}
