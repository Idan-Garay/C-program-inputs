#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int elem;
    int next;
} node, Heap[MAX];

typedef struct {
    Heap H;
    int avail;
}VHeap;

typedef int Stack; 

void initCursorStack(VHeap *VH, Stack *S) {
    int x;

    for (x = MAX-1; x >= 0; x--) {
        VH->H[x].next = x-1;
    }
    VH->avail = MAX-1;
    *S = -1;
}

void push(VHeap *VH, Stack *S, int data) {
    int memSpace = VH->avail;

    if (memSpace != -1) {
        VH->avail = VH->H[memSpace].next;
        VH->H[memSpace].elem = data;
        VH->H[memSpace].next = *S;
        *S = memSpace;
    }
}

void pop(VHeap *VH, Stack *S) {
    if (*S != -1) {
        int tmp;

        // tmp = VH->H[*S].next;
        // VH->H[*S].next = VH->avail;
        // VH->avail = *S;
        tmp = *S;
        *S = VH->H[tmp].next;
        VH->H[tmp].next = VH->avail;
        VH->avail = tmp;
    }
} 

void populateCursorStack(VHeap *VH, Stack *S, int data[], int dataSize) {
    int x;
    
    for (x = 0; x < dataSize; x++) {
        push(VH, S, data[x]);
    }
}

void displayCursorStack(VHeap VH, Stack S) {
    while (S != -1) {
        printf("[%d]: %d - %d\n", S, VH.H[S].elem, VH.H[S].next);
        S = VH.H[S].next;
    }
    printf("\n");
}