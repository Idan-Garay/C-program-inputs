#include <stdio.h>
#include <stdlib.h>

typedef int elemType;

typedef struct node {
    elemType elem;
    struct node* LC;
    struct node* RC;
}*BST, ctype, nodetype;

void initializeBST(BST *tree) {
    *tree = NULL;
}

int isMember(BST tree, int X) {
    while (tree != NULL && X != tree->elem)
        tree = (X < tree->elem)? tree->LC: tree->RC;
    return (tree != NULL)? 1: 0;
}

void insertElem(BST *tree, elemType X) {
    if (*tree == NULL) {
        *tree = (BST) malloc(sizeof(ctype));
        if (*tree != NULL) {
            (*tree)->LC = (*tree)->RC = NULL;
            (*tree)->elem = X;
        }
    } else if ((*tree)->elem != X) {
        (X < (*tree)->elem)? insertElem(&(*tree)->LC, X): insertElem(&(*tree)->RC, X);
    }
}
void deleteElem(BST *tree, elemType X) {
    if (*tree != NULL) {
        if ((*tree)->elem != X) {
            (X < (*tree)->elem)? deleteElem(&(*tree)->LC, X): deleteElem(&(*tree)->RC, X);
        }else {
            BST delNode = *tree;
            if ((*tree)->LC == NULL && (*tree)->RC == NULL) {
                *tree = NULL;
            } else if ((*tree)->RC == NULL) {
                *tree = (*tree)->LC;
            } else if ((*tree)->LC == NULL) {
                *tree = (*tree)->RC;
            } else {
                BST *nodePtr = &(*tree)->LC;

                while ((*nodePtr)->RC != NULL)
                    nodePtr = &(*nodePtr)->RC;
                (*tree)->elem = (*nodePtr)->elem;
                delNode = *nodePtr;
                *nodePtr = (*nodePtr)->LC;
            } 
            free(delNode);
        }
    } 
}

int deleteMin(BST *tree) {
    int retVal = -1;
    if (*tree != NULL) {
        if ((*tree)->LC != NULL)
            retVal = deleteMin(&(*tree)->LC);
        else {
            BST delNode;

            delNode = *tree;
            *tree = delNode->RC;
            retVal = delNode->elem;
            free (delNode);
        }
    }
    return retVal;
}

int deleteMax(BST *tree) {
    int retVal = -1;
    
    if (*tree != NULL) {
        if ((*tree)->RC != NULL) 
            retVal = deleteMax(&(*tree)->RC);
        else {
            BST delNode;

            delNode = *tree;
            *tree = delNode->LC;
            retVal = delNode->elem;
            free(delNode);
        }
    }
    return retVal;
}

void preorder(BST tree) {
    if (tree != NULL) {
        printf("%d ", tree->elem);
        preorder(tree->LC);
        preorder(tree->RC);
    }
}

void inorder(BST tree) {
    if (tree != NULL) {
        preorder(tree->LC);
        printf("%d ", tree->elem);
        preorder(tree->RC);
    }
}

void postorder(BST tree) {
    if (tree != NULL) {
        postorder(tree->LC);
        postorder(tree->RC);
        printf("%d ", tree->elem);
    }
}







