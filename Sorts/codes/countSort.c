#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void displayArr(int A[], int size);
void countingSort(int A[], int size, int exp)
{
  int x, count[10], B[size];

  memset(count, 0, sizeof(int) * 10);
  for (x = 0; x < size; x++)
  {
    count[(A[x] / exp) % 10]++;
  }

  for (x = 1; x < size; x++)
  {
    count[x] += count[x - 1];
  }

  memcpy(B, A, sizeof(int) * size);

  for (x = size - 1; x >= 0; x--)
  {
    A[--count[(B[x] / exp) % 10]] = B[x];
  }
}

int main()
{

  int A[] = {4, 93, 71, 21, 6, 2, 74, 73, 84, 57};
  int size = 10;

  displayArr(A, size);
  countingSort(A, size, 1);
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