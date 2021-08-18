#include "QueueCursor.h"

int main() {
    Queue Q;
    VHeap VH;
    int data[] = {1,2,3,4,5,6};

    initCursorQueue(&VH, &Q);

    populateCursorQueue(&VH, &Q, data, 6);
    displayCursorQueue(VH, Q);

    enqueue(&VH, &Q, 100);
    displayCursorQueue(VH, Q);

    dequeue(&VH, &Q);
    displayCursorQueue(VH, Q);

    return 0;
}