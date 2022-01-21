#include <stdio.h>
#include <stdlib.h>

typedef enum COLOR
{
  BLACK,
  RED
} color_t;

typedef struct node
{
  int key;
  struct node *parent;
  struct node *left, *right;
  color_t color;
} * RBT, RBNode;

typedef struct
{
  RBT root;
  color_t color;
} RBTree;

RBT createNode(int elem)
{
  RBT newNode = (RBT)calloc(1, sizeof(RBNode));

  if (newNode != NULL)
  {
    newNode->key = elem;
    newNode->left = newNode->right = newNode->parent = NULL;
    newNode->color = RED;
  }
  return newNode;
}

void leftRotate(RBT *T)
{
  RBT x = *T;
  RBT y = x->right;

  x->right = y->left;
  if (y->left != NULL)
    y->left->parent = x;
  y->parent = x->parent;
  if (x->parent == NULL)
    *T = y;
  else if (x->parent->left == x)
    x->parent->left = y;
  else
    x->parent->right = y;
  y->right = x;
  x->parent = y;
}

void rightRotate(RBT *T)
{
  RBT x = *T;
  RBT y = x->left;

  x->left = y->right;
  if (y->right != NULL)
    y->right->parent = x;
  y->parent = x->parent;
  if (x->parent == NULL)
    *T = y;
  else if (x->parent->right == x)
    x->parent->right = y;
  else
    x->parent->left = y;
  y->left = x;
  x->parent = y;
}

RBT getParent(RBT node)
{
  return node == NULL ? NULL : node->parent;
}

RBT getGrandParent(RBT node)
{
  return getParent(getParent(node));
}

RBT getUncle(RBT node)
{
  RBT G = getGrandParent(node);
  RBT P = getParent(node);
  RBT U;

  if (G != NULL)
  {
    U = G->left == P ? G->right : G->left;
  }
  return U;
}

void RB_insert_fixup(RBT z)
{
  RBT U, P, G;

  P = getParent(z);
  while (P != NULL && P->color == RED)
  {
    G = getGrandParent(z);
    if (G != NULL && G->left == P)
    {
      U = G->right;
      if (U != NULL && U->color == RED)
      {
        P->color = BLACK;
        U->color = BLACK;
        G->color = RED;
        z = G;
      }
      else if (P != NULL && P->right == z)
      {
        z = P;
        leftRotate(&z); // different
      }
      P->color = BLACK;
      G->color = RED;
    }
    else
    {
      if (U != NULL && U->color == RED)
      {
        P->color = BLACK;
        U->color = BLACK;
        G->color = RED;
        z = G;
      }
      else if (P != NULL && P->left == z)
      {
        z = P;
        rightRotate(&z); // different
      }
      P->color = BLACK;
      G->color = RED;
    }
  }
}

void RBT_insert(RBTree *T, int elem)
{
  RBT x, y;

  y = NULL;
  x = T->root;
  while (x != NULL)
  {
    y = x;
    x = (elem < x->key) ? x->left : x->right;
  }

  RBT z = createNode(elem);
  z->parent = y;
  if (y == NULL)
    T->root = z;
  else if (z->key < x->key)
    x->left = z;
  else
    x->right = z;

  // RB_insert_fixup(z);
}

void preOrder(RBT T);
int main()
{
  RBTree rbt = {NULL, BLACK};

  RBT_insert(&rbt, 11);
  RBT_insert(&rbt, 2);
  // RBT_insert(&rbt, 14);
  preOrder(rbt.root);

  return 0;
}

void preOrder(RBT T)
{
  if (T != NULL)
  {
    printf("%d -> ", T->key);
  }
}