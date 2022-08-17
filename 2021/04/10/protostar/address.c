/* Got at ShellBlade site */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv) {

  char *ptr = ("SHELL");
  if(ptr != NULL){
    printf("estimated address: %p\n",ptr);
    return 0;
  }
}
