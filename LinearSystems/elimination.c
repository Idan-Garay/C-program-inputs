#include <stdio.h>
#include <stdlib.h>
#define ROW 3
#define COL 4

typedef int Matrix[ROW][COL]; //systems of linear equations with 3 unknowns with integral solution set.

void displayMatrix(Matrix M)
{
  int c, r;
  printf("Matrix:\n");
  for (r = 0; r < ROW; r++)
  {
    for (c = 0; c < COL - 1; c++)
    {
      printf("%5d", M[r][c]);
    }

    printf("   : %d\n", M[r][c]);
  }
}

int getLCM(int a, int b)
{
  int LCM;

  if (a < b)
  {
    LCM = b;
    b = a;
    a = LCM;
  }

  while (LCM % b != 0)
  {
    LCM += a;
  }

  return LCM;
}

void swapRow(Matrix A, int rX, int rY)
{
  int x, len, tmp;

  len = sizeof(A[rX]) / sizeof(int);

  for (x = 0; x < len; x++)
  {
    tmp = A[rX][x];
    A[rX][x] = A[rY][x];
    A[rY][x] = tmp;
  }
}

void findEchelonForm(Matrix A)
{
  int c, r, allZeroes, nr = ROW - 1, x;

  for (r = 0; r < nr; r++)
  {
    allZeroes = 1;
    for (c = 0; c < COL && allZeroes != 0; c++)
    {
      if (A[r][c] != 0)
      {
        allZeroes = 0;
      }
    }
    if (allZeroes == 1)
    {
      swapRow(A, r, nr--);
    }
  }

  int p = 0;

  while (p < nr && p < COL)
  {
  nextPivot:
    r = 1;
    while (A[p][r] == 0)
    {
      if (p + r <= nr)
      {
        p += 1;
        goto nextPivot;
      }
      swapRow(A, p, p + r);
      r += 1;
    }
    for (r = 1; r < nr - p; r++)
    {
      if (A[p + r][p] != 0)
      {
        x = -A[p + r][p] / A[p][p];
        for (c = p; c < COL; c++)
        {
          A[p + r][c] = A[p][c] * x + A[p + r][c];
        }
      }
    }
  }
  p += 1;
}

int main()
{
  Matrix M = {
      {-4, 2, 6, -10},
      {2, 1, -2, 14},
      {2, -4, -2, -16},
  };

  // displayMatrix(M);
  findEchelonForm(M);
  // displayMatrix(M);

  return 0;
}