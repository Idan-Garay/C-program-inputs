/*Stack Link by Denzel John Lawas, finished on 9/21/20.
  This is a header file that contains the stack operation
  for link implementation of Stack*/

#ifndef STACK_H
#define STACK_H
#endif

#define Max 10
#define dummy -1

typedef char elemType;

typedef struct node {
    elemType elems;
    struct node* next;
}*nodePtr;

typedef struct {
    nodePtr nodePtr;
    int count;
} Stack, *StackPtr;

void push(StackPtr, elemType);
void pop(StackPtr);
elemType top(StackPtr);
void initStack(StackPtr);
int isEmpty(Stack);
int isFull(Stack);
void displayStack(Stack);

void push (StackPtr S, elemType elem) 
{
    if (isFull(*S)) {
        printf("Stack is already FULL.\n");
    } else {
        nodePtr temp = (nodePtr) malloc(sizeof(struct node));
        if (temp != NULL) {
            temp->elems = elem;
            temp->next = S->nodePtr;
            S->nodePtr = temp;
            S->count++;
        }
    } 
}

void pop (StackPtr S) 
{
    if (isEmpty(*S)) {
        printf("Stack is empty.\n");
    } else {
        nodePtr delNode = S->nodePtr;
        S->nodePtr = delNode->next;
        free (delNode);
        S->count--;
    }
}


elemType top (StackPtr S) 
{
    elemType val = dummy;
    if(!isEmpty(*S)) {
        val = S->nodePtr->elems;
    }
    return val;
}

void initStack (StackPtr S) {
    S->count = 0;
    S->nodePtr = NULL;
}

int isEmpty (Stack S) 
{
    return (S.count == 0)? 1: 0;
}

int isFull (Stack S) 
{
    return (S.count == Max)? 1: 0;
}

void displayStack(Stack S) {
    Stack temp;
    nodePtr trav;
    int i, len = S.count;
    
    initStack(&temp);  
    for (trav = S.nodePtr; trav != NULL; trav = trav->next) {
        push(&temp, trav->elems);
    }

    while (!isEmpty(temp)) {
        printf(" %c ->", temp.nodePtr->elems);
        pop(&temp);
    }
    printf("\n");
}
