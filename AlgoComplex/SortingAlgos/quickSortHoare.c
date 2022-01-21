#include <stdio.h>

void display(int arr[], int size);
void test(int A[], int size, int start, int end);

int partition(int A[], int start, int end)
{
  int l, r, pivot, temp;

  pivot = A[(start + end) / 2];
  while (1)
  {
    for (l = start; A[l] < pivot; l++)
    {
    }
    for (r = end; A[r] > pivot; r--)
    {
    }

    if (l >= r)
      return r;

    temp = A[l];
    A[l] = A[r];
    A[r] = temp;
  }
}

void quickSort(int A[], int start, int end)
{
  if (start < end)
  {
    int pivot = partition(A, start, end);
    display(A, 8);
    quickSort(A, start, pivot);
    quickSort(A, pivot + 1, end);
  }
}

int main()
{
  int arr[] = {2, 8, 7, 1, 3, 5, 6, 4};
  test(arr, 8, 0, 7);
}

void display(int arr[], int size)
{
  int x;

  for (x = 0; x < size; x++)
  {
    printf(" %d", arr[x]);
  }
  printf("\n");
}

void test(int A[], int size, int start, int end)
{
  display(A, size);
  quickSort(A, start, end);
  // display(A, size);
}
