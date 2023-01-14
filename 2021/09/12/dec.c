#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef unsigned int u_int;

const char A[26] = { 'A' , 'B' , 'C' , 'D' , 'E' , 'F' , 'G' , 'H' , 'I' , 'J' , 'K' , 'L' , 'M' , 'N' , 'O' , 'P' , 'Q' , 'R' , 'S' , 'T' , 'U' , 'V' , 'W' , 'X' , 'Y' , 'Z' };
const u_int B[26] = { 0x0A , 0x1E , 0x01 , 0x0E , 0x10 , 0x1C , 0x02 , 0x13 , 0x19 , 0x12 , 0x23 , 0x0B , 0x08 , 0x09 , 0x1A , 0x22 , 0x03 , 0x1B , 0x05 , 0x1F , 0x0F , 0x0C , 0x16 , 0x15 , 0x14 , 0x18 };

u_int get_index(u_int ui) {
  int res = -1;
  u_int i = 0;
  for(i = 0; i < 26; i++)
    if(B[i] == ui)
      res = i;
  if(res < 0) {
    fprintf(stderr,"value %#x not found in array B",ui);
    exit(-1);
  }
  else
    return((u_int)res);
}

int main(int argc, char **argv) {

  int c;
  u_int index,offset;
  
  FILE *fdi = fopen(argv[1],"r");

  while(1) {
  L1:
    c = fgetc(fdi);
    
    if (feof(fdi))
      break;

    if(c < 0x80)
      goto L2;

    if( (c == 0xE0) || (c == 0xA4) )
      goto L1;

    if( (c >= 0x80) && (c <= 0xB9) ) {
      offset = c - 0x84;
      index = get_index((u_int)offset);
      c = index + 0x61;
    }
  L2:
    if(isprint(c))
      putchar(c);
  }
    
  fclose(fdi);

  putchar('\n');
  
  return 0;
  
}
