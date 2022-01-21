#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int key;
  struct node *left, *right;
  int height;
} * BST, node;

BST createNode(int elem)
{
  BST tmp = (BST)calloc(1, sizeof(node));
  if (tmp != NULL)
  {
    tmp->key = elem;
  }
  return tmp;
}

int getHeight(BST T)
{
  return T == NULL ? -1 : T->height;
}

int getBiggerHeight(BST T)
{
  int larger = -1;
  if (T != NULL)
  {
    BST left = T->left;
    BST right = T->right;

    if (left != NULL && left->height > larger)
      larger = left->height;
    else if (right != NULL && right->height > larger)
      larger = right->height;
  }
  return larger;
}

void rightRotate(BST *T)
{
  BST X, Y;

  X = *T;
  Y = X->left;
  X->left = Y->right;
  Y->right = X;
  *T = Y;
  X->height = getBiggerHeight(X) + 1;
  Y->height = getBiggerHeight(Y) + 1;
}

void leftRotate(BST *T)
{
  BST X = *T;
  BST Y = X->right;
  X->right = Y->left;
  Y->left = X;
  *T = Y;
  X->height = getBiggerHeight(X) + 1;
  Y->height = getBiggerHeight(Y) + 1;
}

void insert(BST *T, int elem)
{
  if (*T == NULL)
  {
    *T = createNode(elem);
  }
  else if (*T != NULL)
  {
    elem < (*T)->key ? insert(&(*T)->left, elem) : insert(&(*T)->right, elem);
  }

  (*T)->height = getBiggerHeight(*T) + 1;
  int BF = getHeight((*T)->left) - getHeight((*T)->right);

  if (BF > 1)
  {
    if (elem > (*T)->left->key)
      leftRotate(&(*T)->left);
    rightRotate(T);
  }
  if (BF < -1)
  {
    if (elem < (*T)->right->key)
      rightRotate(&(*T)->right);
    leftRotate(T);
  }
}

void preOrder(BST A)
{
  if (A != NULL)
  {
    printf("%d: %d, ", A->key, A->height);
    preOrder(A->left);
    preOrder(A->right);
  }
}