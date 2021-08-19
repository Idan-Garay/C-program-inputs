#include "BSTPointer.h"

int main() {

    BST tree; 
    int data[] = {10,5,15,3,8,12,20};
    initBST(&tree);

    populateBST(&tree, data, 7);
    preOrder(tree);
    printf("\n");
    
    insert(&tree, 6);
    preOrder(tree);
    printf("\n");

    removal(&tree, 5);
    preOrder(tree);

    return 0;
}