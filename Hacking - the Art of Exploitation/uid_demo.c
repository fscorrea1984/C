#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char **argv) {

  printf("real uid: %d\n",getuid());
  printf("effective uid: %d\n",geteuid());
  
}
