#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
  int *buffer;
  int front, tail;
  int size;
} Queue;

void initQueue(Queue *Q, int size)
{
  Q->front = 0;
  Q->tail = -1;
  Q->buffer = calloc(size, sizeof(int));
  Q->size = size;
}

int isFull(Queue Q)
{
  return Q.tail == Q.size - 1;
}

int isEmpty(Queue Q)
{
  return Q.tail == Q.front + 1;
}

void enqueue(Queue *Q, int node)
{
  if (!isFull(*Q))
  {

    Q->buffer[++Q->tail] = node;
  }
}

void dequeue(Queue *Q)
{
  if (!isEmpty(*Q))
  {
    Q->front = (Q->front + 1) % Q->size;
  }
}

void printQueue(Queue Q)
{
  Queue tmp;
  memcpy(&tmp, &Q, sizeof(Queue));

  while (!isEmpty(tmp))
  {
    printf("%d -> ", tmp.buffer[tmp.front]);
    dequeue(&tmp);
  }
}

Queue *makeQueue(int elems[], int size)
{
  Queue *tmp = calloc(1, sizeof(Queue));
  int x = 0;

  initQueue(tmp, size);
  while (!isFull(*tmp))
  {
    enqueue(tmp, elems[x++]);
  }

  return tmp;
}