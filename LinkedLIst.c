#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int elem;
  struct node *link;
} * List;

List populateList(int A[], int count);
List createSubList(List *A);
void merge2Lists(List *Out, List *In);
void displayList(List L, char msg[]);
void freeList(List *L);

int main()
{
  // int arr[] = {83, 86, 77, 15, 93, 35, 86, 92, 49, 21, 62, 27, 90, 59, 63, 26, 40, 26, 72, 36};
  // int arr[] = {21, 15, 1, 6, 9, 0, 17, 100, 20, 5, 33, 65, 2, 10, 89};
  int arr[] = {10, 5, 30, 40, 2, 4, 9};
  int num = sizeof(arr) / sizeof(int);
  List orig, subList, output = NULL;

  //	Task 1: Call populateList() and displayList()
  printf("Task 1: ");
  orig = populateList(arr, num);
  displayList(orig, "Original");
  printf("\n");
  printf("_________________________________________________________");
  /*	Task 2: while (orig list is not empty)
			a) Call createSublist
			b) displayList() - passing the sublist
			c) displayList() - passing the Orig*/

  /*
	for(num=1;orig != NULL; num++){
	    subList = createSubList(&orig);
	    displayList(subList,"SubList");
	    displayList(orig, "Original");
	    printf("\n");
	}
	*/

  /*	Task 3: Call createSublist(), merge2Lists() and displayList() is called 3 times
			a) display the subList
			b) display the outList
			c) display the original
	*/
  /*
	subList = createSubList(&orig);
	displayList(subList, "SubList");
	merge2Lists(&output,&subList);
	displayList(output,"Output");
	*/
  /*	
		Task 4: 
		while (orig is not empty) {
			a) call createSubList ==> returns sublist
			b) call merge2Lists ==> merges the output and the sublist
		}
	*/

  while (orig != NULL)
  {
    displayList(orig, "Original");
    subList = createSubList(&orig);
    displayList(orig, "Original");
    displayList(subList, "SubList");
    merge2Lists(&output, &subList);
    displayList(output, "Output");
  }

  printf("\n");
  displayList(output, "Final");

  printf("\n");
  freeList(&output);
  freeList(&subList);
  freeList(&orig);
  return 0;
}

List populateList(int A[], int count)
{
  int i;
  List retList, temp;
  retList = NULL;
  for (i = count - 1; i >= 0; i--)
  {
    temp = (List)malloc(sizeof(struct node));
    if (temp != NULL)
    {
      temp->elem = A[i];
      temp->link = retList;
      retList = temp;
    }
  }
  return retList;
}

List createSubList(List *A)
{

  //insertSorted

  //     List retval,temp, *trav;

  //     retval = *A;
  // 	if(*A != NULL){
  // 		*A = (*A)->link;
  // 		retval->link = NULL;

  // 		while(*A != NULL){
  // 		    if((*A)->elem < retval->elem){
  // 		        A = &(*A)->link;
  // 		    }
  // 		 	else{
  // 				for(trav = &retval; *trav!= NULL && (*A)->elem > (*trav)->elem; trav = &(*trav)->link){}
  // 				temp = *A;
  // 				*A = (*A)->link;
  // 				temp->link = *trav;
  // 				*trav = temp;
  // 			}
  // 		}
  // 	}
  // 	return retval;

  //compare last element

  List sublist, last, *trav;

  sublist = *A;
  if (sublist != NULL)
  {
    last = sublist;
    *A = (*A)->link;

    for (trav = A; *trav != NULL;)
    {
      if ((*trav)->elem > last->elem)
      {
        last = last->link = *trav;
        *trav = (*trav)->link;
      }
      else
      {
        trav = &(*trav)->link;
      }
    }
    last->link = NULL;
  }
  return sublist;
}

/* void merge2Lists(List *out, List *in) {
    List temp;

    if(*out == NULL) {
        *out = *in;
        *in = NULL;
    } else {
        while(*in != NULL) {
            if((*in)->elem < (*out)->elem) {
                temp = *out;
                *out = *in;
                *in = (*in)->link;
                (*out)->link = temp;
            } else {
                out = &(*out)->link;
            }
        }
    }
} */

void merge2Lists(List *out, List *in)
{

  //if insertSorted

  // List *trav;

  // for(trav = in; *trav != NULL; trav = &(*trav)->link){}
  //  *trav = *out;
  //  *out = *in;
  //  *in = NULL;

  //if compare last elem

  List temp;

  if (*out == NULL)
  {
    *out = *in;
    *in = NULL;
  }
  else
  {
    while (*in != NULL)
    {
      if ((*in)->elem < (*out)->elem)
      {
        temp = *out;
        *out = *in;
        *in = (*in)->link;
        (*out)->link = temp;
      }
      else
      {
        out = &(*out)->link;
      }
    }
  }
}

void displayList(List L, char msg[])
{
  printf("\n %s: \t\t", msg);
  if (L != NULL)
  {
    for (; L != NULL; L = (L)->link)
    {
      printf("%d", L->elem);
      if (L->link != NULL)
      {
        printf(" -> ");
      }
    }
  }
  else
  {
    printf("EMPTY");
  }
}

void freeList(List *A)
{
  List temp;
  while (*A != NULL)
  {
    temp = *A;
    *A = (*A)->link;
    free(temp);
  }

  (*A == NULL) ? printf("\nList Freed successfully!") : printf("\nList Freed failed");
}