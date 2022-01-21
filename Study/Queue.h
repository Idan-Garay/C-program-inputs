#include <stdio.h>
#include <stdlib.h>

// circular array

// enqueue(x)
// dequeue()
// isEmpty()
// front()

typedef struct
{
  int *arr;
  int size;
  int front, tail;
} Queue;

void initQueue(Queue *q, int n)
{
  if (q != NULL)
  {
    q->size = n + 1;
    q->arr = calloc(q->size, sizeof(int));
    q->front = 0;
    q->tail = q->front - 1;
  }
}

int isFull(Queue q)
{
  return ((q.tail + 2) % q.size) == q.front;
}

int isEmpty(Queue q)
{
  return ((q.tail + 1) % q.size) == q.front;
}

void enqueue(Queue *q, int x)
{
  if (!isFull(*q))
  {
    q->arr[++q->tail] = x;
  }
}

void dequeue(Queue *q)
{
  if (!isEmpty(*q))
  {
    q->front = (q->front + 1) % q->size;
  }
}

void printQueue(Queue q)
{
  int x;

  for (x = q.front; x < q.tail; x = (x + 1) % q.size)
  {
    printf(" %d ->", q.arr[x]);
  }
  printf("\n");
}

int front(Queue q)
{
  return (!isEmpty(q) ? q.arr[q.front] : -1);
}