#include <stdio.h>

int binarySearch2(int A[], int lo, int hi, int val) {

  if (lo < hi) {
    int mid = (hi+ lo) / 2;

    if (A[mid] == val)    
      return val;
    if (A[mid] > val) 
      return binarySearch2(A, lo, mid-1, val);
    return binarySearch2(A, mid+1, hi, val);
  }
  return -1;
}

int binarySearch(int A[], int size, int val) {

  int lo, hi, mid;

  lo = 0;
  hi = size-1;

  while (lo <= hi) {
    mid = (hi+lo)/2;
    if (A[mid] == val)
      return val;
    if (A[mid] > val)
      hi = mid-1;
    if (A[mid] < val)
      lo = mid+1;
  }
  return -1;
}

int main() {
  int arr[] = {1, 2, 3, 4, 8};

  printf("Search: %d", binarySearch(arr, 5, 4));

  return 0;
}