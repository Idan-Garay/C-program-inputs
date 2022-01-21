#include <stdio.h>
#define SIZE 15

typedef struct {
	int elem[SIZE];
	int lastNdx;
}ListHeap;

int deleteMax(ListHeap *H);
void display(ListHeap H);
void HeapSort(ListHeap *H);
void maxHeapify(ListHeap *H);
void subHeapify(ListHeap *H, int index);
void maxHeapifyV2(ListHeap *H);
void subHeapifyV2(ListHeap *H, int index);

int main(void)
{
	ListHeap L = {{6,3,7,4,10,1,20,12,3,13,6,9,4,19,5},14};
	display(L);
	HeapSort(&L);
	display(L);
	return 0;
}

int deleteMax(ListHeap *H)
{
	int ret;
	if(H->lastNdx>-1){
		ret=H->elem[0];
		H->elem[0]=H->elem[H->lastNdx];
		H->lastNdx--;
		subHeapify(H,0);
		return ret;
	}
}

void display(ListHeap H)
{
	int x;
	printf("\n");
	for(x=0;x<=H.lastNdx;x++){
		printf("%d,",H.elem[x]);
	}
}

void HeapSort(ListHeap *H)
{
	int ctr,temp;
	temp=H->lastNdx;
	maxHeapify(H);
	display(*H);
	for(ctr=temp;ctr>=0;ctr--){
		H->elem[ctr]=deleteMax(H);
	}
	H->lastNdx=temp;
}

void maxHeapify(ListHeap *H)
{
	int x;
	for(x=(H->lastNdx-1)/2;x>=0;x--){
		subHeapify(H,x);
	}
}

void subHeapify(ListHeap *H, int index)
{
	int parent,child,temp;
	if(H->lastNdx>-1){
		parent=index;
		child=parent*2+1;
		while(child<=H->lastNdx){
			if(child+1<=H->lastNdx && H->elem[child+1]>H->elem[child]){
				child++;
			}
			if(H->elem[parent]<H->elem[child]){
				temp=H->elem[parent];
				H->elem[parent]=H->elem[child];
				H->elem[child]=temp;
				parent=child;
				child=parent*2+1;
			}else{
				child=H->lastNdx+1;
			}
		}
	}
}
