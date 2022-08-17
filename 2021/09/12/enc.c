#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef unsigned int u_int;

const char A[26] = { 'A' , 'B' , 'C' , 'D' , 'E' , 'F' , 'G' , 'H' , 'I' , 'J' , 'K' , 'L' , 'M' , 'N' , 'O' , 'P' , 'Q' , 'R' , 'S' , 'T' , 'U' , 'V' , 'W' , 'X' , 'Y' , 'Z' };
const u_int B[26] = { 0x0A , 0x1E , 0x01 , 0x0E , 0x10 , 0x1C , 0x02 , 0x13 , 0x19 , 0x12 , 0x23 , 0x0B , 0x08 , 0x09 , 0x1A , 0x22 , 0x03 , 0x1B , 0x05 , 0x1F , 0x0F , 0x0C , 0x16 , 0x15 , 0x14 , 0x18 };

int main(int argc, char **argv) {

  int c;
  u_int index,offset;
  
  FILE *fdi = fopen(argv[1],"r+");
  FILE *fdo = fopen("outflow.bin","w+");

  while(1) {
    if (feof(fdi)) break;
    c = fgetc(fdi);
    if (islower(c)) {
      index = (unsigned int)c - 0x61;
      offset = B[index];
      fputc('\xE0',fdo);
      fputc('\xA4',fdo);
      fputc('\x84'+offset,fdo);
    }
    else
      fputc(c,fdo);
  }

  fclose(fdo);
  fclose(fdi);

  return 0;
  
}
