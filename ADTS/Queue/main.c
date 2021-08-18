#include "QueueArray.h"

int main() {
    Queue Q;
    int data[] = {1,2,3,4,5,6};

    initQueue(&Q);
    populateQueue(&Q, data, 6);
    displayQueue(Q);

    return 0;
}