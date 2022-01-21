#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int elem;
  struct node *left, *right;
} node, *List;

void makeEmptyTree(List *h)
{
  *h = NULL;
}

void insertBST(List *h, int val)
{
  if (*h == NULL)
  {
    List tmp = calloc(1, sizeof(struct node));
    tmp->elem = val;
    tmp->left = tmp->right = NULL;
    *h = tmp;
  }
  else
  {
    (*h)->elem > val ? insertBST(&(*h)->left, val) : insertBST(&(*h)->right, val);
  }
}

void preOrder(List h)
{
  if (h != NULL)
  {
    preOrder(h->left);
    printf(" %d,", h->elem);
    preOrder(h->right);
  }
}
