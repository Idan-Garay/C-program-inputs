#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int elem;
    struct node* next;
}node, *nodePtr;

typedef struct queue {
    nodePtr head, tail;

} Queue;

void initQueue(Queue *Q) {
    Q->head = Q->tail = NULL;
}

void enqueue(Queue *Q, int data) {
    nodePtr newNode = (nodePtr) calloc(1, sizeof(struct node));

    if (newNode != NULL) {
        if (Q->head != NULL) {
            Q->tail->next = newNode;
        }
        newNode->elem = data;
        newNode->next = NULL;
        Q->tail = newNode;

        if (Q->head == NULL) {
            Q->head = Q->tail;
        }
    }
}

void dequeue(Queue *Q) {
    if (Q->head != NULL) {
        nodePtr freeNode = Q->head;
        Q->head = freeNode->next;
        free(freeNode);
    }
}

void populateQueue(Queue *Q, int data[], int dataSize) {
    int x;

    for (x = 0; x < dataSize; x++) {
        enqueue(Q, data[x]);
    }
}

void displayQueue(Queue Q) {
    nodePtr trav;

    printf("\n");
    for (trav = Q.head; trav != NULL; trav = trav->next) {
        printf(" %d ->", trav->elem);
    }
}