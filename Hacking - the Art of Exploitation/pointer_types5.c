#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {

  int i;
  char char_array[5] = { 'a' , 'b' , 'c' , 'd' , 'e' };
  long int_array[5] = { 1 , 2 , 3 , 4 , 5 };

  unsigned long hacky_nonpointer;

  hacky_nonpointer = (unsigned long) char_array;
  
  for(i = 0 ; i < 5 ; i++) { // iterate through the char array with the char_pointer
    printf("[hacky_nonpointer] points to %p, which contains the char %c\n",hacky_nonpointer,*((char *) hacky_nonpointer));
    hacky_nonpointer = hacky_nonpointer + sizeof(char);
  }

  hacky_nonpointer = (unsigned long) int_array;

  for(i = 0 ; i < 5 ; i++) { // iterate through the int array with the int_pointer
    printf("[hacky_nonpointer] points to %p, which contains the integer %d\n",hacky_nonpointer,*((long *) hacky_nonpointer));
    hacky_nonpointer = hacky_nonpointer + sizeof(long);
  }
  
} // here I needed unsigned longs instead of unsigned ints, because 64-bits architecture have 64-bit address and sizeof(int) is 4 (bytes)
