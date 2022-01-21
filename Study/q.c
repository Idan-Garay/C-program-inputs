#include <stdio.h>
#include "Queue.h"

int main()
{
  Queue q;
  int elems[] = {7, 3, 1, 9, 10, 4, 6, 2, 15};
  int x, n = 9;

  initQueue(&q, n);
  for (x = 0; x <= n; x++)
  {
    enqueue(&q, elems[x]);
  }

  printQueue(q);
  dequeue(&q);
  printQueue(q);
}