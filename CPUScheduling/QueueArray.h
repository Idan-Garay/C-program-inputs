#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int elems[100];
    int front, back;
} Queue;

void initQueue(Queue *Q) {

    Q->front = 0;
    Q->back = Q->front-1;
}

void enqueue(Queue *Q, int data) {
    if (Q->front != (Q->back+2) % MAX) {
        Q->back = (Q->back+1) %MAX;
        Q->elems[Q->back] = data;
    }
}

void dequeue(Queue *Q) {
    if (Q->front != (Q->back+1) % MAX) {
        Q->front = (Q->front+1)%MAX;
    }
}

void displayQueue(Queue Q) {
    while (Q.front != (Q.back+1) % MAX) {
        printf(" %d ->", Q.elems[Q.front]);
        dequeue(&Q);
    }
}

int isFull(Queue Q) {
    return (Q.front == (Q.back+2) % MAX)? 1: 0;
}

void populateQueue(Queue *Q, int data[], int dataSize) {
    int x;

    for (x = 0; x < dataSize; x++) {
        if (!isFull(*Q)) {
            enqueue(Q, data[x]);
        }
    }
}