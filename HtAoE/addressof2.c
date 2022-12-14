#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {

  int int_var = 5;
  int *int_ptr;
  int_ptr = &int_var; // put the address of int_var into int_ptr
  
  printf("int_ptr = 0x%08x\n",int_ptr);
  printf("int_ptr = 0x%08x\n",&int_ptr);
  printf("int_ptr = 0x%08x\n\n",*int_ptr);
  
  printf("int_var is located at 0x%08x and contains %d\n",&int_var,int_var);
  printf("int_ptr is located at 0x%08x, contains 0x%08x, and points to %d\n\n",&int_ptr,int_ptr,*int_ptr);
  
}
