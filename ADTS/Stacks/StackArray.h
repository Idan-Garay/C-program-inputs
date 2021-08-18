#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int *elems;
    int ctr;
} Stack;

void initStack(Stack *S) {
    S->elems = (int*) calloc(MAX, sizeof(int));

    S->ctr = (S->elems != NULL)? 0: -1;
}

void push(Stack *S, int data) {
    if (S->ctr < MAX) {
        S->elems[S->ctr++] = data;
    }
}

void pop(Stack *S) {
    if (S->ctr > 0) {
        S->ctr--;
    }
}

void populateStack(Stack *S, int data[], int dataSize) {
    int x;
    
    initStack(S);
    for (x = 0; x < dataSize; x++) {
        push(S, data[x]);
    }
}

void displayStack(Stack S) {
    printf("\n");
    while (S.ctr > 0) {
        printf(" %d ->", S.elems[--S.ctr]);
    }
}