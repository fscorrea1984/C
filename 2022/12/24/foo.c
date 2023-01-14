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
Stack *Pop(Stack *S) {
  if(empty(S)) {
  fputs("underflow",stderr);
  putchar('\n');
  } else
    S->top = S->top->prev;

  return(S->top);

  /*do {
    
      /*(aux>prev != NULL) ? fprintf(stdout,"%d <---> ",aux) : fprintf(stdout,"%d ---> NULL",aux->key);
    (aux != NULL) ? fprintf(stdout,"%d <---> ",aux) : fprintf(stdout,"%d ---> NULL",aux->key);
    aux = aux->prev;
    free(aux->next);
    
  } while(aux != NULL;)*/

}
/* ---------------------------------------------------------------------------------------------------- */
/*
makestack (Stack *S,Stack *aux) {XSxw
  
  for(int i = 1; i <= 9; i++) {
    Push(S,aux,i);
      // S = (Stack *)malloc( (sizeof(Stack) ) {
  }

}
/*

/* ---------------------------------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------------------------------- */

void printstack(Stack *S,Stack *aux) {

  S->top = (Stack *)malloc(sizeof(Stack));
  aux = S->top;

  /*while(aux-prev != NULL)
    aux = S->top; */

  fputs("S ---> ",stdout);

  for(int i = 1; i <= 9; i++) {
    //Push(S,aux,i);
    aux = S.top;
	        
  do {
    
    (aux->prev != NULL) ? fprintf(stdout,"%d <---> ",aux) : fprintf(stdout,"%d ---> NULL",aux->key);
    aux = aux->prev;
    
  } while(aux != NULL);

  puts("\n");
    
	}
}
}
?/* ---------------------------------------------------------------------------------------------------- */


int main(int argc, char **argv) {

  /* --- */

  Stack *S;
  Stack *aux;
  aux->key = 0;
  aux->prev = NULL;
  aux->next = NULL;

  //printstack(S,aux);

  while (aux != NULL) {

    aux = Pop(S);
    (aux != NULL) ? fprintf(stdout,"%d <---> ",aux) : fprintf(stdout,"%d ---> NULL",aux->key);
    aux = aux->prev;
    free(aux->next);
  
  };
  
  return 0;
}}
}
