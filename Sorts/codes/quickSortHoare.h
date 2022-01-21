#include <stdio.h>

void swap(int *a, int *b)
{
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

int partition(int A[], int lo, int hi)
{
  int i, j, pivot;

  pivot = A[(hi + lo) / 2];
  i = lo;
  j = hi;
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
    int pivot = partition(A, lo, hi);
    quickSort(A, lo, pivot);
    quickSort(A, pivot + 1, hi);
  }
}