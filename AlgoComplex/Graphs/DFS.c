#include <stdio.h>
#include "Queue.h"

int main()
{
  int elem[] = {1, 2, 3, 4, 5, 6, 7};
  int v = 7;

  Queue *Q = makeQueue(elem, v);
  printQueue(*Q);

  return 0;
}