#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} *SET;

void sortSetList(SET *A);
void displayList(SET A);
//Linked List

SET unionList(SET *A, SET *B) {
    SET C = (SET) calloc(1, sizeof(SET));
    SET trav, trav2;

    if (*A != NULL || *B != NULL) {
        sortSetList(A);
        displayList(*A);
        sortSetList(B);
        displayList(*B);
        SET *ptr = &C;
        trav = *A;
        trav2 = *B;

        while (trav != NULL && trav2 != NULL) {
            if (trav->data < trav2->data) {
                *ptr = (SET) calloc(1, sizeof(struct node));

                if (*ptr != NULL) {
                    (*ptr)->data = trav->data;
                    (*ptr)->next = NULL;
                    ptr = &(*ptr)->next;
                }
                trav = trav->next;
            } else {
                if (trav->data == trav2->data) {
                    trav = trav->next;
                }

                *ptr = (SET) calloc(1, sizeof(struct node));
                if (*ptr != NULL) {
                    (*ptr)->data = trav2->data;
                    (*ptr)->next = NULL;
                    ptr = &(*ptr)->next;
                }
                trav2 = trav2->next;
            }
        }

        if (trav2 != NULL) {
            trav = trav2;
        }

        while (trav != NULL) {
            *ptr = (SET) calloc(1, sizeof(struct node));
            
            if (*ptr != NULL) {
                (*ptr)->data = trav->data;
                (*ptr)->next = NULL;
                ptr = &(*ptr)->next;
            }

            trav = trav->next;
        }
    }
    return C;
}

void displayList(SET A) {

    while (A != NULL) {
        printf(" %d ->", A->data);
        A = A->next;
    }
    printf("\n");
}

void populateSetList(SET *A, int data[], int dataSize) {
    int x;

    if (*A == NULL) {
        for (x = 0; x < dataSize; x++) {
            *A = (SET) calloc(1, sizeof(struct node));
            if (*A != NULL) {
                (*A)->data = data[x];
                (*A)->next = NULL;
                A = &(*A)->next;
            }
        }
    } else {
        printf("Set is not empty. \n");
    }
}

void sortSetList(SET *A) {
    if (*A != NULL) {
        SET nodeHolder, *trav, *trav2, *smallest;
        for (trav = A; *trav != NULL; trav = &(*trav)->next ) {
            smallest = trav;
            for (trav2 = &(*trav)->next; *trav2 != NULL; trav2 = &(*trav2)->next) {
                if ((*smallest)->data > (*trav2)->data) {
                    smallest = trav2;
                }
            }
            nodeHolder = *smallest;
            *smallest = nodeHolder->next;
            nodeHolder->next = *trav;
            *trav = nodeHolder;
        }
    }
}