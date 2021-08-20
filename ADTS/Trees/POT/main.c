#include "POT.h"

int main() {
    Heap H;
    int data[] = {5,4,8,25,1,8,2};

    initHeap(&H);
    
    populateHeap(&H, data, 6);
    displayHeap(H);

    HeapSort(&H);
    displayHeap(H);
}