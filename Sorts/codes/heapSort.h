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

void insertMax(heap *h, int val)
{
  int p, c;

  if (h->lastNdx < SIZE - 1)
  {
    c = ++h->lastNdx;
    for (p = (c - 1) / 2; c > 0 && h->elem[p] < val; p = (c - 1) / 2)
    {
      h->elem[c] = h->elem[p];
      c = p;
    }
    h->elem[c] = val;
  }
}

int deleteMax(heap *h)
{
  int val = -1;

  if (h->lastNdx != -1)
  {
    int p, c, tmp;

    p = 0;
    val = h->elem[p];
    tmp = h->elem[h->lastNdx--];
    for (c = p * 2 + 1; c <= h->lastNdx; c = p * 2 + 1)
    {
      if (c + 1 <= h->lastNdx && h->elem[c + 1] > h->elem[c])
        c++;
      if (tmp < h->elem[c])
      {
        h->elem[p] = h->elem[c];
        p = c;
      }
      else
      {
        break;
      }
    }
    h->elem[p] = tmp;
  }

  return val;
}

void heapSort(heap *h)
{
  int x, orig, catcher;

  orig = h->lastNdx;
  h->lastNdx = -1;

  for (x = 0; x < orig; x++)
  {
    insertMax(h, h->elem[x]);
  }

  while (h->lastNdx != -1)
  {
    catcher = deleteMax(h);
    h->elem[h->lastNdx + 1] = catcher;
  }
  h->lastNdx = orig;
}