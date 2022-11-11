#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct S Node;

struct S {
  int k;
  Node *next;
  Node *prev;
};

Node * insert(Node *L, int l) {
  if(L == NULL) {
    L = (Node *)malloc(sizeof(Node));
    L->k = l;
    L->next = L;
    L->prev = L;
    return L;
  } else if(L->next == L) {
      L->next = (Node *)malloc(sizeof(Node));
      L->next->k = l;
      L->next->prev = L;
      L->next->next = L;
      return L;
  } else {
    Node *aux = (Node *)malloc(sizeof(Node));
    aux->k = l;
    aux->next = L->next;
    aux->prev = L;
    L->next->prev = aux;
    L->next = aux;
    return L;
  }
}

Node * delete(Node *L, int l) {
    Node *aux = L;
  if(L->k == l) {
    L = L->next;
    free(aux);
    return L;
  } else {
    while(aux->k != l)
      aux = aux->next;
    aux->prev->next = aux->next;
    aux->next->prev = aux->prev;
    free(aux);
    return L;
  }
}

Node * update(Node *L, int k, int l) {
  Node *aux = L;
  if(L->k == k) {
    L->k = l;
    return L;
  }
  else {
    while(aux->k != k)
      aux = aux->next;
    aux->k = l;
    return L;
  }
}

int main(int argc, char **argv) {

  /* --- */
  Node *L = NULL;

  L = insert(L,5);
  L = insert(L,4);
  L = insert(L,3);
  L = insert(L,2);
  L = insert(L,1);

  Node *aux = L;

  do {
    printf(" %d ",aux->k);
    if(aux->next != L)
      fputs("<--->",stdout);
    else
      putchar('\n');
    aux = aux->next;
  } while(aux != L);

  L = update(L,2,0);

  aux = L;

    do {
      printf(" %d ",aux->k);
    if(aux->next != L)
      fputs("<--->",stdout);
    else
      putchar('\n');
    aux = aux->next;
  } while(aux != L);

    L = delete(L,4);
    
  aux = L;

    do {
      printf(" %d ",aux->k);
    if(aux->next != L)
      fputs("<--->",stdout);
    else
      putchar('\n');
    aux = aux->next;
  } while(aux != L);

  return 0;

}
