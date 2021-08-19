#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *LC, *RC;
}node, *BST;

void initBST(BST *B) {
    *B = NULL;
}

void insert(BST *B, int data) {
    BST *trav = B, tmp;

    while(*trav != NULL) {
        trav = (*trav)->data > data ? &(*trav)->LC : &(*trav)->RC;
    }

    if (*trav == NULL) {
        *trav = (BST) calloc(1, sizeof(node));
        (*trav)->data = data;
        (*trav)->LC = (*trav)->RC = NULL;
    }
}

void removal(BST *B, int data) {
    BST *trav = B;

    while (*trav != NULL && (*trav)->data != data) {
        trav = (*trav)->data > data? &(*trav)->LC : &(*trav)->RC ;
    }

    if (*trav != NULL) {
        BST freeNode = *trav;
        if ((*trav)->LC != NULL && (*trav)->RC != NULL) {
            BST *successor = &(*trav)->RC;

            while ((*successor)->LC != NULL) {
                successor = &(*successor)->LC;
            }
            (*successor)->LC = freeNode->LC;
            *trav = *successor;
            *successor = (*successor)->RC;
            (*trav)->RC = freeNode->RC;
        } else {
            *trav = ((*trav)->LC == NULL)? freeNode->RC: freeNode->LC;
        }

        free(freeNode);
    }
}

void populateBST(BST *B, int data[], int dataSize) {
    int x;

    for (x = 0; x < dataSize; x++) {
        insert(B, data[x]);
    }
}

void preOrder(BST B) {
    if (B != NULL) {
        printf(" %d ->", B->data);
        preOrder(B->LC);
        preOrder(B->RC);
    }
}

void inOrder(BST B) {
    if (B != NULL) {
        inOrder(B->LC);
        printf(" %d ->", B->data);
        inOrder(B->RC);
    }
}

void postOrder(BST B) {
    if (B != NULL) {
        postOrder(B->LC);
        postOrder(B->RC);
        printf(" %d ->", B->data);
    }
}

int member2(BST B, int data) {
	while (B != NULL && B->data != data) {
		B = (B->data < data)? B->RC : B->LC;
	}

	return (B != NULL)? 1 : 0;
}

int member(BST B, int data){
	if (B == NULL) {
		return 0;
	} else if (B->data == data) {
		return 1;
	} else if (B->data < data) {
		return member(B->RC, data);
	} else {
		return member(B->LC, data);
	}
}