#include "StackCursor.h"
typedef int SET;

int main() {

    Stack S;
    int data[] = {1,2,3,4,5};
    VHeap VH;

    initCursorStack(&VH, &S);
    displayCursorStack(VH, S);
    
    populateCursorStack(&VH, &S, data, 5);
    displayCursorStack(VH, S);

    pop(&VH, &S);
    displayCursorStack(VH, S);

    push(&VH, &S, 100);
    displayCursorStack(VH, S);

    return 0;
}