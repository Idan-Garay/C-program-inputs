#include <stdio.h>
#define SIZE 10

typedef struct heap
{
  int elem[SIZE];
  int lastNdx;
} heap;

void displayHeap(heap h)
{
  int x;

  printf("\n");
  for (x = 0; x <= h.lastNdx; x++)
  {
    printf(" %d, ", h.elem[x]);
  }
}

void swap(int *a, int *b)
{
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void minHeapify(heap *h, int root)
{
  int smallest = root;
  int c = root * 2 + 1;

  if (c <= h->lastNdx && h->elem[c] < h->elem[smallest])
    smallest = c;
  if (c + 1 <= h->lastNdx && h->elem[c + 1] < h->elem[smallest])
    smallest = c + 1;

  if (smallest != root)
  {
    swap(&(h->elem[smallest]), &(h->elem[root]));
    minHeapify(h, smallest);
  }
}

void insertMin(heap *h, int val)
{
  if (h->lastNdx < SIZE - 1)
  {
    int p, c;

    c = ++h->lastNdx;
    h->elem[c] = val;
    for (p = (c - 1) / 2; c > 0 && h->elem[p] > val; p = (c - 1) / 2)
    {
      c = p;
      minHeapify(h, p);
    }
  }
}

int deleteMin(heap *h)
{
  int val = -1;

  if (h->lastNdx != -1)
  {
    val = h->elem[0];
    h->elem[0] = h->elem[h->lastNdx--];
    minHeapify(h, 0);
  }
  return val;
}

void heapSort(heap *h)
{
  int catcher, orig, x;

  orig = h->lastNdx;
  for (x = (orig - 1) / 2; x >= 0; x--)
  {
    minHeapify(h, x);
  }

  while (h->lastNdx != -1)
  {
    catcher = deleteMin(h);
    h->elem[h->lastNdx + 1] = catcher;
  }
  h->lastNdx = orig;
}