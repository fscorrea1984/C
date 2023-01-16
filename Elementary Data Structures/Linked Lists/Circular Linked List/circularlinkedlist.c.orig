#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int key;
  Node *next;  
  Node *prev;
} Node;

void insert(Node *L,int k) {
  Node *aux = (Node *)malloc(sizeof(Node));
  aux->key = k;
  aux->next = L->next;
  aux->prev = L;
  L->next = aux;
}

void delete(Node *L) {
  Node *aux = L->next;
  L->next = aux->next;
  L->next->prev = L;
  aux->next = NULL;
  aux->prev = NULL;
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
}

void printlist(Node *L) {
  Node *aux = L;
  while(aux != NULL) {
    if(aux->next != NULL)
      printf("%d, ",aux->key);
    else
      printf("%d\n",aux->key);
  }
}

int main(int argc, char **argv) {

  /* --- */

  /* dynamically allocate first node of list
  Node *L = (Node *)malloc(sizeof(Node));
  //L->key = some integer
  L->next = L;
  L->prev = L;
  */

  /* free every allocated node
  Node *aux = L;
  while(aux != NULL) {
    Node *N = aux;
    aux = aux->next;
    free(N);
  }
  */

  return 0;

}
