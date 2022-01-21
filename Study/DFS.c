#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
#include "AdjMatrix.h"

void DFS(adjMatrix M, int src)
{
  int *visited = calloc(M.vertices, sizeof(int));
  Stack s;
  int x, v, flag;

  initStack(&s, M.vertices);
  push(&s, src);
  visited[src] = 1;

  while (!isEmpty(s))
  {
    v = peek(s);
    pop(&s);

    for (x = M.vertices - 1; x >= 0; x--)
    {
      if (M.matrix[v][x] == 1 && visited[x] == 0)
      {
        visited[x] = 1;
        push(&s, x);
      }
    }
    printf("%d => ", v);
  }
}

int main()
{
  // int elems[] = {0, 1, 2, 3, 4, 5, 6, 7};
  int x, n = 8;
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
  edgeList el = {edges, 8};

  initGraph(&M, el);
  printGraph(M);
  DFS(M, 0);
}