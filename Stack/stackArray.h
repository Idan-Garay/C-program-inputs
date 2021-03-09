/*Stack Array by Idan Joshua T. Garay, finished on 9/21/20.
  This is a header file that contains the stack operation
  for array implementation of Stack*/
  
#ifndef STACK_H
#define STACK_H
#endif

#define Max 8
#define dummy '0'

typedef char elemType;

typedef struct stack {
    elemType elems[Max];
    int count;
} Stack, *StackPtr;

void push (StackPtr S, elemType elem);
void pop (StackPtr S);
elemType top (StackPtr S);
void initStack (StackPtr S);
int isEmpty (Stack S);
int isFull (Stack S);
void displayStack (Stack S);

void push (StackPtr S, elemType elem) {
    if (!isFull(*S)) {
        S->elems[S->count++] = elem;
    } else {
        printf("Stack is full.\n");
    }
}

void pop (StackPtr S) {
    if (!isEmpty(*S)) {
        S->count--;
    } else {
        printf("Stack is already empty.\n");
    }
}

elemType top (StackPtr S) {
    return (isEmpty(*S))? dummy: S->elems[S->count-1];
}

void initStack (StackPtr S) {
    S->count = 0;
}

int isEmpty (Stack S) {
    return (S.count == 0)? 1: 0;
}

int isFull (Stack S) {
    return (S.count == Max)? 1: 0;
}

void displayStack (Stack S) {
    if (!isEmpty (S)) {
        int i;
        for (i = S.count-1; i >= 0; i--) {
            printf(" %c ->", S.elems[i]);
            pop (&S);
        }
        printf("\n");
    }
}