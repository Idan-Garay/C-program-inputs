typedef struct
{
  int **matrix;
  int vertices;
} adjMatrix;

typedef struct
{
  int x;
  int y;
} edge;

typedef struct
{
  edge *edges;
  int n;
} edgeList;

void initGraph(adjMatrix *M, edgeList e)
{
  int x;
  edge z;

  M->matrix = (int **)calloc(M->vertices, sizeof(int *));
  for (x = 0; x < M->vertices; x++)
  {
    M->matrix[x] = (int *)calloc(M->vertices, sizeof(int));
  }

  for (x = 0; x < e.n; x++)
  {
    z = e.edges[x];
    M->matrix[z.x][z.y] = 1;
    M->matrix[z.y][z.x] = 1;
  }
}

void printGraph(adjMatrix M)
{
  int x, y;

  for (x = 0; x < M.vertices; x++)
  {
    // printf("%d", x);
    for (y = 0; y < M.vertices; y++)
    {
      // if (y == 0)
      // {
      //   printf("\t%d", x);
      // }
      printf("%d\t", M.matrix[x][y]);
    }
    printf("\n");
  }
}