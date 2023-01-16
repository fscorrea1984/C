#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int key;
  struct Node *next;  
  struct Node *prev;
} Node;

Node *tail = NULL;

void insert(Node **L,int k) {
  Node *aux = (Node *)malloc(sizeof(Node));
  aux->key = k;
  if(*L == NULL) {
    *L = aux;
    tail = *L;
    tail->next = *L;
    tail->prev = *L;
  }
  else {
    aux->next = *L;
    *L = aux;
    (*L)->next->prev = *L;
    tail->next = *L;
  }
}

void delete(Node **L,int k) {
  if(*L == NULL)
    puts("Empty list");
  else
    if((*L)->key == k) {
      Node *N = *L;
      *L = N->next;
      tail->next = *L;
      (*L)->prev = tail;
      N->next = NULL;
      free(N);
    }
    else {
      Node *aux;
      Node *N = *L;
      while(N != NULL && N->key != k) {
	aux = N;
	N = N->next;
      }
      if(N == NULL)
	printf("Key %d not found\n",k);
      else {
	aux->next = N->next;
	if(N->next != NULL)
	  N->next->prev = aux;
	N->next = NULL;
	N->prev = NULL;
	free(N);
      }
    }
}

Node *search(Node *L,int k) {
  if(L == NULL) {
    puts("Empty list");
  }
  else {
    Node *aux = L;
    while(aux != tail && aux->key != k) {
      aux = aux->next;
    }
    if(aux == tail)
      printf("Key %d was not found in the list\n",k);
    else
      if(aux->key == k)
	printf("Key %d was found in the list\n",k);
      else
	printf("Key %d was not found in the list\n",k);
  }
}

void printlist(Node *L) {
  if(L == NULL) {
    puts("Empty list");
  }
  else {
    Node *aux = L;
    while(1) {
      printf("%d ",aux->key);
      if(aux->next == L) {
	putchar('\n');
	break;
      }
      else
	aux = aux->next;
    }
  }
}

int main(int argc, char **argv) {

  /* --- */

  Node *L;

  insert(&L,4);
  insert(&L,7);
  insert(&L,13);
  insert(&L,29);

  printlist(L);

  search(L,20);
  search(L,7);
  
  delete(&L,7);

  printlist(L);

  delete(&L,29);

  printlist(L);
  
  Node *aux = L;
  while(aux != NULL) {
    Node *N = aux;
    aux = aux->next;
    N->next = NULL;
    N->prev = NULL;
    free(N);
  }
  
  return 0;

}
