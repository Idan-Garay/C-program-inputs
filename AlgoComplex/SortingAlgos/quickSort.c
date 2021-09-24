#include <stdio.h>

void display(int arr[], int size);
void test(int A[], int size, int start, int end);

int partition(int A[], int start, int end)
{
  int i, temp, j, pivot;
  pivot = A[start];

  for (i = j = start + 1; j <= end; j++)
  {
    if (A[j] < pivot)
    {
      temp = A[j];
      A[j] = A[i];
      A[i] = temp;
      i++;
    }
  }
  temp = A[start];
  A[start] = A[i - 1];
  A[i - 1] = temp;

  return i - 1;
}

void quickSort(int A[], int start, int end)
{
  if (start < end)
  {
    int pivot = partition(A, start, end);
    quickSort(A, start, pivot - 1);
    quickSort(A, pivot + 1, end);
  }
}

int main()
{
  int arr[] = {9, 7, 8, 3, 2, 1};
  test(arr, 6, 0, 5);
}

void display(int arr[], int size)
{
  int x;

  printf("\n");
  for (x = 0; x < size; x++)
  {
    printf(" %d", arr[x]);
  }
}

void test(int A[], int size, int start, int end)
{
  display(A, size);
  quickSort(A, start, end);
  display(A, size);
}
