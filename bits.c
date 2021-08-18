#include <stdio.h>
#include "SETList.h"

void displayBits(char val) {
    int bit = (sizeof(val)*8) -1;
    unsigned int masked;

    for (masked = 1 << bit; masked > 0; masked >>=1) {
        printf("%d", (masked&val? 1 : 0));
    }
}

int main() {

    SET A = NULL;
    SET B = NULL;
    
    int data[] = {23,34,61,1,0,25};
    int data2[] = {1,2,3,4,5};

    populateSetList(&A, data, 6);
    displayList(A);
    populateSetList(&B, data2, 5);
    displayList(B);

    SET C = unionList(&A, &B);
    displayList(C);

    return 0;
}

// UID

