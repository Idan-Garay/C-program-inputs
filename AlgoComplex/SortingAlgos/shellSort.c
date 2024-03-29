#include <stdio.h>
#include "arrayUtil.h"
void test(int A[], int size);
void shellSort(int A[], int size)
{
  int gap, y, x, tmp;

  for (gap = size / 2; gap > 0; gap /= 2)
  {
    for (x = gap; x < size; x++)
    {
      tmp = A[x];
      for (y = x; y >= gap && tmp < A[y - gap]; y -= gap)
        A[y] = A[y - gap];
      A[y] = tmp;
    }
    printf("\n[%d]: ", gap);
    display(A, size);
  }
}

int main()
{
  int input2[] = {8, 3, 6, 9, 7, 0};
  test(input2, 6);
  return 0;
}

void test(int A[], int size)
{
  display(A, size);
  shellSort(A, size);
  display(A, size);
}