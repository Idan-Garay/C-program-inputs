#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int elem;
  struct node *link;
} * List;

List populateList(int A[], int size)
{
  List L, *trav;
  int x;

  L = NULL;
  trav = &L;

  for (x = 0; x < size; x++)
  {
    *trav = (List)calloc(1, sizeof(struct node));
    if (*trav != NULL)
    {
      (*trav)->elem = A[x];
      trav = &(*trav)->link;
    }
  }

  return L;
}

void displayList(List L, char msg[])
{
  printf("\n%s:", msg);
  if (L == NULL)
  {
    printf(" Empty");
  }
  else
  {
    while (L != NULL)
    {
      printf(" %d,", L->elem);
      L = L->link;
    }
  }
}

List createSubList(List *A)
{
  List *trav, head, trav2;

  if (*A != NULL)
  {
    int large;

    head = trav2 = *A;
    *A = head->link;
    large = head->elem;
    for (trav = A; *trav != NULL;)
    {
      if (large < (*trav)->elem)
      {
        large = (*trav)->elem;
        trav2->link = *trav;
        *trav = (*trav)->link;
        trav2 = trav2->link;
      }
      else
      {
        trav = &(*trav)->link;
      }
    }
    trav2->link = NULL;
  }
  return head;
}

void merge2Lists(List *out, List *in)
{
  List *outTrav, *inTrav, hold;

  if (*out == NULL)
  {
    *out = *in;
  }
  else
  {
    outTrav = out;
    inTrav = in;
    while (*inTrav != NULL)
    {
      if ((*outTrav)->elem > (*inTrav)->elem)
      {
        hold = *inTrav;
        *inTrav = (*inTrav)->link;
        hold->link = *outTrav;
        *outTrav = hold;
      }

      outTrav = &(*outTrav)->link;
    }
  }
}

int main()
{
  // int arr[] = {10, 5, 30, 40, 2, 4, 9};
  int arr[] = {21, 15, 1, 6, 9, 0, 17, 100, 20, 5, 33, 65, 2, 10, 89};
  int num = sizeof(arr) / sizeof(int);

  // task 1
  printf("Task 1");
  List original = populateList(arr, num);
  displayList(original, "Original");

  List sublist;
  // printf("\n\nTask 2");
  // while (original != NULL)
  // {
  //   sublist = createSubList(&original);
  //   displayList(sublist, "Sublist");
  //   displayList(original, "Original");
  // }

  List outlist = NULL;
  // printf("\n\nTask 3");
  // sublist = createSubList(&original);
  // merge2Lists(&original, &sublist);
  // displayList(sublist, "Sublist");
  // displayList(original, "Outlist");
  // displayList(original, "Original");

  printf("\n\nTask 4");
  while (original != NULL)
  {
    displayList(original, "Original");
    sublist = createSubList(&original);
    displayList(original, "Original");
    displayList(sublist, "SubList");
    merge2Lists(&outlist, &sublist);
    displayList(outlist, "Output");
  }

  // displayList(sublist, "sorted");
  return 0;
}