#include <stdio.h>
#include <stdlib.h>
#include "AVL2.h"
// BST remove, insert,

int main()
{
  BST B = NULL;
  // int A[] = {23, 15, 52, 21, 2};
  int A[] = {30, 11, 19, 20, 32, 40, 45};
  int size = 7;

  int x;

  for (x = 0; x < size; x++)
  {
    insert(&B, A[x]);
    printf("\n");
    preOrder(B);
  }
  // preOrder(B);
  // printf("\n");
  // delete (&B, 30);
  // delete (&B, 11);
  // preOrder(B);
  // printf("\n");

  return 0;
}