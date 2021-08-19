#include <stdio.h>
// Heap is an array implementation of POT
#define MAX 100

typedef struct {
    int elems[MAX];
    int lastNdx;
}Heap;

void initHeap(Heap *H) {
    H->lastNdx = -1;
}

void insert(Heap *H, int data) {
    if (H->lastNdx < MAX-1) {
        int p, c, tmp;

        c = ++H->lastNdx;
        H->elems[c] = data;
        p = (c-1)/2;
        while (c > 0 && H->elems[c] < H->elems[p]) {
            tmp = H->elems[p];
            H->elems[p] = H->elems[c];
            H->elems[c] = tmp;
            c = p;
            p = (c-1)/2;
        }
    } 
}

int removal(Heap *H) {
    int retVal = -1;
    if (H->lastNdx != -1) {
        int p, c, smallest;

        p = 0;
        retVal = H->elems[p];
        for (c = (p*2)+1; c <= H->lastNdx;) {
            smallest = c;
            
            if (c+1 <= H->lastNdx) {
                smallest = H->elems[c+1] < H->elems[smallest] ? c+1 : smallest;
            } 

            H->elems[p] = H->elems[smallest];
            p = smallest;
            c = (p*2)+1;
        }
        --H->lastNdx;
    }

    return retVal;
}

void populateHeap(Heap *H, int data[], int dataSize) {
    int x;

    for (x = 0; x < dataSize; x++) {
        insert(H, data[x]);
    }
};

void displayHeap(Heap H) {
    int x;

    printf("\n");
    for (x = 0; x <= H.lastNdx; x++) {
        printf(" %d ->", H.elems[x]);
    }
}