#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(int argc, char **argv) {

  time_t t;
  t = time();
  srand(&t);
  int x = rand()%10;
  ++x;
  return 0;
  
}
