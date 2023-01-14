#include<stdio.h>
#include<stdlib.h>

enum colors_t { BLACK, BLUE, GREEN, CYAN, RED, PURPLE, YELLOW, WHITE } color;

int main(int argc, char **argv) {

  //enum colors_t color = BLUE;
  color = BLUE;
  printf("%d\n",color);
  /*  for(enum colors_t i = BLACK; i <= WHITE; i++){
    printf("%d\n",i);
    }*/
  
  return 0;

}
