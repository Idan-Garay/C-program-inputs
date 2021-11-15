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

  a = abs(a);
  b = abs(b);
  LCM = a;
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

int getScalars(int LCM, int value)
{
  // value = abs(value);

  // printf("%d, %d\n", LCM, value);
  return (LCM > value) ? LCM / value : value / LCM;
}

void findEchelonForm(Matrix A)
{
  int run, c, r, LCM;
  int scalars[3] = {1, 1, 1};

  for (r = 1; r < ROW; r++)
  {
    for (c = 0; c < r; c++)
    {
      int LCM = getLCM(A[0][c], A[r][c]);
      scalars[0] = getScalars(LCM, A[0][c]);
      scalars[r] = getScalars(LCM, A[r][c]);
      for (run = c; run < COL; run++)
      {
        A[r][run] = (scalars[0] * A[0][run]) - (scalars[r] * A[r][run]);
      }
      displayMatrix(A);
    }
  }
}

void findRRowEchelonForm(Matrix A)
{
  int run, c, r, LCM;
  int scalars[3] = {1, 1, 1};

  for (r = 1; r < ROW; r++)
  {
    for (c = 0; c < r; c++)
    {
      int LCM = getLCM(A[0][c], A[r][c]);
      scalars[0] = getScalars(LCM, A[0][c]);
      scalars[r] = getScalars(LCM, A[r][c]);
      for (run = c; run < COL; run++)
      {
        A[r][run] = (scalars[0] * A[0][run]) - (scalars[r] * A[r][run]);
      }
    }
  }

  displayMatrix(A);

  for (r = 0; r < ROW - 1; r++)
  {
    for (c = r + 1; c < COL - 1; c++)
    {
      if (A[r][c] != 0)
      {
        int LCM = getLCM(A[r + 1][c], A[r][c]);
        scalars[r + 1] = getScalars(LCM, A[r + 1][c]);
        scalars[r] = getScalars(LCM, A[r][c]);
        for (run = c; run < COL; run++)
        {
          // printf("(%d * %d) - (%d * %d) = %d\n", scalars[r], A[r][run], scalars[r + 1], A[r + 1][run], (scalars[r] * A[r][run]) - (scalars[r + 1] * A[r + 1][run]));
          A[r][run] = (scalars[r] * A[r][run]) - (scalars[r + 1] * A[r + 1][run]);
        }
      }
    }
  }

  int k;
  for (r = 0; r < ROW; r++)
  {
    k = A[r][r];
    if (k != 1)
    {
      A[r][r] /= k;
      A[r][COL - 1] /= k;
    }
  }
  displayMatrix(A);
}

int main()
{
  Matrix M = {
      {-4, 2, 6, -10},
      {2, 1, -2, 14},
      {2, -4, -2, -16}};

  findRRowEchelonForm(M);

  return 0;
}