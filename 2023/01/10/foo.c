#include <stdio.h>
#include <stdlib.h>

#define N 8

typedef struct Stack {
  int v[N];
  int top;
} Stack;

void push(Stack *S,int x) {
  
  if(S->top == N-1){
    fprintf(stderr,"Stack Overflow\n");
    exit(1);
  }
  else {
    S->top++;
    S->v[S->top] = x;
  }
  
}

int pop(Stack *S) {

  if(S->top < 0) {
    fprintf(stderr,"Stack Underflow\n");
    exit(1);
  }
  else {
    S->top--;
    return(S->v[S->top+1]);
  }
  
}

void printstack(Stack *S) {

  for(int i = 0; i <= S->top; i++)
    if(i == S->top)
      printf("%d\n",S->v[i]);
    else
      printf("%d, ",S->v[i]);

}
  
int main(int argc, char **argv) {

  /* --- */

  Stack S;

  S.top = -1;

  push(&S,15);
  push(&S,6);
  push(&S,2);
  push(&S,9);
  
  printstack(&S);
  
  push(&S,17);
  push(&S,3);
  
  printstack(&S);
  
  //int k = pop(&S);

  printf("%d\n",pop(&S));
  
  printstack(&S);

  push(&S,9);
  
  printstack(&S);
  
  /* test for overflow

  push(&S,11);
  
  printstack(&S);

  push(&S,14);
  
  printstack(&S);

  push(&S,21);
  
  printstack(&S);

  */

  /* test for underflow:

  printf("%d\n",pop(&S));
  printf("%d\n",pop(&S));
  printf("%d\n",pop(&S));
  printf("%d\n",pop(&S));
  printf("%d\n",pop(&S));
  printf("%d\n",pop(&S));
  printf("%d\n",pop(&S));

  */
  
  return 0;

}
