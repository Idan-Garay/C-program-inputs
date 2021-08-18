#include <stdio.h>
#define MAX 100

typedef struct node {
    int elem;
    int link;
}stype, HeapSpace[MAX];

typedef struct {
    HeapSpace H;
    int avail;
} VHeap;

typedef int SET;

SET unionn(SET A, SET B, VHeap *VH) {
    SET C, *trav;

    C = -1;
    trav = &C;
    while (A != -1 && B != -1) {
        *trav = VH->avail;
        if (VH->H[A].elem < VH->H[B].elem) {
            if (*trav != -1) {
                VH->avail = VH->H[*trav].link;
                VH->H[*trav].elem = VH->H[A].elem;
                VH->H[*trav].link = -1;
            }
            A = VH->H[A].link;
        } else {
            if (VH->H[A].elem == VH->H[B].elem) 
                A = VH->H[A].link;
            if (*trav != -1) {
                VH->avail = VH->H[VH->avail].link;
                VH->H[*trav].elem = VH->H[B].elem;
                VH->H[*trav].link = -1;
            }
            B = VH->H[B].link;
        }
        trav = &VH->H[*trav].link;
    }

    if (B != -1) {
        A = B;
    }

    while (A != -1) {
        *trav = VH->avail;
        if (*trav != -1) {
            VH->avail = VH->H[VH->avail].link;
            VH->H[*trav].elem = VH->H[A].elem;
            VH->H[*trav].link = -1;
            trav = &VH->H[*trav].link;
        }
        A = VH->H[A].link;
    }
    return C;
}

void displayCursorSet(VHeap VH, SET S) {
    while(S != -1) {
        printf("\n[%d] %d - %d", S, VH.H[S].elem, VH.H[S].link);
        S = VH.H[S].link;
    }
}

void initVH(VHeap *VH) {
    int x;

    for (x = 0; x < MAX; x++) {
        VH->H[x].link = x+1;
    }
    VH->avail = 0;
    VH->H[x].link = -1;
}

void populateCursorSet(VHeap *VH, SET *S, int data[], int dataSize) {
    int x;
    int memSpace = -1;

    for (x = 0; x < dataSize; x++) {
        memSpace = VH->avail;
        if (memSpace != -1) {
            VH->avail = VH->H[VH->avail].link;
            VH->H[memSpace].elem = data[x];
            VH->H[memSpace].link = -1;
            *S = memSpace;
            S = &VH->H[memSpace].link;
        }
    }
}