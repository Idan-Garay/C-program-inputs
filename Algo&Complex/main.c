#include <stdio.h>

int **findTranspose(int row, int col, int **A)
{
  int **B = (int **)calloc(col, sizeof(int *));

  if (B != NULL)
  {
    int x, y;

    for (x = 0; x < col; x++)
      B[x] = (int *)calloc(row, sizeof(int));

    for (x = 0; x < row; x++)
    {
      for (y = 0; y < col; y++)
      {
        B[y][x] = A[x][y];
      }
    }
  }

  return B;
}

void display2D(int row, int col, int A[row][col])
{
  int x, y;

  printf("\n");
  for (y = 0; y < row; y++)
  {
    for (x = 0; x < col; x++)
    {
      printf(" %d,", A[y][x]);
    }
    printf("\n");
  }
}

int main()
{
  int A[][3] = {{0, 1, -1},
                {4, -7, 3}};
  int **C = findTranspose(2, 3, A);
  display2D(3, 2, C);
  
  return 0;
}