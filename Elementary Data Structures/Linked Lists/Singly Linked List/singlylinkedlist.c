#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int key;
  Node *next;
} Node;

void insert(Node *L,int k) {
  Node *aux = (Node *)malloc(sizeof(Node));
  aux->key = k;
  aux->next = L->next;
  L->next = aux;
}

void delete(Node *L) {
  Node *aux = L;
  L = L->next;
  aux->next = NULL;
  free(aux);
}

Node *search(Node *L,int k) {
  Node *aux = L;
  while(aux != NULL) {
    if(aux->key == k)
      return(aux);
    else
      aux = aux->next;
  }
  return(aux);
}

void printlist(Node *L) {
  if(L == NULL) {
    puts("Empty list");
    goto END;
  }
  Node *aux = L;
  while(aux != NULL) {
    if(aux->next != NULL)
      printf("%d, ",aux->key);
    else
      printf("%d\n",aux->key);
  }
  END:
}

int main(int argc, char **argv) {

  /* --- */

  // dynamically allocate first node of list
  Node *L = (Node *)malloc(sizeof(Node));
  L->key = 4;
  L->next = NULL;

  insert(L,7);
  insert(L,13);

  printlist(L);

  Node *N;
  
  if((N = search(N,20)) == NULL)
    puts("Value not found");
  else
    delete(N);

  if((N = search(N,7)) == NULL)
    puts("Value not found");
  else
    delete(N);

  printlist(L);
  
  // free allocated nodes
  Node *aux = L;
  while(aux != NULL) {
    Node *N = aux;
    aux = aux->next;
    free(N);
  }
  
  return 0;

}
