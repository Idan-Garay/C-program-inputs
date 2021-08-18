#include <stdio.h>

#define MAX 100

typedef struct {
    int elem;
    int next;
} node, Heap[100];

typedef struct {
    Heap H;
    int avail;
} VHeap;

typedef struct {
    int front, back;
} Queue;

void initCursorQueue(VHeap *VH, Queue *Q) {
    int x;

    for (x = MAX-1; x >= 0; x--) {
        VH->H[x].next = x-1;
    }
    VH->avail = MAX-1;
    Q->front = Q->back = -1;
}

void enqueue(VHeap *VH, Queue *Q, int data) {
    int memSpace = VH->avail;

    if (memSpace != -1) {
        VH->avail = VH->H[memSpace].next;
        VH->H[memSpace].elem = data;
        VH->H[memSpace].next = -1;
        
        if (Q->back != -1) 
            VH->H[Q->back].next = memSpace;

        Q->back = memSpace;

        if (Q->front == -1) {
            Q->front = Q->back;
        }
    }
}


void dequeue(VHeap *VH, Queue *Q) {
    if (Q->front != -1) {
        int node = Q->front;

        Q->front = VH->H[node].next;
        VH->H[node].next = VH->avail;
        VH->avail = node;
    }
}

void populateCursorQueue(VHeap *VH, Queue *Q, int data[], int dataSize) {
    int x;

    for (x = 0; x < dataSize; x++) {
        enqueue(VH, Q, data[x]);
    }
}

void displayCursorQueue(VHeap VH, Queue Q) {
    while (Q.front != -1) {
        printf("%d - %d \n", VH.H[Q.front].elem, VH.H[Q.front].next);
        dequeue(&VH, &Q);
    }
    printf("\n");
}