#include <stdio.h>
#include <stdlib.h>
typedef enum
{
  FALSE,
  TRUE
} boolean;

#define M 3
typedef struct
{
  int num[M];
  int ctr;
  struct node *child[M + 1];
} * ptr, nodetype;

void insert(ptr *n, ptr *p, int num)
{
  int i;
  if (*n != NULL)
  {
    if ((*n)->child[0] == NULL)
    {
      for (i = (*n)->ctr - 1; i >= 0 && (*n)->num[i] > num; i--)
      {
        (*n)->num[i + 1] = (*n)->num[i];
      }
      (*n)->num[i + 1] = num;
      (*n)->ctr++;
    }
    else
    {
      for (i = 0; i < (*n)->ctr && (*n)->num[i] < num; i++)
      {
      }
      insert(&(*n)->child[i], n, num);
    }
  }
  else
  {
    ptr newNode = calloc(1, sizeof(nodetype));
    if (newNode != NULL)
    {
      newNode->num[0] = num;
      ++newNode->ctr;
      *n = newNode;
    }
  }
  if ((*n)->ctr == M)
  {
    split(n, p);
  }
}

void split(ptr *A, ptr *P)
{
  ptr N, R, trav;
  int x, y, newSize;

  N = calloc(1, sizeof(nodetype));
  newSize = (*A)->ctr / 2;

  for (y = 0, y = newSize + 1; x <= (*A)->ctr; x++, y++)
  {
    if (x <= (*A)->ctr)
      N->num[y] = (*A)->num[x];
    N->child[y] = (*A)->child[x];
    (*A)->child[x] == NULL;
  }

  (*A)->ctr = newSize;
  N->ctr = y - 1;

  if (*P == NULL)
  {
    R = calloc(1, sizeof(nodetype));
    R->num[0] = (*A)->num[newSize];
    R->child[0] = *A;
    R->child[1] = N;
    R->ctr++;
    *A = R;
  }
  else
  {
    for (x = 0; (*P)->child[x] != *A; x++)
    {
    }

    (*P)->ctr++;
    for (y = (*P)->ctr; y > x; y--)
    {
      (*P)->child[y] = (*P)->child[y - 1];
      if (y - 1 > x)
        (*P)->num[y - 1] = (*P)->num[y - 2];
    }
    (*P)->num[x] = (*A)->data[newSize];
    (*P)->child[x + 1] = N;
  }
}