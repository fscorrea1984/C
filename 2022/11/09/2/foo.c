#include<stdio.h>
#include<stdlib.h>
#include<signal.h>

extern void handler(int);

int main(int argc, char **argv) {

  signal(SIGINT,&handler);

  while(1);
  
  return 0;
  
}
