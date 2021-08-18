#include "StackArray.h"
typedef int SET;

int main() {

    Stack S;
    int data[] = {1,2,3,4,5};
    
    populateStack(&S, data, 5);
    displayStack(S);

    pop(&S);
    displayStack(S);

    push(&S, 100);
    displayStack(S);

    return 0;
}