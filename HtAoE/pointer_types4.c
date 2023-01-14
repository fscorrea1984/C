#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {

  int i;
  char char_array[5] = { 'a' , 'b' , 'c' , 'd' , 'e' };
  int int_array[5] = { 1 , 2 , 3 , 4 , 5 };

  void *void_pointer;

  void_pointer = (void *) int_array;
  
  for(i = 0 ; i < 5 ; i++) { // iterate through the int array with the int pointer
    printf("[integer pointer] points to %p, which contains the integer %d\n",void_pointer,*((int *) void_pointer));
    void_pointer = (void *) ((int *) void_pointer + 1);
  }

  void_pointer = (void *) char_array;

  for(i = 0 ; i < 5 ; i++) { // iterate through the char array with the char pointer
    printf("[char pointer] points to %p, which contains the char %c\n",void_pointer,*((char *) void_pointer));
    void_pointer = (void *) ((char *) void_pointer + 1);
  }
  
}
