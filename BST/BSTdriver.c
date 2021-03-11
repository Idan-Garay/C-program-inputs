#include "BST.h"
#include <stdio.h>
#include <stdlib.h>

BST populateBST (int arr[], int size) {
    BST tree;

    tree = (BST) malloc(sizeof(ctype));
    if (tree != NULL) {
        int x = 0;
        initializeBST(&tree);

        while(x < size){
            insertElem(&tree, arr[x]);
            x++;
        }
    }
    return tree;
}

void deleteTestCases(BST *tree, int arr[], int size) {
    int x;

    for (x = 0; x < size; x++) {
        deleteElem(tree, arr[x]);
    }
}

void makeEmptyBST(BST *tree) {
    while (*tree != NULL) {
        ((*tree)->LC == NULL)? deleteMax(tree): deleteMin(tree);
    }
}

int binarySearch(int arr[], int length, int elem) {
    int front, rear, y;

    rear = length - 1;
    front = 0;
    for (y = rear/2; arr[y] != elem && front < rear; y = (front+rear)/2) {
        if (elem < arr[y])
            rear = y-1;
        else 
            front = y+1;
    }

    return (arr[y] == elem)? arr[y]: -1;
}

int main () {
    BST tree;
    int arr[12] = {10,8,9,6,3,7,16,13,11,12,20,25};
    int deleteArr[] = {6, 25, 13, 12};

    /* a. */
    initializeBST(&tree);
    tree = populateBST(arr, 12);
    preorder(tree);
    printf("\n");

    /* b. */
    printf("Is %d a member: %d\n", 99, isMember(tree, 99));
    printf("Is %d a member: %d\n", arr[5], isMember(tree, arr[5]));

    /* c. */
    deleteTestCases(&tree, deleteArr, 4);
    preorder(tree);
    printf("\n");

    /* d. */
    makeEmptyBST(&tree);
    preorder(tree);

    return 0;
}