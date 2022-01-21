#include <stdio.h>
#include <string.h>

void display(int arr[], int size);
void test(int A[], int size, int start, int end);

void merge(int A[], int start, int mid, int end)
{
  int q, p, k, x;
  int arr[end-start+1];

  p = start;
  q = mid+1;
  k = 0;

  for (x = start; x <= end; x++) {
    if (p > mid) 
      arr[k++] = A[q++];
    else if (q > end)
      arr[k++] = A[p++];
    else if(A[p] < A[q])
      arr[k++] = A[p++];
    else
      arr[k++] = A[q++];
  }

  for (x = 0; x < k; x++) {
    A[start++] = arr[x];
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
