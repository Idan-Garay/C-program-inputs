#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct
{
  int row;
  int col;
  int weight;
} vector;

int min(int a, int b)
{
  return a < b ? a : b;
}

void makeGraph(int N, int Matrix[][N], vector set[], int setLength)
{
  int x, r, c;

  for (r = 0; r < N; r++)
  {
    for (c = 0; c < N; c++)
    {
      Matrix[r][c] = 999;
    }
  }

  for (x = 0; x < N; x++)
  {
    Matrix[x][x] = 0;
  }

  for (x = 0; x < setLength; x++)
  {
    Matrix[set[x].row][set[x].col] = set[x].weight;
  }
}

void printGraph(int N, int Matrix[][N])
{
  int r, c;

  for (r = 0; r < N; r++)
  {
    printf("%d:", r);
    for (c = 0; c < N; c++)
    {
      printf("%5d ", Matrix[r][c]);
    }
    printf("\n");
  }
}

typedef struct
{
  int row;
  int col;
  int weight;
} edge;

#define MAX_EDGE 20

typedef struct
{
  edge edges[MAX_EDGE];
  int count;
} edgeList;

#define INF 999

void initFWMatrix(int V, int M[][V], edgeList L)
{
  int r, c, k;
  edge e;

  for (r = 0; r < V; r++)
    for (c = 0; c < V; c++)
      M[r][c] = r == c ? 0 : 999;

  for (k = 0; k < L.count; k++)
  {
    e = L.edges[k];
    M[e.row][e.col] = e.weight;
  }
}

void floydWarshall(int V, edgeList L)
{
  int dist[V][V], i, j, k;
  edge e;

  initFWMatrix(V, dist, L);
  for (k = 0; k < V; k++)
  {
    for (i = 0; i < V; i++)
    {
      for (j = 0; j < V; j++)
      {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }

  printGraph(V, dist);
}

void floydWarshall(int V, edgeList L)
{
  int dist[V][V], i, j, k;
  edge e;

  initFWMatrix(V, dist, L);
  for (k = 0; k < V; k++)
  {
    for (i = 0; i < V; i++)
    {
      for (j = 0; j < V; j++)
      {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }

  printGraph(V, dist);
}

void floydWarshallR(int V, edgeList L)
{
  int dist[V][V], i, j, k;
  edge e;

  initFWMatrix(V, dist, L);
  for (k = 0; k < V; k++)
  {
    for (i = 0; i < V; i++)
    {
      for (j = 0; j < V; j++)
      {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }

  printGraph(V, dist);
}

int shortestPathR(int i, int j, int k, int V, int M[][V])
{
  if (k == 0)
  {
    if (i == j)
      return 0;
    return M[i][j];
  }
  return min(shortestPathR(i, j, k - 1, V, M), shortestPathR(k, j, k - 1, V, M));
}

void shortestPath(int N, int Matrix[][N])
{
  int k, i, j;

  for (k = 0; k < N; k++)
  {
    for (i = 0; i < N; i++)
    {
      for (j = 0; j < N; j++)
      {
        Matrix[i][j] = min(Matrix[i][j], Matrix[i][k] + Matrix[k][j]);
      }
    }
  }
}

// void recursiveFW(int i, int j, int k, int W[][N])
// {
//   if (k == 0)
//   {
//     if (i == j)
//       return 0;
//     return W[i][j];
//   }
//   return min(recursiveFW(i, j, k - 1, W), recursiveFW(i, k, k - 1, W) + recursiveFW(k, j, k - 1, W));
// }

int main()
{
  vector Set[] = {
      {1, 0, 4},
      {0, 2, -2},
      {2, 3, 2},
      {3, 1, -1},
      {1, 2, 3},
  };

  edgeList L = {{
                    {1, 0, 4},
                    {0, 2, -2},
                    {2, 3, 2},
                    {3, 1, -1},
                    {1, 2, 3},
                },
                5};
  // int Matrix[4][4];
  floydWarshall(4, L);
  // printGraph(4, Matrix);

  printf("\n\n");
  // makeGraph(4, Matrix, Set, 5);
  // printGraph(4, Matrix);
  printf("\n\n");
  // shortestPath(4, Matrix);
  // printGraph(4, Matrix);

  return 0;
}

// let dist be a |V| × |V| array of minimum distances initialized to ∞ (infinity)
// for each edge (u, v) do
//     dist[u][v] ← w(u, v)  // The weight of the edge (u, v)
// for each vertex v do
//     dist[v][v] ← 0
// for k from 1 to |V|
//     for i from 1 to |V|
//         for j from 1 to |V|
//             if dist[i][j] > dist[i][k] + dist[k][j]
//                 dist[i][j] ← dist[i][k] + dist[k][j]
//             end if
