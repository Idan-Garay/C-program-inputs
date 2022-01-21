#include<stdio.h>
#include<stdlib.h>
#define SIZE 7
#define base 10

typedef struct node{
	int elem;
	struct node *next;
}List, *LL;

typedef LL Bucket[base];

void display(int[]);
void initBucket(Bucket);	
void BucketSort(int*, int);
void RadixSort(int*);
int Max(int[]);


int main(void){
	int A[] = {90, 213, 7, 45, 460, 52, 167};
	RadixSort(A);
	display(A);
	return 0;	
}

int Max(int A[]){
	int i, key=0;
	for(i=0; i<SIZE; i++){
		if(A[i]>key){
			key = A[i];
		}
	}
	return key;
}

void RadixSort(int *A){
	int d = Max(A);
	int pos;
	for(pos=1; d/pos > 0; pos *= 10){
		BucketSort(&(*A), pos);
	}
}

void BucketSort(int *A, int pos){
	Bucket BL;
	int i, j, val;
	initBucket(BL);
	LL temp, *trav, ptr;
	for(i=0; i<SIZE; i++){
		val = (A[i]/pos)%10;
		for(trav = &(BL[val]); *trav !=NULL;  trav = &(*trav)->next){}
		temp = (LL) malloc (sizeof(List));
		if(temp!=NULL){
			temp->elem = A[i];
			temp->next = *trav;
			(*trav) = temp;
		}	
	}
	
	for(i=0,j=0; i<base; i++){	
		for(ptr = BL[i]; ptr!=NULL; ptr = ptr->next){
			A[j] = ptr->elem;
			j++;
			
		}
	}
}

void initBucket(Bucket BL){
	int i;
	for(i=0; i<base; i++){
		BL[i] = NULL;
	}
}

void display(int A[]){
	int i;
	for(i=0; i<SIZE; i++){
		printf("%d ",A[i]);
	}
}
