void display(int arr[], int size);
void displayF(float arr[], int size);

// shell Sort
void shellSort(int A[], int size)
{
  int gap, x, y, temp;

  for (gap = size / 2; gap > 0; gap /= 2)
  {
    for (x = gap; x < size; x += gap)
    {
      temp = A[x];
      for (y = x; y > 0 && temp < A[y - gap]; y -= gap)
      {
        A[y] = A[y - gap];
      }
      A[y] = temp;
    }
  }
}

void testShellSort(int A[], int size)
{
  printf("Shell Sort: \n");
  display(A, size);
  shellSort(A, size);
  printf(" -> ");
  display(A, size);
  printf("\n");
}

// Merge Sort
void merge(int A[], int lo, int mid, int hi)
{
  int leftLength = mid - lo + 1;
  int rightLength = hi - mid;
  int left[leftLength];
  int rightPart[rightLength];
  int j, g, k;

  for (g = 0; g < leftLength; g++)
  {
    left[g] = A[lo + g - 1];
  }

  for (j = 0; j < rightLength; j++)
  {
    rightPart[j] = A[mid + 1 + j];
  }

  j = g = 0;
  for (k = lo; k <= hi; k++)
  {
    if (j < leftLength && left[j] <= rightPart[g])
    {
      A[k] = left[j++];
    }
    else
    {
      A[k] = rightPart[g++];
    }
  }
}

void mergeSort(int A[], int lo, int hi)
{
  if (lo < hi)
  {
    int mid = (hi + lo) / 2;
    mergeSort(A, lo, mid);
    mergeSort(A, mid + 1, hi);
    merge(A, lo, mid, hi);
  }
}

void testMergeSort(int A[], int size)
{
  printf("Merge Sort: \n");
  display(A, size);
  mergeSort(A, 0, size - 1);
  printf(" -> ");
  display(A, size);
  printf("\n");
}

// quick sort

int partition(int A[], int lo, int hi)
{
  int pivot = A[hi];

  int i, j, swap;

  i = lo - 1;
  for (j = lo; j < hi; j++)
  {
    if (A[j] < pivot)
    {
      i++;
      swap = A[j];
      A[j] = A[i];
      A[i] = swap;
    }
  }
  swap = A[i + 1];
  A[i + 1] = A[hi];
  A[hi] = swap;

  return i + 1;
}

void quickSort(int A[], int lo, int hi)
{
  if (lo < hi)
  {
    int pivot = partition(A, lo, hi);

    quickSort(A, lo, pivot - 1);
    quickSort(A, pivot + 1, hi);
  }
}

void testQuickSort(int A[], int size)
{
  printf("Quick Sort: \n");
  display(A, size);
  quickSort(A, 0, size - 1);
  printf(" -> ");
  display(A, size);
  printf("\n");
}

typedef struct node
{
  float val;
  struct node *next;
} node, *ptr;

// Bucket Sort
#include <stdlib.h>
void insertionSort(ptr *List);
void displayBuckets(ptr A[], int size)
{
  int x;
  ptr trav;

  printf("\n");
  for (x = 0; x < size; x++)
  {
    printf("[%d]: ", x);
    for (trav = A[x]; trav != NULL; trav = trav->next)
    {
      printf(" %f ->", trav->val);
    }
    printf("\n");
  }
}

void bucketSort(float A[], int size)
{
  ptr trav, *buckets = calloc(size, sizeof(ptr));
  int x, k, idx;
  float _MAX = A[0];

  for (x = 1; x < size; x++)
  {
    if (_MAX < A[x])
      _MAX = A[x];
  }

  for (x = 0; x < size; x++)
  {
    idx = (A[x] * size);
    ptr element = malloc(sizeof(node));
    element->val = A[x];
    element->next = buckets[idx];
    buckets[idx] = element;
  }

  k = 0;
  for (x = 0; x < size; x++)
  {
    insertionSort(buckets + x);
    for (trav = buckets[x]; k < size && trav != NULL; trav = trav->next)
    {
      A[k++] = trav->val;
    }
  }

  free(buckets);
}

void testBucketSort(float A[], int size)
{

  printf("Bucket Sort: \n");
  displayF(A, size);
  bucketSort(A, size);
  printf(" -> ");
  displayF(A, size);
  printf("\n");
}

void insertionSort(ptr *List)
{

  if (*List != NULL && (*List)->next != NULL)
  {
    ptr trav, trav2;
    float tmp, hold;
    int flag = 0;
    for (trav = (*List)->next; trav != NULL; trav = trav->next)
    {
      tmp = trav->val;
      for (trav2 = *List; trav2 != NULL; trav2 = trav2->next)
      {
        if (tmp < trav2->val)
        {
          flag = 1;
        }
        if (flag == 1)
        {
          hold = trav2->val;
          trav2->val = tmp;
          tmp = hold;
        }
      }
    }
  }
}

// counting sort
#include <string.h>
void countingSort(int A[], int size, int exp)
{
  int *count, x;
  int B[size];
  int _MAX = A[0] % exp;

  memcpy(B, A, sizeof(int) * size);
  for (x = 1; x < size; x++)
  {
    if ((A[x] % exp) > _MAX)
      _MAX = A[x] % exp;
  }

  count = (int *)calloc(_MAX + 1, sizeof(int));
  for (x = 0; x < size; x++)
  {
    count[A[x] % exp]++;
  }

  for (x = 1; x <= _MAX; x++)
  {
    count[x] += count[x - 1];
  }

  for (x = size - 1; x >= 0; x--)
  {
    A[--count[B[x]]] = B[x];
  }
  free(count);
}

void testCountingSort(int A[], int size)
{

  printf("Counting Sort: \n");
  display(A, size);
  countingSort(A, size, 1000);
  printf(" -> ");
  display(A, size);
  printf("\n");
}

// radix sort

void radixSort(int A[], int size)
{
  int x, largest;
  largest = A[0];
  printf(" -> 1");

  for (x = 1; x < size; x++)
  {
    if (largest < A[x])
      largest = A[x];
  }
  printf(" -> 2");

  for (x = 10; (largest % x) != 0; x *= 10)
  {
    printf(" -> 3");
    countingSort(A, size, x);
  }
}

void testRadixSort(int A[], int size)
{

  printf("Radix Sort: \n");
  display(A, size);
  radixSort(A, size);
  printf(" -> ");
  display(A, size);
  printf("\n");
}

// display utility
void display(int arr[], int size)
{
  int x;

  for (x = 0; x < size; x++)
  {
    printf(" %d", arr[x]);
  }
}

void displayF(float arr[], int size)
{
  int x;

  for (x = 0; x < size; x++)
  {
    printf(" %g", arr[x]);
  }
}
