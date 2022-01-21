#include <stdio.h>

void display(int arr[], int size);
void test(int A[], int size, int start, int end);

void swap(int *a, int *b)
{
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

int partitionInternetVar(int A[], int start, int end)
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

int partitionLomuto(int A[], int start, int end)
{
  int i, j, pivot;

  pivot = A[end];
  i = start - 1;

  for (j = start; j < end; j++)
  {
    if (A[j] <= pivot)
    {
      i++;
      swap(A + j, A + i);
    }
  }

  swap(A + (i + 1), A + end); // swap(A[i+1], A[end])
  return i + 1;
}

void quickSort(int A[], int start, int end)
{
  if (start < end)
  {
    int pivot = partitionInternetVar(A, start, end);
    display(A, 8);
    quickSort(A, start, pivot - 1);
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
