#include <stdio.h>
#include <stdlib.h>
/*#include "stackArray.h"*/
#include "stackLink.h"

/*After the driver program is ran, the line 15 and line 18 
  will produce error because the function is only intended
  for stackArray.h header and there's no elems with brackets
  or an array of characters called elems in stackLink.h 
  but a character datatype instead.*/

/*for ArrayStack only*/
void insertBottom(StackPtr sPtr, elemType elem) {
    if (!isFull(*sPtr)) {
        Stack temp;
        initStack(&temp);
        //get stack 1 elems to stack 2
        for ( ; !isEmpty(*sPtr); pop(sPtr)){
            push(&temp, sPtr->elems[sPtr->count-1]);
        } 
        push(&temp, elem);
        
        for (; !isEmpty(temp); pop (&temp)) {
            push(sPtr, temp.elems[temp.count-1]);
        };
    }   
}

int main() {
    Stack stack;

    printf("Problem 1 :\n");
    initStack(&stack);
    printf(" %d\n", isEmpty(stack));
    
    printf("Problem 2 :\n");
    int i;
    char elements[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    
    for (i = 0; i < 8; i++) {
        push(&stack, elements[i]);
    }
    displayStack(stack);

    printf("Problem 3 :\n");
    printf(" %d\n", isFull(stack));

    printf("Problem 4 :\n");
    for (i = 0; i < 3; i++) {
        pop(&stack);
    }
    displayStack(stack);

    printf("Problem 5 :\n");
    insertBottom(&stack, 'Z');
    insertBottom(&stack, 'X');
    displayStack(stack);

    printf("Problem 6 :\n");
    printf(" %c\n", top(&stack));
    return 0;
}