#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10

typedef struct node
{
  float elem;
  struct node *next;
} node, *List;

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

int partitionHoare(int A[], int lo, int hi)
{
  int i, j, pivot;

  i = lo;
  j = hi;
  pivot = A[(hi + lo) / 2];
  while (1)
  {
    while (A[i] < pivot)
      i++;
    while (A[j] > pivot)
      j--;
    if (i < j)
      swap(&A[i], &A[j]);
    else
      return j;
  }
}

void quickSort(int A[], int lo, int hi)
{
  if (lo < hi)
  {
    int piv = partitionHoare(A, lo, hi);
    quickSort(A, lo, piv);
    quickSort(A, piv + 1, hi);
  }
}

int main()
{
  int A[] = {4, 93, 71, 21, 6, 2, 74, 73, 84, 57};
  // float Af[] = {.4, .93, .71, .21, .6, .2, .74, .73, .84, .57};
  int size = 10;
  heap h = {{4, 93, 71, 21, 6, 2, 74, 73, 84, 57}, 9};

  // Summary for shell, merge, quick, counting, bucket, radix, heap
  displayArr(A, size);
  quickSort(A, 0, 9);
  displayArr(A, size);

  return 0;
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

void displayHeap(heap h)
{
  int x;

  printf("\n");
  for (x = 0; x <= h.lastNdx; x++)
  {
    printf(" %d,", h.elem[x]);
  }
}