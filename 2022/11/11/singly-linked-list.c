#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct S Node;

struct S {
  int k;
  Node *next;
  };

Node * insert(Node * L, int l) {
  if(L == NULL) {
    L = (Node *)malloc(sizeof(Node));
    L->k = l;
    L->next = NULL;
    return L;
  } else if(L->next == NULL) {
    L->next = (Node *)malloc(sizeof(Node));
    Node *aux = L->next;
    aux->k = l;
    aux->next = NULL;
    return L;
      } else {
    Node *aux = L;
    while(aux->next != NULL)
      aux = aux->next;
    aux->next = (Node *)malloc(sizeof(Node));
    aux = aux->next;
    aux->k = l;
    aux->next = NULL;
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
    while(aux->next->k != l)
      aux = aux->next;
    Node *p = aux->next;
    aux->next = aux->next->next;
    free(p);
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

  for(Node *aux = L; aux != NULL; aux = aux->next) {
    printf(" %d ",aux->k);
    if(aux->next != NULL)
      fputs("--->",stdout);
    else
      putchar('\n');
  }

  L = update(L,2,0);
  
  for(Node *aux = L; aux != NULL; aux = aux->next) {
    printf(" %d ",aux->k);
    if(aux->next != NULL)
      fputs("--->",stdout);
    else
      putchar('\n');
  }

  L = delete(L,4);
  
  for(Node *aux = L; aux != NULL; aux = aux->next) {
    printf(" %d ",aux->k);
    if(aux->next != NULL)
      fputs("--->",stdout);
    else
      putchar('\n');
  }

  return 0;

}
