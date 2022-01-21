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

void print_RBT(RBT T);
void RB_insert_fixup(RBT *T, RBT *P, int elem);

RBT getParent(RBT N)
{
  return N->p;
}

RBT getGrandParent(RBT N)
{
  return getParent(getParent(N));
}

RBT getUncle(RBT N)
{
  RBT G = getGrandParent(N);
  RBT U = NULL;

  if (G != NULL)
  {
    RBT P = getParent(N);
    U = G->child[0] == P ? G->child[0] : G->child[1];
  }

  return U;
}

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

void RB_insert(RBT *T, RBT *P, int elem)
{
  if (*T == NULL)
  {
    *T = createNode(elem);
    (*T)->p = *P;
  }
  else if (elem < (*T)->key)
  {
    RB_insert(&(*T)->child[0], T, elem);
  }
  else if (elem >= (*T)->key)
  {
    RB_insert(&(*T)->child[1], T, elem);
  }

  if (*P != NULL)
  {
    RB_insert_fixup(T, &(*T)->p, elem);
  }
}

void RB_insert_fixup(RBT *T, RBT *P, int elem)
{
  if (getParent(*T) == NULL)
  {
    (*T)->color = BLACK;
  }
  else if (getUncle(*T) != NULL && getUncle(*T)->color == RED)
  {
    RBT G = getGrandParent(*T);
    RBT P = getParent(*T);
    RBT U = getUncle(*T);

    G->color = RED;
    P->color = BLACK;
    U->color = BLACK;
  }
}

int main()
{
  RBT R = NULL;

  RB_insert(&R, &R, 15);
  RB_insert(&R, &R, 14);
  RB_insert(&R, &R, 16);
  print_RBT(R);

  return 0;
}

void print_RBT(RBT T)
{
  if (T != NULL)
  {
    printf("(%d, c%d) -> ", T->key, T->color);
    print_RBT(T->child[0]);
    print_RBT(T->child[1]);
  }
}