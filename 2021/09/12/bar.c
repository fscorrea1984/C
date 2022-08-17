#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char A[26] = { 'A' , 'B' , 'C' , 'D' , 'E' , 'F' , 'G' , 'H' , 'I' , 'J' , 'K' , 'L' , 'M' , 'N' , 'O' , 'P' , 'Q' , 'R' , 'S' , 'T' , 'U' , 'V' , 'W' , 'X' , 'Y' , 'Z' };

int main(int argc, char **argv) {

  int B[26];
  
  //system("shuf -i 0-35 > C");
  FILE *fd = fopen("C","r+");
  for(int i = 0; i < 26; i++)
    fscanf(fd,"%d\n",&B[i]);
  for(int i = 0; i < 26; i++) {
    if (B[i] <= 9)
      printf("%c ---> 0%d ---> U+090%d ---> ",A[i],B[i],B[i]);
    else
      printf("%c ---> %d ---> U+09%d ---> ",A[i],B[i],B[i]);
    if ((unsigned int)B[i] <= 0xF)
      printf("0x0%X\n",(unsigned int)B[i]);
    else
      printf("0x%X\n",(unsigned int)B[i]);
  }
  fclose (fd);

  return 0;
  
}
