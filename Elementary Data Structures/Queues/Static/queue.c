#include <stdio.h>
#include <stdlib.h>

#define N 12

typedef struct Queue {
  int v[N];
  int head;
  int tail;
} Queue;

void enqueue(Queue *Q,int x) {
  Q->v[Q->tail] = x;
  if(Q->tail == N-1)
    Q->tail = 0;
  else
    Q->tail++;
}

int dequeue(Queue *Q) {
  int x = Q->v[Q->head];
  if(Q->head == N-1)
    Q->head = 0;
  else
    Q->head++;
  return(x);
}

void printqueue(Queue *Q) {
  int i = Q->head;
  do {
    printf("%d,",Q->v[i]);
    if(i == N-1)
      i = 0;
    else
      i++;
  } while(i != Q->tail);
  putchar('\n');
}

int main(int argc, char **argv) {

  /* --- */

  Queue Q;

  Q.head = 0;
  Q.tail = 0;
/*
  Q.head = 6;
  Q.tail = 6;

  enqueue(&Q,15);
  enqueue(&Q,6);
  enqueue(&Q,9);
  enqueue(&Q,8);
  enqueue(&Q,4);

  printqueue(&Q);

  enqueue(&Q,17);
  enqueue(&Q,3);
  enqueue(&Q,5);

  printqueue(&Q);

  printf("%d\n",dequeue(&Q));

  printqueue(&Q);
*/
  return 0;

}
