#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  float elem;
  struct node *next;
} node, *List;

void displayArr(float A[], int size);
List *createBuckets(int size)
{
  return (List *)calloc(size, sizeof(List));
}

int getBucketIndex(List node)
{
  return node->elem * 10;
}

void intobuckets(float A[], int aSize, List nodeList[], int listSize)
{
  int x, ndx;
  List tmp;

  for (x = 0; x < aSize; x++)
  {
    tmp = calloc(1, sizeof(node));
    if (tmp != NULL)
    {
      ndx = getBucketIndex(tmp);
      tmp->elem = A[x];
      tmp->next = nodeList[ndx];
      nodeList[ndx] = tmp;
    }
  }
}

void swap(float *a, float *b)
{
  float tmp = *a;
  *a = *b;
  *b = tmp;
}

void selectionSort(List list)
{
  List sorted, unsorted, max;

  for (sorted = list; sorted->next != NULL; sorted = sorted->next)
  {
    max = sorted;
    for (unsorted = sorted->next; unsorted != NULL; unsorted = unsorted->next)
    {
      if (max->elem > unsorted->elem)
        max = unsorted;
    }
    swap(&(max->elem), &(sorted->elem));
  }
}

void bucketSort(float A[], int size)
{
  int x, bucketNdx, count;
  List trav, *nodeList;
  // 1. Create new array approximately the same size as the original array and initiate to null
  nodeList = createBuckets(size);

  // 2. Place each element in the original array to its appropriate bucket (hash function)
  intobuckets(A, size, nodeList, size);
  // 3. Sort elements in the non-empty buckets
  for (x = 0; x < size; x++)
  {
    if (nodeList[x] != NULL)
    {
      selectionSort(nodeList[x]);
    }
  }
  // 4. Gather all elements in bucket into one array.
  count = 0;
  for (x = 0; x < size; x++)
  {
    for (trav = nodeList[x]; trav != NULL; trav = trav->next)
    {
      A[count++] = trav->elem;
    }
  }
}

int main()
{
  float A[] = {0.2,
               0.6,
               0.4,
               0.73,
               0.21,
               0.71,
               0.74,
               0.93,
               0.84,
               0.57};

  displayArr(A, 10);
  bucketSort(A, 10);
  displayArr(A, 10);

  return 0;
}

void displayArr(float A[], int size)
{
  int x;

  printf("\n");
  for (x = 0; x < size; x++)
  {
    printf(" %.2g,", A[x]);
  }
}