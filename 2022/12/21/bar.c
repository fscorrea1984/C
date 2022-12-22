#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct LinkedList {

  struct LinkedList *next;
  struct LinkedList *prev;
  int key;
} List;

List *ListSearch(List *L,int k) {

  List *x = L;

  while(x != NULL && x->key != k)
    x = x->next;

  return(x);
  
}

void ListPrepend(List *L,List *x) {

  x->next = L;
  x->prev = NULL;

  if(L != NULL)
    L->prev = x;
  L = x;
  
}

void ListInsert(List *x,List *y) {

  x->next = y->next;
  x->prev = y;

  if(y->next != NULL)
    y->next->prev = x;
  y->next = x;
  
}

void ListDelete(List *L,List *x) {

  if(x->prev != NULL)
    x->prev->next = x-> next;
  else
    L = x->next;

  if(x->next != NULL)
    x->next->prev = x->prev;

  free(x);
  
}

void printlist(List *L) {

  List *aux = L;

  fputs("L ---> ",stdout);

  do {
    (aux->next != NULL) ? fprintf(stdout,"%d <---> ",aux->key) : fprintf(stdout,"%d ---> NULL",aux->key);
    aux = aux->next;
  } while(aux != NULL);

  puts("\n");
    
}

int main(int argc, char **argv) {

  List *L = (List *)malloc(sizeof(List));
  
  List *aux = L;

  aux->key = 9;
 
  aux->prev = NULL;
  aux->next = (List *)malloc(sizeof(List));

  aux->next->prev = aux;
  aux->next->key = 16;

  aux = aux->next;

  aux->next = (List *)malloc(sizeof(List));
  aux->next->prev = aux;
  aux->next->key = 4;

  aux = aux->next;

  aux->next = (List *)malloc(sizeof(List));
  aux->next->prev = aux;
  aux->next->key = 1;

  aux = aux->next;
  aux->next = NULL;

  printlist(L);

  aux = (List *)malloc(sizeof(List));
  aux->key = 25;
  aux->next = NULL;
  aux->prev = NULL;

  ListPrepend(L,aux);

  printlist(L);

  aux = (List *)malloc(sizeof(List));

  aux->key = 36;

  List *aux2 = ListSearch(L,9);

  ListInsert(aux,aux2);

  printlist(L);

  aux = ListSearch(L,4);

  ListDelete(L,aux);

  printlist(L);

  aux = L;
  
  do {

    aux = aux->next;

    if(aux != NULL)
      free(aux->prev);

  } while(aux != NULL);
  
  return 0;

}

/* Goal: hardcode list of four nodes L <---> 9 <---> 16 <---> 4 <---> 1

   output must be L ---> 25 <---> 9 <---> 16 <---> 4 <---> 1 ---> NULL

   output must be L ---> 25 <---> 9 <---> 36 <---> 16 <---> 4 <---> 1 ---> NULL

   output must be L ---> 25 <---> 9 <---> 36 <---> 16 <---> 1 ---> NULL
*/
