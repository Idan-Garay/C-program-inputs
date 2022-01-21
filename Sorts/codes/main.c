#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// #include "shellSort.h"
// #include "mergeSort.h"
// #include "quickSortHoare.h"
#define SIZE 10

typedef struct
{
  int elem[SIZE];
  int lastNdx;
} heap;

void displayArr(int A[], int size);
void displayHeap(heap h);

void swap(int *a, int *b)
{
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void maxHeapify(heap *h, int root)
{
  int largest, l, r;

  largest = root;
  l = root * 2 + 1;
  r = l + 1;

  if (l <= h->lastNdx && h->elem[l] > h->elem[largest])
    largest = l;
  if (r <= h->lastNdx && h->elem[r] > h->elem[largest])
    largest = r;
  if (largest != root)
  {
    swap(&h->elem[largest], &h->elem[root]);
    maxHeapify(h, largest);
  }
}

void insertMax(heap *h, int val)
{
  if (h->lastNdx < SIZE - 1)
  {
    int p, c;

    c = ++h->lastNdx;
    h->elem[c] = val;
    for (p = c * 2 + 1; c > 0 && h->elem[p] < h->elem[c]; p = c * 2 + 1)
    {
      maxHeapify(h, p);
      c = p;
    }
  }
}

int deleteMax(heap *h)
{
  int val = -1;

  if (h->lastNdx != -1)
  {
    val = h->elem[0];
    h->elem[0] = h->elem[h->lastNdx--];
    maxHeapify(h, 0);
  }
  return val;
}

void heapSort(heap *h)
{
  int orig, catcher, x;

  orig = h->lastNdx;
  for (x = (h->lastNdx - 1) / 2; x >= 0; x--)
  {
    maxHeapify(h, x);
  }

  while (h->lastNdx != -1)
  {
    catcher = deleteMax(h);
    h->elem[h->lastNdx + 1] = catcher;
  }
  h->lastNdx = orig;
}

int main()
{
  int A[] = {4, 93, 71, 21, 6, 2, 74, 73, 84, 57};
  float Af[] = {.4, .93, .71, .21, .6, .2, .74, .73, .84, .57};
  int size = 10;
  heap h = {{4, 93, 71, 21, 6, 2, 74, 73, 84, 57}, 9};
  // heap h = {{}, -1};

  // displayArr(A, size);
  // shellSort(A, size);
  // radixSort(A, size);
  // quickSort(A, 0, 9);
  displayHeap(h);
  heapSort(&h);
  displayHeap(h);

  // displayArr(A, size);
}

void displayHeap(heap h)
{
  int x;

  printf("\n");
  for (x = 0; x <= h.lastNdx; x++)
  {
    printf(" %d,", h.elem[x]);
  }
}

void displayFloats(float A[], int size)
{
  int x;

  printf("\n");
  for (x = 0; x < size; x++)
  {
    printf(" %.3g,", A[x]);
  }
}

void displayArr(int A[], int size)
{
  int x;

  printf("\n");
  for (x = 0; x < size; x++)
  {
    printf(" %d,", A[x]);
  }
}