#include <stdio.h>
#include <stdlib.h>

#define MAX 10


typedef struct node {
    int data;
    struct node *next;
} node, *ptr;

typedef ptr Dictionary[MAX];
typedef struct {
    int arr[MAX];
    int count;
}SET;

void initDict(Dictionary D) {
    int x;

    for (x = 0; x < MAX; x++) {
        D[x] = NULL;
    }
}

int hash(int val) {
    int catcher;

    for (catcher = 0; val != 0; val /= 10) {
        catcher = catcher + (val%10);
    }

    return catcher % 10;
}

void populateDictionary(Dictionary D, SET A) {
    int x, checksum;
    ptr *trav;

    for (x = 0; x < A.count; x++) {
        checksum = hash(A.arr[x]);

        for (trav = &(D[checksum]); *trav != NULL && A.arr[x] != (*trav)->data; trav = &(*trav)->next) {}
        if (*trav == NULL) {
            *trav = (ptr) calloc(1, sizeof(struct node));
            if (*trav != NULL) {
                (*trav)->data = A.arr[x];
            }
        }
    }
}

void displayDictionary(Dictionary D) {
    int x;
    ptr trav;

    for (x = 0; x < MAX; x++) {
        printf("\n");
        printf("[%d]:", x);
        for (trav = D[x]; trav != NULL; trav = trav->next) {
            printf(" %d ->", trav->data);
        }
    }
}
