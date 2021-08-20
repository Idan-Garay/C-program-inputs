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
        int p, c;

        c = ++H->lastNdx;
        p = (c-1)/2;
        while (c > 0 && data < H->elems[p]) {
            H->elems[c] = H->elems[p];
            c = p;
            p = (c-1)/2;
        }
        H->elems[c] = data;
    }
}

int removal (Heap *H) {
	int min = -1;

	if (H->lastNdx != -1) {
		int c, p, tmp;

        p = 0;
        min = H->elems[p];
        tmp = H->elems[H->lastNdx--];
        for (c = p*2+1; c <= H->lastNdx; c = p*2+1) {
            if (c+1 <= H->lastNdx && H->elems[c+1] < H->elems[c])
                c += 1;
            if (tmp > H->elems[c]) {
                H->elems[p] = H->elems[c];
                p = c;
            } else {
                break;
            }
        }
        H->elems[p] = tmp;
	}
	return min;
}


void minHeapify(Heap *H) {
    int p, c, swap, lastNdx;

    if (H->lastNdx != -1) {
        lastNdx = (H->lastNdx-1)/2;
        while(lastNdx >= 0) {
            p = lastNdx;
            c = p*2+1;
            if (c+1 <= H->lastNdx && H->elems[c+1] < H->elems[c]) 
                c += 1;
                
            if (H->elems[c] < H->elems[p]) {
                swap = H->elems[c];
                H->elems[c] = H->elems[p];
                H->elems[p] = swap;
            }
            lastNdx--;
        }
    }
}

void HeapSort(Heap *H) {
    int min;
    int p, c, swap, orig;

    orig = H->lastNdx;
    // 2.
    while (H->lastNdx != -1) {
        p = 0;
        min = H->elems[p];
        H->elems[p] = H->elems[H->lastNdx--];

        for (c = p*2+1; c <= H->lastNdx; c = p*2+1) {
            if (c+1 <= H->lastNdx && H->elems[c+1] < H->elems[c])
                c += 1;

            if (H->elems[c] < H->elems[p]) {
                swap = H->elems[c];
                H->elems[c] = H->elems[p];
                H->elems[p] = swap;
                p = c;
            } else {
                break;
            }
        }
        H->elems[H->lastNdx+1] = min;
    }
    H->lastNdx = orig;
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