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

int removal2(Heap *H) {
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

int removal (Heap *H) {
	int min = -1;

	if (H->lastNdx != -1) {
		int c, p, swap;
		
		p = 0;
		min = H->elems[p];
		H->elems[p] = H->elems[H->lastNdx--];
		for (c = p*2+1; c <= H->lastNdx;c = p*2+1) {
			if (c+1 <= H->lastNdx && H->elems[c] > H->elems[c+1])
				c += 1;
			if (H->elems[p] > H->elems[c]) {
                swap = H->elems[p];
                H->elems[p] = H->elems[c];
                H->elems[c] = swap;
                p = c;
            } else {
                break;
            }
		}
	}
	return min;
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