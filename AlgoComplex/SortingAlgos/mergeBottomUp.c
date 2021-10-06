#include <stdio.h>

void CopyArray(int B[], int A[], int n)
{
  int i;
    for (i = 0; i < n; i++)
        A[i] = B[i];
}

int min(int a, int b) {
  return a < b? a: b;
}

//  Left run is A[iLeft :iRight-1].
// Right run is A[iRight:iEnd-1  ].
void BottomUpMerge(int A[], int iLeft, int iRight, int iEnd, int B[])
{
  int i, j, k;
    i = iLeft, j = iRight;
    // While there are elements in the left or right runs...
    for (k = iLeft; k < iEnd; k++) {
        // If left run head exists and is <= existing right run head.
        if (i < iRight && (j >= iEnd || A[i] <= A[j])) {
            B[k] = A[i];
            i = i + 1;
        } else {
            B[k] = A[j];
            j = j + 1;    
        }
    } 
}

// array A[] has the items to sort; array B[] is a work array
void BottomUpMergeSort(int A[], int B[], int n)
{
  int width,i ;
    // Each 1-element run in A is already "sorted".
    // Make successively longer sorted runs of length 2, 4, 8, 16... until the whole array is sorted.
    for (width = 1; width < n; width = 2 * width)
    {
        // Array A is full of runs of length width.
        for (i = 0; i < n; i = i + 2 * width)
        {
            // Merge two runs: A[i:i+width-1] and A[i+width:i+2*width-1] to B[]
            // or copy A[i:n-1] to B[] ( if (i+width >= n) )
            BottomUpMerge(A, i, min(i+width, n), min(i+2*width, n), B);
        }
        // Now work array B is full of runs of length 2*width.
        // Copy array B to array A for the next iteration.
        // A more efficient implementation would swap the roles of A and B.
        CopyArray(B, A, n);
        // Now array A is full of runs of length 2*width.
    }
}

void display(int arr[], int size)
{
  int x;

  printf("\n");
  for (x = 0; x < size; x++)
  {
    printf(" %d", arr[x]);
  }
}

void test(int A[], int B[], int size)
{
  display(A, size);
  BottomUpMergeSort(A, B, size);
  display(A, size);
}


int main() {
  int arr[] = {4, 2, 8, 3, 1};  
  int arrCpy[] = {4, 2, 8, 3, 1};
  test(arr, arrCpy, 5);

}