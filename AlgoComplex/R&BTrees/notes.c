#include <stdio.h>
#include <stdlib.h>

typedef enum
{
  Red,
  Black
} colors;

typedef struct link
{
  struct link *p, *left, *right;
  colors color;
  int key;
} node, *ptr;

typedef struct
{
  ptr root;
  ptr NIL;
} RBT;

void initRBT(RBT *T)
{
  T->root = (ptr)calloc(1, sizeof(node));
  T->NIL = NULL;
  if (T->root != NULL)
  {
    T->NIL = T->root;
  }
  T->root->key = 0;
  T->root->color = Black;
}

void leftRotate(RBT *T, ptr z)
{
  ptr y = z->right;
  z->right = y->left;

  if (y->right != T->NIL) // possible node to be redirected
  {
    y->right->p = z;
  }
  y->p = z->p;
  if (z->p == T->NIL) // root
  {
    T->root = y;
  }
  else if (z == z->p->left)
  {
    z->p->right = y;
  }
  else
  {
    z->p->left = y;
  }
  y->left = z;
  z->p = y;
}

void rightRotate(RBT *T, ptr z)
{
  ptr y = z->left;
  z->left = y->right;

  if (y->right != NULL)
  {
    y->right->p = z;
  }
  y->p = z->p;

  if (z->p == T->NIL)
  {
    T->root = z;
  }
  else if (z == z->p->left)
  {
    z->p->left = y;
  }
  else
  {
    z->p->right = y;
  }
  y->right = z;
  z->p = y;
}

void insertFixup(RBT *T, ptr z)
{
  ptr U;
  while (z->p->color == Red)
  { // 1. check childType of parent
    if (z->p == z->p->p->left)
    {
      U = z->p->p->right;
      if (U->color == Red) // case 1
      {
        U->color = Black;
        z->p->color = Black;
        z->p->p->color = Red;
        z = z->p->p;
      }
      else
      {
        // case 2 innerChild
        if (z == z->p->right)
        {
          z = z->p;
          leftRotate(T, z);
        }
        z->p->color = Black; // case 3 outerChild
        z->p->p->color = Red;
        rightRotate(T, z->p->p);
      }
    }
    else
    {
      U = z->p->p->left;
      if (U->color == Red)
      {
        U->color = Black;
        z->p->color = Black;
        z->p->p->color = Red;
        z->p->p->color = Red;
        z = z->p->p;
      }
      else
      {
        if (z == z->p->left)
        {
          z = z->p;
          rightRotate(T, z);
        }
        z->p->color = Black;
        z->p->p->color = Red;
        leftRotate(T, z->p->p);
      }
    }
  }
  T->root->color = Black;
}

void insert(RBT *T, ptr new)
{
  ptr y = T->NIL;
  ptr x = T->root;

  while (x != T->NIL)
  {
    y = x;
    x = (x->key > new->key) ? x->left : x->right;
  }

  new->p = y;

  if (y == T->NIL) // root
  {
    T->root = new;
  }
  else if (y->key <= new->key) // left, right
  {
    y->right = new;
  }
  else
  {
    y->left = new;
  }
  new->left = T->NIL;
  new->right = T->NIL;
  insertFixup(T, new);
}

ptr createNode(int key)
{
  ptr tmp = (ptr)calloc(1, sizeof(node));
  if (tmp != NULL)
  {
    tmp->key = key;
    tmp->color = Red;
    tmp->p = NULL;

    tmp->left = NULL;
    tmp->right = NULL;
  }
  return tmp;
}

void preOrder(ptr N);

int main()
{
  RBT T;

  initRBT(&T);
  insert(&T, createNode(7));
  // insert(&T, createNode(4));
  // insert(&T, createNode(11));
  preOrder(T.root);

  return 0;
}

void preOrder(ptr N)
{
  if (N != NULL)
  {
    printf("%d,%d,p:%d -> ", N->key, N->color, N->p != NULL ? N->p->key : 0);
    preOrder(N->left);
    preOrder(N->right);
  }
}