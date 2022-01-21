#include <stdio.h>

void swap(int *a, int *b)
{
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

int partition(int A[], int lo, int hi)
{
  int i, pivot, j;

  pivot = A[hi];
  i = lo - 1;

  for (j = i + 1; j < hi; j++)
  {
    if (A[j] < pivot)
    {

      swap(&A[++i], &A[j]);
    }
  }

  swap(&A[i + 1], &A[hi]);
  return i + 1;
}

void quickSort(int A[], int lo, int hi)
{
  if (lo < hi)
  {
    int pivot = partition(A, lo, hi);
    quickSort(A, lo, pivot - 1);
    quickSort(A, pivot + 1, hi);
  }
}