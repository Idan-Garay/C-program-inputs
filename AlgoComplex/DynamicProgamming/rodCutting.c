#include <stdio.h>

#include <stdlib.h>

#include <limits.h>

int max(int a, int b) {
  return (a > b) ? a : b;
}

int cutRod(int A[], int n) {
  int q, i;

  if (n == 0)
    return 0;

  q = INT_MIN; // recursive: be thrifty with operations
  for (i = 0; i < n; i++) {
    q = max(q, A[i] + cutRod(A, n - i - 1));
  }
  
  return q;
}

// int memoized_cut_rod_aux(int A[], int n, int B[]) {
//   int result;

//   if (B[n - 1] >= 0) {
//     return B[n - 1];
//   } else if (n == 0) {
//     result = 0;
//   } else {
//     int x;

//     result = INT_MIN;
//     for (x = 0; x < n; x++) {
//       result = max(result, A[x] + memoized_cut_rod_aux(A, n - x - 1, B));
//     }
//   }
//   B[n - 1] = result;

//   return result;
// }

int bottom_up_cut_rod(int A[], int n) {
  int result, i, j, B[n + 1];

  B[0] = 0;
  for (j = 1; j <= n; j++) {
    result = INT_MIN;
    for (i = 0; i < j; i++) {
      result = max(result, A[i] + B[j - i - 1]);
    }
    B[j] = result;
  }
  return B[n];
}

// int memoized_cut_rod(int A[], int n) {
//   int i;
//   int B[n];

//   for (i = 0; i < n; i++) {
//     B[i] = INT_MIN;
//   }
//   return memoized_cut_rod_aux(A, n, B);
// }

int main() {
  int arr[] = {
    1,
    5,
    8,
    9,
    10,
    17,
    17,
    20
  };
  int size = 8;

  printf("Maximum Obtainable Value is %d\n", bottom_up_cut_rod(arr, size));
  printf("Maximum Obtainable Value is %d", cutRod(arr, size));
  return 0;
}