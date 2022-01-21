#include <stdio.h>

void swap(int *a, int *b)
{
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void merge(int A[], int lo, int mid, int hi)
{
  int leftSize, rightSize, i, j, k;

  leftSize = mid - lo + 1;
  rightSize = hi - mid;
  int left[leftSize], right[rightSize];

  for (i = 0; i < leftSize; i++)
  {
    left[i] = A[lo + i];
  }

  for (j = 0; j < rightSize; j++)
  {
    right[j] = A[mid + j + 1];
  }

  j = i = 0;
  k = lo;

  while (i < leftSize && j < rightSize)
  {
    if (left[i] < right[j])
      A[k++] = left[i++];
    else
      A[k++] = right[j++];
  }

  while (i < leftSize)
  {
    A[k++] = left[i++];
  }

  while (j < rightSize)
  {
    A[k++] = right[j++];
  }
}

void mergeSort(int A[], int lo, int hi)
{
  if (lo < hi)
  {
    int mid = (lo + hi) / 2;
    mergeSort(A, lo, mid);
    mergeSort(A, mid + 1, hi);
    merge(A, lo, mid, hi);
  }
}