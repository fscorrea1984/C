#include<stdio.h>
#include<stdlib.h>

struct Node {
  int data;
  struct Node *next;
  struct Node *prev;
};

int getLength (struct Node *node);

int isEmpty(struct Node *head) { return(head == NULL); }

void insert(struct Node **head, int data) {
  struct Node *freshNode = (struct Node *) malloc (sizeof (struct Node));

  freshNode->data = data;
  freshNode->next = *head;
  freshNode->prev = NULL;

  // If the linked list already had atleast 1 node
  if(!isEmpty(*head))
    (*head)->prev = freshNode;
  
  // freshNode will become head
  *head = freshNode;
}

void deleteFront(struct Node **head) {
  struct Node *tempNode = *head;

  // if DLL is empty
  if(isEmpty(*head)) {
    puts("Linked List Empty, nothing to delete");
    exit(0);
  }

  // if Linked List has only 1 node
  if(tempNode->next == NULL) {
    printf("%d deleted\n", tempNode->data);
    *head = NULL;
    exit(0);
  }

  // move head to next node
  *head = (*head)->next;
  // assign head node's previous to NULL
  (*head)->prev = NULL;

  printf("%d deleted\n", tempNode->data);
  free(tempNode);
}

void deleteEnd (struct Node **head)
{
  struct Node *tempNode = *head;

  // if DLL is empty
  if(isEmpty(*head)) {
    puts("Linked List Empty, nothing to delete");
    exit(0);
  }

  // if Linked List has only 1 node
  if(tempNode->next == NULL) {
    printf("%d deleted\n", tempNode->data);
    *head = NULL;
    exit(0);
  }

  // else traverse to the last node
  while(tempNode->next != NULL)
    tempNode = tempNode->next;

  struct Node *secondLast = tempNode->prev;

  // Curr assign 2nd last node's next to Null
  secondLast->next = NULL;

  printf("%d deleted\n", tempNode->data);
  free(tempNode);
}

void deleteNthNode(struct Node **head, int n) {
  //if the head node itself needs to be deleted
  int len = getLength(*head);

  // not valid
  if(n < 1 || n > len) {
    fputs("Position not valid", stderr);
    fputc('\n', stderr)
    exit(1);
  }

  // delete the first node
  if(n == 1) {
      deleteFront(head);
      exit(0);
    }

  if(n == len) {
    deleteEnd(head);
    exit(0);
  }

  struct Node *tempNode = *head;

  // traverse to the nth node
  while(--n) {
    tempNode = tempNode->next;
  }

  struct Node *previousNode = tempNode->prev;	// (n-1)th node
  struct Node *nextNode = tempNode->next;	// (n+1)th node

  // assigning (n-1)th node's next pointer to (n+1)th node
  previousNode->next = tempNode->next;

  // assigning (n+1)th node's previous pointer to (n-1)th node
  nextNode->prev = tempNode->prev;

  // deleting nth node
  printf ("%d deleted \n", tempNode->data);
  free(tempNode);
}

// required for deleteNthNode
int getLength(struct Node *node) {
  int len = 0;

  while(node != NULL) {
    node = node->next;
    len++;
  }

  return len;
}

//function to print the doubly linked list
void display(struct Node *node) {
  struct Node *end = NULL;

  //putchar('\n');
  fputs("List in Forward direction: ", stdout);
  
  while(node != NULL) {
    printf (" %d ", node->data);
    end = node;
    node = node->next;
  }

  putchar('\n');
  fputs("List in backward direction:", stdout);

  while(end != NULL) {
    printf(" %d ", end->data);
    end = end->prev;
  }
  
  printf ("\n\n");
}

int main(int argc, char **argv) {
  struct Node *head = NULL;

  insert(&head, 7);
  insert(&head, 8);
  insert(&head, 9);
  insert(&head, 10);
  insert(&head, 11);
  insert(&head, 12);

  display(head);

  deleteFront(&head);
  display(head);

  deleteEnd(&head);
  display(head);

  // delete 3rd node
  deleteNthNode(&head, 3);
  display(head);

  // delete 1st node
  deleteNthNode(&head, 1);
  display(head);

  // delete 1st node
  deleteEnd(&head);
  display(head);

  return 0;
}

/** ---

    List in Forward direction:  12  11  10  9  8  7 
    List in backward direction: 7  8  9  10  11  12 

    12 deleted
    List in Forward direction:  11  10  9  8  7 
    List in backward direction: 7  8  9  10  11 

    7 deleted
    List in Forward direction:  11  10  9  8 
    List in backward direction: 8  9  10  11 

    9 deleted 
    List in Forward direction:  11  10  8 
    List in backward direction: 8  10  11 

    11 deleted
    List in Forward direction:  10  8 
    List in backward direction: 8  10 

    8 deleted
    List in Forward direction:  10 
    List in backward direction: 10 
    
--- **/
