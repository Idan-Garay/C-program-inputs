#include <stdio.h>

void shellSort(int A[], int size)
{
  int gap, x, tmp, trav;
  int count = 0;

  for (gap = size / 2; gap > 0; gap /= 2)
  {
    for (x = gap; x < size; x++)
    {
      tmp = A[x];
      for (trav = x; trav >= gap && A[trav - gap] > tmp; trav -= gap)
      {
        A[trav] = A[trav - gap];
        count++;
      }
      A[trav] = tmp;
    }
  }
  printf("\n # of operations: %d \n", count);
}
