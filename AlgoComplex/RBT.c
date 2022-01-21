#include <stdio.h>

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

void insertFixup(RBT *T, ptr z)
{
  ptr U;

  while (z->p->color == RED)
  {
    // determine type of child
    if (z->p == z->p->p->left)
    {
      U = z->p->p->right;
      if (U != NULL && U->color == RED)
      { // U is red
        U->color = Black;
        z->p->color = Black;
        z->p->p->color = Red;
        z = z->p->p;
      }
      else
      {
        if (z == z->p->right)
        {
          z = z->p;
          leftRotate(T, z);
        }
        z->p->color = Black;
        z->p->p->color = Red;
        rightRotate(T, z->p->p);
      }
    }
  }
}

void insert(RBT *T, ptr new)
{
  ptr x = T->root;
  ptr y = T->NIL

          while (x != NULL)
  {
    y = x;
    x = (new->elem < x->key) ? x->left : x->right;
  }

  new->p = y;
  if (y == T->NIL)
    T->root = y;
  else if (new->elem < y->key)
    y->left = new;
  else
    y->right = new;
  insertFixup(T, new);
}