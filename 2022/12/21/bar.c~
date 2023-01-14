#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ------------------------------------------------------------------------------------------------------- */

typedef struct LinkedList {
  //LinkedList *head;
  struct LinkedList *next;
  struct LinkedList *prev;
  int key;
} List;

/* ------------------------------------------------------------------------------------------------------- */

List *ListSearch(List *L,int k) {

  List *x = L;

  while(x != NULL && x->key != k)
    x = x->next;

  return(x);
  
}

/* ------------------------------------------------------------------------------------------------------- */

void ListPrepend(List *L,List *x) {

  x->next = L;
  x->prev = NULL;

  if(L != NULL)
    L->prev = x;
  L = x;
  
}

/* ------------------------------------------------------------------------------------------------------- */

void ListInsert(List *x,List *y) {

  x->next = y->next;
  x->prev = y;

  if(y->next != NULL)
    y->next->prev = x;
  y->next = x;
  
}

/* ------------------------------------------------------------------------------------------------------- */

void ListDelete(List *L,List *x) {

  if(x->prev != NULL)
    x->prev->next = x-> next;
  else
    L = x->next;

  if(x->next != NULL)
    x->next->prev = x->prev;

  free(x);
  
}

/* ------------------------------------------------------------------------------------------------------- */

void printlist(List *L) {

  List *aux = L;

  fputs("L ---> ",stdout);

  do {
    (aux->next != NULL) ? fprintf(stdout,"%d <---> ",aux->key) : fprintf(stdout,"%d ---> NULL",aux->key);
    aux = aux->next;
  } while(aux != NULL);

  puts("\n");
    
}

/* ------------------------------------------------------------------------------------------------------- */

int main(int argc, char **argv) {

/* ------------------------------------------------------------------------------------------------------- */

  List *L = (List *)malloc(sizeof(List));
  
  List *aux = L;

  // Goal: hardcode list of four nodes 9 <---> 16 <---> 4 <---> 1

  aux->key = 9;

  // L ---> 9
  //    aux ^
  
  aux->prev = NULL;
  aux->next = (List *)malloc(sizeof(List));

  // L ---> 9
  //    aux ^
  
  aux->next->prev = aux;
  aux->next->key = 16;

  // L ---> 9 <---> 16
  //    aux ^  
  
  aux = aux->next;

  // L ---> 9 <---> 16
  //            aux ^
  
  aux->next = (List *)malloc(sizeof(List));
  aux->next->prev = aux;
  aux->next->key = 4;

  // L ---> 9 <---> 16 <---> 4
  //            aux ^

  aux = aux->next;

  // L ---> 9 <---> 16 <---> 4
  //                     aux ^


  aux->next = (List *)malloc(sizeof(List));
  aux->next->prev = aux;
  aux->next->key = 1;

  // L ---> 9 <---> 16 <---> 4 <---> 1
  //                     aux ^

  aux = aux->next;
  aux->next = NULL;

  printlist(L);

  // L ---> 9 <---> 16 <---> 4 <---> 1 ---> NULL
  //                             aux ^
  

  // hardcode list of four nodes 9 <---> 16 <---> 4 <---> 1 ---> NULL

  // Initlal list hardcoded

/* ------------------------------------------------------------------------------------------------------- */

  // prepend node with key 25 as per figure 10.4 b)

  aux = (List *)malloc(sizeof(List));
  aux->key = 25;
  aux->next = NULL;
  aux->prev = NULL;

  ListPrepend(L,aux);

  printlist(L);
  
  // output must be

  // L ---> 25 <---> 9 <---> 16 <---> 4 <---> 1 ---> NULL

 
/* ------------------------------------------------------------------------------------------------------- */
  
  // insert node with key 36 after node with key 9 as per figure 10.4 c)

  // 1 - allocate node
  aux = (List *)malloc(sizeof(List));
  // 1.1 - set key
  aux->key = 36;

  // 2 - declare aux2 (where-to-insert) = ListSearch(L,9)
  List *aux2 = ListSearch(L,9);

  ListInsert(aux,aux2);

  printlist(L);

  // output must be

  // L ---> 25 <---> 9 <---> 36 <---> 16 <---> 4 <---> 1 ---> NULL

/* ------------------------------------------------------------------------------------------------------- */
  
  // delete node with key 4 as per figure 10.4 d)

  // 1 - make aux point to node with key 4 (the node to-be-deleted)
  aux = ListSearch(L,4);

  ListDelete(L,aux);

  printlist(L);
  
  // output must be

  // L ---> 25 <---> 9 <---> 36 <---> 16 <---> 1 ---> NULL
  
/* ------------------------------------------------------------------------------------------------------- */

  aux = L;
  
  do {

    aux = aux->next;

    if(aux != NULL)
      free(aux->prev);

  } while(aux != NULL);
  
/* ------------------------------------------------------------------------------------------------------- */
  
  return 0;

}
