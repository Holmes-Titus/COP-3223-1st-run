#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
        int          data;
        struct Node *next;
} Node;

//function to create a new node
Node *node_create(int data) {
    Node *n = malloc(sizeof(Node));
    if (n == NULL) {
        perror("malloc");
        return NULL;
    }
    n->data = data;
    /* Terminate the chain */
    n->next = NULL;
    return n;
}

//function to add a new node of given data to the front of the linked list
//because it is only 2 pointer assignments it is always O(1)
Node *prepend(Node *head, int data){
    Node *n = node_create(data);
    if (n == NULL) return head;
    /* New node points to old head */
    n->next = head;
    /* New node IS the new head */
    return n;
}

//this function adds a node to the end of the linked list, O(N) in time as it needs to iterate through the linked list
Node *append(Node *head, int data){
    Node *n = node_create(data);
    if (n == NULL) return head;
    if (head == NULL) return n; /* was empty */
    /* Walk to last node */
    Node *cur = head;
    while (cur->next != NULL){
        cur = cur->next;}
    cur->next = n;
    return head;
}

//traverse through the linked list and print the values
void list_print(Node *head) {
    Node *cur = head;
    while (cur != NULL) {
        printf("%d", cur->data);
        if (cur->next != NULL)  printf(" -> ");
        cur = cur->next;
    }
    printf(" -> NULL\n");
}

void list_free(Node *head) {
    Node *cur = head;
    Node *next_node;
    while (cur != NULL) {
        /* Save next BEFORE free */
        next_node = cur->next;
        free(cur);
        cur = next_node;
    }
}

int main(void){

    //Big O notations (the preformance of algorithms)
    //as input size N grows, how does the number of operations grow
    /*
    
    Ex: averaging the number of inputs is N
    We want to find the shape of the curve, or how O changes as N -> infinity
    O(1) is the fastest possible time. Time is independent on N
    Ex of O(1): check if even, accessing an array element, inseting a node to the head of a linked list
    O() consideres the worst possible scenario
    Ex: attempting to find index by searching through all values is O(N)
    Ex: attempting to find index of a sorted array by using BNS is O(log(N)) (log is base 2)
    O(N) is when each input requires an independent use
    O(N^2) time grows exponentially with N; Often due to nested loops and dangerous for large data sets
    We only care about the shape, so drop constants O(N) = O(2N)
    Drop smaller terms, so O(N^2+N) = O(N^2)
    Inserting in the front of arrays is O(N), while inserting to the front of linked lists is O(1)
    Knowing O helps us choose the right tool for the job
    */
   

    //Linked Lists
    //fixed the problem of arrays being very rigid, at the cost of sequential access
    //a linked list is a chain of nodes, where each node holds the value stored and a pointer ot the next node
    /*
    
    [data|next]
    node example

    no contigous block of memory

    

    data | 4 bytes
    next | 8 bytes (pointer)

    sizeof(Node) == 12 or 16 (platform-dependent alignment)

    
    
    */


    //first node you want is the head pointer

    Node *head = NULL;

    Node *n = node_create(10);

    head = n;

    //n is now the head of the linked list, of value [10|NULL]

    //the head pointer is th only way into the list, lose it and the list is leaked
    //thus never advance the head during traversal or the entire linked list will be leaked

    //Prepend (adding to the front of the list)


    head = prepend(head, 20);
    head = prepend(head, 30);
    head = prepend(head, 40);
    head = prepend(head, 50);
    head = prepend(head, 60);
    head = prepend(head, 70);
    head = prepend(head, 80);
    head = prepend(head, 90);
    head = prepend(head, 100);

    list_print(head);
    list_free(head);



return 1;
}