#include <stdio.h>

void insertionSort(int A[], int size)
{
  int j, k, tmp;

  for (j = 1; j < size; j++)
  {
    tmp = A[j];
    k = j - 1;
    while (k >= 0 && A[k] > tmp)
    {
      A[k + 1] = A[k];
      k--;
    }
    A[k + 1] = tmp;
  }
}

// for (j = 0; j < size - 1; j++)
//   {
//     tmp = A[j + 1];
//     for (k = j + 1; k > 0 && A[k - 1] > tmp; k--)
//       A[k] = A[k - 1];

//     A[k] = tmp;
//   }

void displayArr(int A[], int size)
{
  int x;

  printf("\n");
  for (x = 0; x < size; x++)
  {
    printf(" %d,", A[x]);
  }
}

void test(int A[], int size)
{
  displayArr(A, size);
  insertionSort(A, size);
  displayArr(A, size);
}

int main()
{
  int A[] = {4, 2, 8, 3, 0, 1};

  test(A, 6);

  return 0;
}