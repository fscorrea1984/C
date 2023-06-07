/** --- Circular Singly Linked List, Insertion at the end of the list, Deletion at any given position  --- **/

#include<stdio.h>
#include<stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

int isEmpty(struct Node *head) { return(head == NULL); }

void display(struct Node *head) {
  // if there are no node in LL
  if(isEmpty(head))
    exit(0);

  struct Node *temp = head;

  //need to take care of circular structure of LL
  do {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  while(temp != head);
  printf("\n");
}

int calcSize(struct Node *head) {
  int size = 0;

  if(isEmpty(head))
    return size;
    
  struct Node *temp = head;

  do {
    size++;
    temp = temp->next;
  }
  while (temp != head);

  return size;
}

void insertLast(struct Node **head, int data) {
  struct Node *newNode = (struct Node *) malloc (sizeof (struct Node));
  newNode->data = data;

  // if its the first node being entered
  // if(*head == NULL) {
  if(isEmpty(*head)) {
    *head = newNode;
    (*head)->next = *head;
    //return;
    exit(0);
  }

  // if LL already as >=1 node
  struct Node *curr = *head;

  // traverse till last node in LL
  while(curr->next != *head) {
      curr = curr->next;
    }

  // assign LL's current last node's next as this new node
  curr->next = newNode;

  // assign this new node's next as current head of LL
  newNode->next = *head;
}

void deleteBegin(struct Node **head) {
  struct Node *tempNode = *head;

  // if there are no nodes in Linked List can't delete
  if(isEmpty(*head)) {
    puts("Linked List Empty, nothing to delete");
    exit(0);
  }

  // if only 1 node in CLL
  if(tempNode->next == *head) {
    *head = NULL;
    return;
  }

  struct Node *curr = *head;

  // traverse till last node in CLL
  while(curr->next != *head)
    curr = curr->next;

  // assign last node's next to 2nd node in CLL
  curr->next = (*head)->next;

  // move head to next node
  *head = (*head)->next;
  free(tempNode);
}

void deleteEnd(struct Node **head) {
  struct Node *tempNode = *head;
  struct Node *previous;

  // if there are no nodes in Linked List can't delete
  if(isEmpty(*head)) {
    puts("Linked List Empty, nothing to delete");
    exit(0);
  }

  // if Linked List has only 1 node
  if(tempNode->next == *head) {
    *head = NULL;
    return;
  }

  // else traverse to the last node
  while(tempNode->next != *head) {
    // store previous link node as we need to change its next val
    previous = tempNode;
    tempNode = tempNode->next;
  }
  // Curr assign 2nd last node's next to head
  previous->next = *head;
  // delete the last node
  free(tempNode);
  // 2nd last now becomes the last node
}

void deletePos(struct Node **head, int n) {
  int size = calcSize(*head);

  if(n < 1 || size < n) {
    printf("Can't delete, %d is not a valid position\n", n);
  }

  else if(n == 1)
    deleteBegin(head);

  else if(n == size)
    deleteEnd(head);

  else {
    struct Node *tempNode = *head;
    struct Node *previous;

    // traverse to the nth node 
    while(--n) {
      // store previous link node as we need to change its next val 
      previous = tempNode;
      tempNode = tempNode->next;
    }

    // change previous node's next node to nth node's next node
    previous->next = tempNode->next;
    // delete this nth node
    free(tempNode);
  }
}

int main(int argc, char **argv) {
  struct Node *head = NULL;

  // puts("Circular (Singly) Linked List:");

  /** ---
  insertLast(&head, 0);
  insertLast(&head, 10);
  insertLast(&head, 20);
  insertLast(&head, 30);
  insertLast(&head, 40);
  --- **/
  
  /** ---
  insertLast (&head, 10);
  insertLast (&head, 11);
  insertLast (&head, 12);
  insertLast (&head, 13);
  insertLast (&head, 14);
  insertLast (&head, 15);
  insertLast (&head, 16);
  
  display(head);

  deletepost(&head, 3);

  display(head);
  --- **/
  
  return 0;
}

/** ---

    void insert(struct Node **head, int data) {
    struct Node *newNode = (struct Node *) malloc (sizeof (struct Node));
    newNode->data = data;

    if(*head == NULL) {
    *head = newNode;
    (*head)->next = *head;
    exit(0);
    }

    struct Node *curr = *head;

    while(curr->next != *head) {
    curr = curr->next;
    }

    curr->next = newNode;
    newNode->next = *head;
    *head = newNode;
}

    
--- **/

/** ---

    void deletePos(struct Node **head, int n) {
  int size = calcSize (*head);

  if(n < 1 || size < n) {
  printf("Can't delete, %d is not a valid position\n", n);
  }

  else if(n == 1)
    deleteFront(head);

  else if(n == size)
    deleteEnd(head);

    else {
    struct Node *temp = *head;
    struct Node *previous;

    // traverse to the nth node 
    while(--n) {
    // store previous link node as we need to change its next val 
    previous = temp;
    temp = temp->next;
    }

    // change previous node's next node to nth node's next node
    previous->next = temp->next;
    // delete this nth node
    free(temp);
    }
}
    
--- **/



--- **/
