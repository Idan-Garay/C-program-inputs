#include "POT.h"

int main() {
    Heap H;
    int data[] = {3,5,9,6,8,9,10,10,18,9};

    initHeap(&H);
    
    populateHeap(&H, data, 10);
    displayHeap(H);

    printf("\nremoved element: %d", removal(&H));
    displayHeap(H);
}