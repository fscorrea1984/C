#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv) {

  int i;

  for(i = 0; i < 10; i++) // Loop 10 times
    printf("Hello World\n"); // Put the string to the output

  return 0; // Tell the program exited without errors
  
}
