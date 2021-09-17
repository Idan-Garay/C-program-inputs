#include <stdio.h>
#include <string.h>

void display(int arr[], int size);
void test(int A[], int size, int start, int end);

void merge(int A[], int start, int mid, int end)
{
  int p = start, q = mid + 1;

  int Arr[end - start + 1], k = 0;

  for (int i = start; i <= end; i++)
  {
    if (p > mid) //checks if first part comes to an end or not .
      Arr[k++] = A[q++];

    else if (q > end) //checks if second part comes to an end or not
      Arr[k++] = A[p++];

    else if (A[p] < A[q]) //checks which part has smaller element.
      Arr[k++] = A[p++];

    else
      Arr[k++] = A[q++];
  }
  for (int p = 0; p < k; p++)
  {
    /* Now the real array has elements in sorted manner including both 
        parts.*/
    A[start++] = Arr[p];
  }
}

void mergeSort(int A[], int lo, int hi)
{
  if (lo != hi)
  {
    int mid = lo + (hi - lo) / 2;
    mergeSort(A, lo, mid);
    mergeSort(A, mid + 1, hi);
    merge(A, lo, mid, hi);
  }
}

int main()
{
  int arr[] = {4, 2, 8, 3, 1};
  test(arr, 5, 0, 4);
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
  mergeSort(A, start, end);
  display(A, size);
}
