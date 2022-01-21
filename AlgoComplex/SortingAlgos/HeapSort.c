#include <stdio.h>
#include "arrayUtil.h"
#define SIZE 10

typedef struct
{
  int elem[SIZE];
  int lastNdx;
} Heap;
void displayHeap(Heap A);

void insert(Heap *A, int val)
{
  if (A->lastNdx < SIZE - 1)
  {
    int p, c;

    c = ++A->lastNdx;
    for (p = 0; c > 0 && val > A->elem[p]; p = (c - 1) / 2)
    {
      A->elem[c] = A->elem[p];
      c = p;
    }
    A->elem[c] = val;
  }
}

int deleteMax(Heap *A)
{
  int val = -1;

  if (A->lastNdx != -1)
  {
    int p, c, tmp;

    p = 0;
    val = A->elem[p];
    A->elem[0] = A->elem[A->lastNdx--];
    tmp = A->elem[0];
    for (c = p * 2 + 1; c <= A->lastNdx; c = c * 2 + 1)
    {
      if (c + 1 <= A->lastNdx && A->elem[c + 1] > A->elem[c])
        c++;
      if (tmp < A->elem[c])
      {
        A->elem[p] = A->elem[c];
        p = c;
      }
      else
      {
        break;
      }
    }
    A->elem[p] = tmp;
  }
  return val;
}

void maxHeapify(Heap *A, int root)
{
  int l, r, largest;

  l = root * 2 + 1;
  r = l + 1;
  largest = root;
  if (l <= A->lastNdx && A->elem[l] > A->elem[largest])
  {
    largest = l;
  }
  if (r <= A->lastNdx && A->elem[r] > A->elem[largest])
  {
    largest = l;
  }

  if (largest != root)
  {
    A->elem[root] = A->elem[largest];
    maxHeapify(A, largest);
  }
}

void heapSort(Heap *A)
{
  int i, orig, catcher;

  orig = A->lastNdx;
  A->lastNdx = -1;
  for (i = 0; i <= orig; i++)
  {
    insert(A, A->elem[i]);
  }

  while (A->lastNdx > 0)
  {
    catcher = deleteMax(A);
    A->elem[A->lastNdx + 1] = catcher;
  }
  A->lastNdx = orig;
}

void heapSort2(Heap *A)
{
  int orig, catcher, x;

  orig = A->lastNdx;

  for (x = (orig - 1) / 2; x >= 0; x--)
  {
    maxHeapify(A, x);
  }

  while (A->lastNdx != -1)
  {
    catcher = deleteMax(A);
    A->elem[A->lastNdx + 1] = catcher;
  }
  A->lastNdx = orig;
}

int main()
{
  Heap A = {{7, 6, 5, 4, 3, 2, 1}, 6};

  displayHeap(A);
  heapSort2(&A);
  displayHeap(A);
  return 0;
}

void displayHeap(Heap A)
{
  int x;

  printf("\n");
  for (x = 0; x <= A.lastNdx; x++)
  {
    printf(" %d ->", A.elem[x]);
  }
}