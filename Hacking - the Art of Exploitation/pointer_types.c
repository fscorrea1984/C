#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {

  int i;
  char char_array[5] = { 'a' , 'b' , 'c' , 'd' , 'e' };
  int int_array[5] = { 1 , 2 , 3 , 4 , 5 };

  char *char_pointer;
  int *int_pointer;

  char_pointer = char_array;
  int_pointer = int_array;

  for(i = 0 ; i < 5 ; i++) { // iterate through the int array with the int pointer
    printf("[integer pointer] points to %p, which contains the integer %d\n",int_pointer,*int_pointer);
    int_pointer = int_pointer + 1;
  }


  for(i = 0 ; i < 5 ; i++) { // iterate through the char array with the char pointer
    printf("[char pointer] points to %p, which contains the char %c\n",char_pointer,*char_pointer);
    char_pointer = char_pointer + 1;
  }
  
}
