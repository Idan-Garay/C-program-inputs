#include <stdio.h>

void merge(int arr[], int p, int q, int r)
{
  int x, y, j, n1, n2;
  n1 = q - p + 1;
  n2 = r - q;
  int L[n1];
  int R[n2];
  x = y = 0;
  j = p;

  for (x = 0; x < n1; x++)
    L[x] = arr[p + x];

  for (x = 0; x < n2; x++)
    R[x] = arr[q + 1 + x];

  x = 0;

  while (x < n1 && y < n2)
  {
    if (L[x] < R[y])
    {
      arr[j++] = L[x++];
    }
    else
    {
      arr[j++] = R[y++];
    }
  }

  while (x < n1)
  {
    arr[j++] = L[x++];
  }

  while (y < n2)
  {
    arr[j++] = R[y++];
  }
}

void mergeSort(int arr[], int p, int r)
{
  if (p < r)
  {
    int q = p + (r - p) / 2;
    mergeSort(arr, p, q);
    mergeSort(arr, q + 1, r);
    merge(arr, p, q, r);
  }
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

int main()
{
  int x[] = {6, 5, 12, 10, 9, 1};
  display(x, 6);
  mergeSort(x, 0, 5);
  display(x, 6);

  return 0;
}

void countingSort(int arr[], int size)
{
  int x, max;
  int output[size];

  max = arr[0];
  for (x = 1; x < size; x++)
  {
    if (arr[x] > max)
      max = arr[x];
  }

  int counter[max + 1];
  memset(counter, 0, sizeof(counter));

  for (x = 0; x < size; x++)
    counter[arr[x]]++;

  for (x = 1; x <= max; x++)
    counter[x] += counter[x - 1];

  for (x = size - 1; x >= 0; x--)
    output[--counter[arr[x]]] = arr[x];

  for (x = 0; x < size; x++)
  {
    arr[x] = output[x];
  }
  printArr(arr, size);
}