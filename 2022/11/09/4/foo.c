#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct s {
  int k;
  struct s *next;
};

typedef struct s Node;

Node *L = NULL;

void insert(Node *n) {
  if(L == NULL) {
    L = n;
  } else {
    Node *aux = L;
    while(aux->next != NULL)
      aux = aux->next;
    aux->next = n;
  }
}

void delete(int k) {
    Node *aux = L;
  while(aux->next->k != k)
    aux = aux->next;
  Node *d = aux->next;
  aux->next = aux->next->next;
  free(d);    
}

void update(int k, int l) {
  Node *aux = L;
  while(aux->k != k)
    aux = aux->next;
  aux->k = l;
}

int main(int argc, char **argv) {

  /* --- */

  Node *pn = (Node *)malloc(sizeof(Node));
  pn->k = 5;
  pn->next = NULL;
  insert(pn);

  pn = (Node *)malloc(sizeof(Node));
  pn->k = 4;
  pn->next = NULL;
  insert(pn);
  
  pn = (Node *)malloc(sizeof(Node));
  pn->k = 3;
  pn->next = NULL;
  insert(pn);
  
  pn = (Node *)malloc(sizeof(Node));
  pn->k = 2;
  pn->next = NULL;
  insert(pn);
  
  pn = (Node *)malloc(sizeof(Node));
  pn->k = 1;
  pn->next = NULL;
  insert(pn);

  
  Node *p = L;
  do {
    printf("%d ---> ",p->k);
    p = p->next;
  } while (p != NULL);

  return 0;

}
