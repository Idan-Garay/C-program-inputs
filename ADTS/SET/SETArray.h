#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct {
    int arr[MAX];
    int count;
} SET;
//UID funcs that returns a set

void displaySet(SET A) {
    int x;

    for ( x = 0; x < A.count; x++) {
        printf(" %d, ", A.arr[x]);
    }
    printf("\n");
}

void sortSet(SET *A) {
    int k, j;
    int largest;
    int tmp;
    // {3,0,55,1}
    for (k = A->count-1; k > 0; k--) {
        largest = k;
        for (j = k-1; j >= 0; j--) {
            if (A->arr[j] > A->arr[largest]) {
                largest = j;
            }
        }
        tmp = A->arr[largest];
        A->arr[largest] = A->arr[k];
        A->arr[k] = tmp;
    }
    displaySet(*A);
}

SET unionn(SET A, SET B) { // A & B are in ascending order.
    SET C = {{}, 0};
    int x, y;
    x = y = 0;

    while (x < A.count && y < B.count) {
        if (A.arr[x] < B.arr[y]) {
            C.arr[C.count] = A.arr[x];
            x++;
        } else {
            if (A.arr[x] == B.arr[y]) {
                x++;
            }
            C.arr[C.count] = B.arr[y];
            y++;
        }
        C.count++;
    }

    if (y < B.count) {
        x = y;
        A = B;
    }

    while  (x < A.count) {
        C.arr[C.count++] = A.arr[x++];
    }
    return C;
}