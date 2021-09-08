#include <stdio.h>

void shellSort(int arr[], int size) {
  int interval, k, j, tmp;

  interval = size;
  do {
    interval /= 2;
    
    for (k = interval; k < size; k++) {
      tmp = arr[k];
      for (j = k; j > 0 && arr[j-interval] > tmp; j -= interval)
        arr[j] = arr[j-interval];
      arr[j] = tmp;
    }

  } while (interval > 0);
}

void display(int arr[], int size) {
  int x;

  printf("\n");
  for (x = 0; x < size; x++) {
    printf(" %d ->", arr[x]);
  }
}

int main() {
  int arr[] = {9,8,3,7,5,6,4,1};
  int size = 8;

  display(arr, size);
  shellSort(arr, size);
  display(arr, size);

  return 0;
}