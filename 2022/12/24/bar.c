#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct LIFO {
  struct LIFO *top;
  struct LIFO *next;
  struct LIFO *prev;
  int key;
} Stack;

//typedef struct LIFO Stack;

int empty(Stack *S) {
  
  if(S->top == NULL)
    return(1);
  else
    return(0);
  
}

/* ---------------------------------------------------------------------------------------------------- */

void Push(Stack *S,Stack *x,int k) {

  x = (Stack *)malloc(sizeof(Stack));
  x->key = k;
  x->prev = S->top->prev;
  S->top = x;
  //x->prev = S->top->prev;
    
}
/* ---------------------------------------------------------------------------------------------------- */
/**Stack *Pop(Stack *S) {
  if(empty(S)) {
  fputs("underflow",stderr);
  putchar('\n');
  } else
    S->top = S->top->prev;



/* Svoid printstack(Stack *S,Stack *aux) {

  S->top = (Stack *)malloc(sizeof(Stack));
  aux = S->top;

  /*while(aux-prev != NULL)
    aux = S->top; */

/* fputs(...,"S ---> ",stdout); 

  for(int i = 1; i <= 9; i++) {
    Push(S,aux,i);
	        
  do {
    
    (aux->prev != NULL) ? fprintf(stdout,"%d <---> ",aux) : fprintf(stdout,"%d ---> NULL",aux->key);
    aux = aux->prev;
    
  } while(aux != NULL);

  puts("\n");

  return(S->top);*/    


/* ---------------------------------------------------------------------------------------------------- */

int main(int argc, char **argv) {

  Stack *S;
  Stack *aux;

  S->top = (Stack *)malloc(sizeof(Stack));
  S->top->prev = NULL;
  S->top->next = NULL;
  S->top->key = 0;
  aux = S->top;
  //aux->prev = S->top->prev;

  printf("%d\n",aux->key);

  return 0;
  
}
//}
