#include <stdio.h>
#include <stdlib.h>

typedef enum t_color
{
  RED,
  BLACK
} COLOR;

typedef struct node
{
  struct node *p;
  struct node *child[2];
  int key;
  COLOR color;
} * RBT, nodetype;

typedef struct
{
  RBT root;
  COLOR color;
} RBTroot;

RBT createNode(int elem)
{
  RBT tmp = calloc(1, sizeof(nodetype));

  if (tmp != NULL)
  {
    tmp->color = RED;
    tmp->key = elem;
  }
  return tmp;
}

void RB_insert(RBT T, int elem)
{
  RBT y, x = T;

  while (x != NULL)
  {
    y = x;
    if (elem < x->key)
      x = x->child[0];
    else
      x = x->child[1];
  }
  RBT z = createNode(elem);
  z->p = y;

  if (y == NULL)
  {
    T.root = z;
  }
  else if (z->key < y->key)
  {
    y->child[0] = z;
  }
  else
    y->child[1] = z;
}

int main()
{
  RBT

      return 0;
}