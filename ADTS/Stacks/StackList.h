#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int elem;
    struct node *next;
} *Stack;

void initStack(Stack *S) {
    *S = NULL;
}

void push(Stack *S, int data) {
    // assumed that top is the first element of the list
    Stack newNode = (Stack) calloc(1, sizeof(struct node));

    if (newNode != NULL) {
        newNode->elem = data;
        newNode->next = *S;
        *S = newNode;
    }
}

void pop(Stack *S) {
    if (*S != NULL) {
        Stack freeNode = *S;
        *S = freeNode->next;
        free(freeNode);
    }
}

void populateStack(Stack *S, int data[], int dataSize) {
    int x;

    for (x = 0; x < dataSize; x++) {
        push(S, data[x]);
    }
}

void displayStack(Stack *S) {
    while (*S != NULL) {
        printf(" %d ->", (*S)->elem);
        S = &(*S)->next;
    }
    printf("\n");
}