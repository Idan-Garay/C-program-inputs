#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int elem;
  struct node *link;
} * List;
void printList(List *A);

List *createSortedSublist(List *A)
{
  int max;
  List *ptr, *trav, tmp, *L = NULL;
  L = (List *)calloc(1, sizeof(List));

  if (*A != NULL)
  {
    ptr = L;
    trav = A;
    max = -99999;
    do
    {
      if (max < (*trav)->elem)
      {
        max = (*trav)->elem;

        tmp = *trav;
        *trav = (*trav)->link;
        tmp->link = NULL;

        *ptr = tmp;
        ptr = &(*ptr)->link;
      }
      else
        trav = &(*trav)->link;
    } while (*trav != NULL);
  }
  return L;
}

void mergeSortedList(List *A, List *B)
{
  List *travA, *travB, travNext, ptr;

  travA = A;
  travB = B;

  while (*travB != NULL)
  {
    if ((*travA)->elem < (*travB)->elem)
    {
      travNext = (*travA)->link;
      while (travNext != NULL && travNext->elem < (*travB)->elem)
      {
        travA = &(*travA)->link;
        travNext = (*travA)->link;
      }

      ptr = *travB;
      *travB = (*travB)->link;
      ptr->link = (*travA)->link;
      (*travA)->link = ptr;
    }
    else
    {
      ptr = *travA;
      *travA = *travB;
      *travB = (*travB)->link;
      (*travA)->link = ptr;
    }
  }
}

List *SortAlgoX(List *A)
{
  List *B = createSortedSublist(A);
  printList(B);
  mergeSortedList(A, B);
  return A;
}

void insertLast(List *A, int val)
{
  List *trav;

  for (trav = A; *trav != NULL; trav = &(*trav)->link)
  {
  }
  if (*trav == NULL)
  {
    List tmp = (List)calloc(1, sizeof(struct node));
    tmp->elem = val;
    tmp->link = NULL;
    *trav = tmp;
  }
}

void fillList(List *A, int values[], int size)
{
  int x;

  for (x = 0; x < size; x++)
  {
    insertLast(A, values[x]);
  }
}

void printList(List *A)
{
  List trav;

  printf("\n");
  for (trav = *A; trav != NULL; trav = trav->link)
  {
    printf(" %d", trav->elem);
  }
}

int main()
{
  List *B, A = NULL;
  int arr[] = {10, 2, 30, 40, 4, 5, 9};
  fillList(&A, arr, 7);
  printList(&A);

  B = SortAlgoX(&A);
  printList(B);
  return 0;
}

/*
  Given List: 10 5 30 40 2 4 9
  After createSortedSublist
  Sublist: 10 30 40
  Given List: 5 2 4 9
*/