#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  int *arr;
  int size;
  int top;
} Stack;

void initStack(Stack *s, int n)
{
  s->arr = calloc(n, sizeof(int));
  s->top = -1;
  s->size = n;
}

int isFull(Stack s)
{
  return s.top == s.size - 1;
}

int isEmpty(Stack s)
{
  return s.top == -1;
}

int peek(Stack s)
{
  return s.arr[s.top];
}

void push(Stack *s, int x)
{
  if (!isFull(*s))
  {
    s->arr[++s->top] = x;
  }
}

void pop(Stack *s)
{
  if (!isEmpty(*s))
  {
    s->top--;
  }
}

void printStack(Stack s)
{
  int x;

  for (x = 0; x <= s.top; x++)
  {
    printf("%d -> ", s.arr[x]);
  }
  printf("\n");
}