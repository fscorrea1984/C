#include<math.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

unsigned long l[4];
long A[8];
char c[4];

int main (int argc, const char *argv[]) {

  unsigned long aux = 0;
  
  for(int k = 0; k < 4; k++) {
    char *arr;
    arr = (char *) malloc(strlen(argv[k+1])+1);
    strcpy(arr,argv[k+1]);
    char ch[9];
    ch[8] = '\0';
  
    for(int i = 0; i < 8; i++) {
      ch[i] = *(arr+i);
      //printf("ch[%d] is %c\n",i,ch[i]);
    }
  
    for(int i = 0; i < 8; i++) {
      char x = *(arr+i);
      //printf("x is %c\n",x);
      A[i] = (long) x - 0x30;
    }

    for(int i = 0; i < 8; i++) {
      float exp = 7.0 - (float) i;
      aux += A[i] * (long) pow(2.0,exp);
    }
    
    l[k] = aux;
    aux = 0;
    c[k] = (char) l[k];
 
    //printf("c[%d] is '%c'\tl[%d] is %li\n",k,c[k],k,l[k]);
    //printf("l[%d] is %li\n"k,l);

  }
  
  for(int i = 3; i >= 0; i--)
    putchar((int) c[i]);

  //putchar('\n');
  
  return 0;
 
}
