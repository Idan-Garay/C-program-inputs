#include <stdio.h>
#include "SortingAlgorithms.c"

int main()
{
  int A[] = {4, 3, 2, 10, 12, 1, 5, 6};
  // float B[] = {0.4, 0.3521, 0.224, 0.10, 0.12, 0.1, 0.5, 0.6};
  // int C[] = {231, 0, 76, 5, 10005, 6044, 7012, 3988};
  // testShellSort(A, 8);
  // testQuickSort(A, 8);
  // testBucketSort(B, 8);
  // testCountingSort(A, 8);
  testRadixSort(A, 8);

  return 0;
}
