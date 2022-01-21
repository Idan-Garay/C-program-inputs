#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int key;
  struct node *left, *right;
  int height;
} node, *BST;

void preOrder(BST B);
void inOrder(BST B);
int biggerHeight(BST left, BST right)
{
  int val;
  if (left == NULL && right == NULL)
    val = -1;
  else if (right == NULL)
    val = left->height;
  else if (left == NULL)
    val = right->height;
  else
    val = left->height < right->height ? right->height : left->height;
  return val;
}

int getHeight(BST B)
{
  return B == NULL ? -1 : B->height;
}

void rightRotate(BST *B)
{
  BST x = *B;
  BST y = x->left;
  x->left = y->right;
  y->right = x;
  *B = y;
  x->height = biggerHeight((*B)->left, (*B)->right) + 1;
}

void leftRotate(BST *B)
{
  BST x = *B;
  BST y = x->right;
  x->right = y->left;
  y->left = x;
  *B = y;
  y->height = biggerHeight((*B)->left, (*B)->right) + 1;
}

void insert(BST *B, int elem)
{
  int balance;
  if (*B != NULL)
  {
    elem < (*B)->key ? insert(&(*B)->left, elem) : insert(&(*B)->right, elem);
  }
  else if (*B == NULL)
  {
    *B = calloc(1, sizeof(struct node));
    (*B)->height = -1;
    (*B)->key = elem;
  }

  (*B)->height = biggerHeight((*B)->left, (*B)->right) + 1;
  balance = getHeight((*B)->left) - getHeight((*B)->right);

  if (balance > 1)
  {
    if ((*B)->left->key < elem)
      leftRotate(&(*B)->left);
    rightRotate(B);
  }
  else if (balance < -1)
  {
    if ((*B)->right->key > elem)
      rightRotate(&(*B)->right);
    leftRotate(B);
  }
}

void delete (BST *B, int elem)
{
  int balance;

  if (*B != NULL)
  {
    if (elem < (*B)->key)
      delete (&(*B)->left, elem);
    else if (elem > (*B)->key)
      delete (&(*B)->right, elem);
    else if (elem == (*B)->key)
    {
      BST delNode = *B;
      if ((*B)->left == NULL && (*B)->right == NULL)
        *B = NULL;
      else if ((*B)->left == NULL)
        *B = (*B)->right;
      else if ((*B)->right == NULL)
        *B = (*B)->left;
      else
      {
        BST *trav = &(*B)->right;
        while ((*trav)->left != NULL)
          trav = &(*trav)->left;
        delNode->key = (*trav)->key;
        delNode = *trav;
        *trav = (*trav)->right;
      }
      free(delNode);
    }
  }
  if (*B != NULL)
  {
    (*B)->height = biggerHeight((*B)->left, (*B)->right) + 1;
    balance = getHeight((*B)->left) - getHeight((*B)->right);

    if (balance > 1)
    {
      if ((*B)->left->key < elem)
        leftRotate(&(*B)->left);
      rightRotate(B);
    }
    else if (balance < -1)
    {
      if ((*B)->right->key > elem)
        rightRotate(&(*B)->right);
      leftRotate(B);
    }
  }
}

void preOrder(BST B)
{
  if (B != NULL)
  {
    printf(" %d,", B->key);
    preOrder(B->left);
    preOrder(B->right);
  }
}

void inOrder(BST B)
{
  if (B != NULL)
  {
    inOrder(B->left);
    printf(" %d,", B->key);
    inOrder(B->right);
  }
}