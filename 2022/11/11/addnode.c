node addNode(node head, int value) {
    node temp, p; // declare two nodes temp and p
    temp = createNode(); // assume createNode creates a new node with value = 0 and next pointing to NULL.
    temp->value = value; // add element to a value part of node
    if (head == NULL) {
        head = temp;     // when linked list is empty
    }
    else {
        p = head; // assign head to p 
        while (p->next != NULL) {
            p = p->next; // traverse the list until p is the last node. The last node always points to NULL.
        }
        p->next = temp; // Point the previous last node to the new node created.
    }
    return head;
}
