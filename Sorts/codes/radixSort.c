#include <stdio.h>
#include "countSort.c"

void displayArrRadix(int A[], int size);
int getMaxRadix(int A[], int size)
{
  int x, max = -9999;

  for (x = 1; x < size; x++)
  {
    if (max < A[x])
      max = A[x];
  }
  return max;
}

int countDigits(int num)
{
  int d = 0;

  do
  {
    num = num / 10;
    d++;
  } while (num != 0);
  return d;
}

void radixSort(int A[], int size)
{
  int x, d, max, exp = 1;

  // 1. Find the largest element on the list and determine its maximum number of digits.
  max = getMaxRadix(A, size);
  d = countDigits(max);

  // 2. Sort the Elements according to ith place digits using Bucket Sort or Counting Sort.
  // for (x = 1; x <= d; x++)
  // {
  //   countingSort(A, size, exp);
  //   exp *= 10;
  // }
  for (exp = 1; max / exp > 0; exp *= 10)
  {
    countingSort(A, size, exp);
  }
}

int main()
{
  int A[] = {4, 93, 71, 21, 6, 2, 74, 73, 84, 57};
  int size = 10;

  displayArrRadix(A, size);
  radixSort(A, size);
  displayArrRadix(A, size);

  return 0;
}

void displayArrRadix(int A[], int size)
{
  int x;

  printf("\n");
  for (x = 0; x < size; x++)
  {
    printf(" %d,", A[x]);
  }
}