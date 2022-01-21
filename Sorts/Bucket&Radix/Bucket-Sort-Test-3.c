#include<stdio.h>
#include<stdlib.h>
#define SIZEARR 10
typedef struct node {
	float elem;
	struct node* link;
}*List, nodeBody;

void insertSorted (List*, float);
void bucketSort (float[]);
List insertionSort (List);
List selectionSort (List);
int getBucketIndex (float);
int main (void)
{
	float unsorted[SIZEARR] = {110, 255.8, 22.3, 439.9, 612.7, 825.99, 386.27, 14.54, 0.43, 4.78};
	bucketSort(unsorted);
	return 0;
}

void bucketSort (float uArr[])
{
	//variable declaration
	int i,j;
	List sortingArray[SIZEARR], temp;
	

	
	//Initialization of buckets
	for(i=0; i<SIZEARR; i++){
		sortingArray[i] = NULL;
	}
	
	//Inserting the elements into the Bucket 
	for(i=0; i<SIZEARR; i++){
		int index = getBucketIndex(uArr[i]);
		temp = (List) malloc (sizeof(nodeBody));
		if(temp!=NULL){
			temp->elem = uArr[i];
			temp->link = sortingArray[index];
			sortingArray[index] = temp; 
		}
	}
	
	//Inserting Elements sorted already into the bucket
	/*for(i=0; i<SIZEARR; i++){
		int index = getBucketIndex(uArr[i]);
		insertSorted(&(sortingArray[index]), uArr[i]);
	}*/
	
	//Prints the sorted bucket
	List trav;
	for(i=0; i<SIZEARR; i++){
		if(sortingArray[i]!=NULL){
			printf("[%d]\t-->\t", i);
			for(trav = sortingArray[i]; trav!=NULL; trav = trav->link){
				printf("%.2f\t", trav->elem);
			}
		}
		printf("\n");
	}
	
	//Insertion Sort/Selection Sort (Sorting the elements)
	for(i=0; i<SIZEARR; i++){
		//sortingArray[i] = insertionSort(sortingArray[i]);
		sortingArray[i] = selectionSort(sortingArray[i]);
	}
	
	//Insert Elements back into Array
	for(i=0, j=0; i<SIZEARR;i++){
		if(sortingArray[i]!=NULL){
			for(trav = sortingArray[i]; trav!=NULL; trav = trav->link){
				uArr[j] = trav->elem;
				j++;
			}
		}
	}

	//Print the elements in the array
	for(i=0; i<SIZEARR; i++){
		printf("[%d] - %.2f \n", i, uArr[i]);
	}
	
		
}

int getBucketIndex (float element)
{
	return element / 100;
}

List insertionSort (List sortArr)
{
	List k, nodeList;
  if (sortArr == 0 || sortArr->link == 0) {
    return sortArr;
  }

  nodeList = sortArr;
  k = sortArr->link;
  nodeList->link = 0;
  while (k != 0) {
    List ptr;
    if(nodeList->elem > k->elem) {
      List tmp;
      tmp = k;
      k = k->link;
      tmp->link = nodeList;
      nodeList = tmp;
      continue;
    }

    for (ptr = nodeList; ptr->link != 0; ptr = ptr->link) {
      if (ptr->link->elem > k->elem)
        break;
    }

    if (ptr->link != 0) {
      List tmp;
      tmp = k;
      k = k->link;
      tmp->link = ptr->link;
      ptr->link = tmp;
      continue;
    } else {
      ptr->link = k;
      k = k->link;
      ptr->link->link = 0;
      continue;
    }
  }
  return nodeList;
}

List selectionSort (List sortArr)
{
	List trav1, trav2, SE, CE;
	int thirdParty;
	if(sortArr!=NULL){	
		for(trav1 = sortArr; trav1!=NULL; trav1 = trav1->link){
			SE = CE = trav1;
			for(trav2= trav1->link; trav2!=NULL; trav2 = trav2->link){
				if(SE->elem > trav2->elem){
					SE = trav2;
				}
			}
			if(SE!=CE){
				thirdParty = CE->elem;
				CE->elem = SE->elem;
				SE->elem = thirdParty;
			}
		}	
	}
	return sortArr;
}

void insertSorted (List *L, float elem)
{
	List* trav;
	List temp;
	for(trav = L; *trav!=NULL && elem > (*trav)->elem; trav = &(*trav)->link){}
	temp = (List) malloc (sizeof(nodeBody));
	if(temp!=NULL){
		temp->elem = elem;
		temp->link = *trav;
		*trav = temp;
	}
	
}
