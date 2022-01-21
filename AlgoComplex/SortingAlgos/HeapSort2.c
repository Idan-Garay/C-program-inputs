#include <stdio.h>
#include <stdlib.h>
#define SIZE 8

typedef struct heap
{
  int elem[SIZE];
  int lastNdx;
} heap;

void display(heap H);

void swap(int *a, int *b)
{
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

int deleteMax(heap *H)
{
  int max = -1;
  if (H->lastNdx != -1)
  {
    int c, p, tmp;

    p = 0;
    max = H->elem[p];
    tmp = H->elem[H->lastNdx--];
    H->elem[p] = tmp;

    for (c = p * 2 + 1; c <= H->lastNdx; c = p * 2 + 1)
    {
      if (c + 1 <= H->lastNdx && H->elem[c + 1] > H->elem[c])
        c++;
      if (tmp < H->elem[c])
      {
        H->elem[p] = H->elem[c];
        p = c;
      }
    }
    H->elem[p] = tmp;
  }
  return max;
}

void maxHeapify(heap *H, int node)
{
  int largest = node;
  int c = node * 2 + 1;

  if (c <= H->lastNdx && H->elem[c] > H->elem[largest])
    largest = c;
  if (c + 1 <= H->lastNdx && H->elem[c + 1] > H->elem[largest])
  {
    largest = c + 1;
  }

  if (largest != node)
  {
    swap(H->elem + largest, H->elem + node);
    maxHeapify(H, largest);
  }
}

void heapSort(heap *H)
{
  int x, orig, catch;

  for (x = H->lastNdx / 2 - 1; x >= 0; x--)
  {
    maxHeapify(H, x);
    printf("[%d] ", x);
    display(*H);
  }

  orig = H->lastNdx;
  while (H->lastNdx != -1)
  {
    catch = deleteMax(H);
    H->elem[H->lastNdx + 1] = catch;
  }
  H->lastNdx = orig;
}

void display(heap H)
{
  int x;

  for (x = 0; x <= H.lastNdx; x++)
  {
    printf("%d ", H.elem[x]);
  }
  printf("\n");
}

int main()
{
  heap H = {{1, 6, 3, 5, 8, 4, 7, 2}, 7};

  display(H);
  heapSort(&H);
  printf("\nSorted: ");
  display(H);
  //heapify process
  /*
    [3]: 1 6 3 5 8 4 7 2
    [2]: 1 6 7 5 8 4 3 2
    [1]: 1 8 7 5 6 4 3 2
    [0]: 8 6 7 5 1 4 3 2
  */

  return 0;
}