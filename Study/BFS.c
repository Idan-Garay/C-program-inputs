#include "Queue.h"
#include <stdlib.h>
#include "AdjMatrix.h"

void BFS(adjMatrix M, int src)
{
  int *visited = calloc(M.vertices, sizeof(int));
  int v, x, y;
  Queue q;
  initQueue(&q, M.vertices);

  enqueue(&q, src);
  visited[src] = 1;

  while (!isEmpty(q))
  {
    v = front(q);
    dequeue(&q);

    for (y = 0; y < M.vertices; y++)
    {
      if (M.matrix[v][y] == 1 && visited[y] == 0)
      {
        enqueue(&q, y);
        printf("%d -> ", y);
        visited[y] = 1;
      }
    }
  }
}

int main()
{

  adjMatrix M = {NULL, 8};
  edge edges[] = {
      {0, 1},
      {0, 2},
      {0, 3},
      {1, 4},
      {1, 5},
      {2, 6},
      {2, 7},
      {3, 7},
  };
  int n = 8;
  edgeList el = {edges, n};

  initGraph(&M, el);
  printGraph(M);
  BFS(M, 0);

  return 0;
}
