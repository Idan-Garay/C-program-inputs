#include <stdio.h>
#include "SETCursor.h"

void displayBits(char val) {
    int bit = (sizeof(val)*8) -1;
    unsigned int masked;

    for (masked = 1 << bit; masked > 0; masked >>=1) {
        printf("%d", (masked&val? 1 : 0));
    }
}

int main() {

    SET A;
    SET B;
    
    int data[] = {1,2,3,4,5};
    int data2[] = {6,7,8,9,10,11};
    VHeap V;

    initVH(&V);
    populateCursorSet(&V, &A, data, 5);
    displayCursorSet(V, A);
    populateCursorSet(&V, &B, data2, 6);
    displayCursorSet(V, B);

    printf("UNION SET: \n");
    SET C = unionn(A, B, &V);
    displayCursorSet(V, C);

    return 0;
}

// UID

