#include "POT.h"

int main() {
    Heap H;
    int data[] = {5,4,8,25,1,8};

    initHeap(&H);
    
    populateHeap(&H, data, 6);
    displayHeap(H);

    HeapSort(&H);
    displayHeap(H);

    minHeapify(&H);
    displayHeap(H);

    printf("\n removed element: %d", removal(&H));
    // removal(&H);
    displayHeap(H);
}