#include <stdio.h>
#include <stdlib.h>

int arrToInt(int arr[], int size) {
    int val, pow, x;

    val = 0;
    x = size-1;
    pow = 1;
    do {
        val += arr[x] * pow;
        pow *= 10;
        x--;
    } while (x >= 0);

    return val;
}

int main() {
    int *arr, size;

    scanf("%d", &size);
    arr = (int*) malloc(size * sizeof(int));

    if (arr != NULL) {
        int x = 0;

        for (x = 0; x < size; x++) {
            scanf("%d", arr+x);
        }
        printf("%d", arrToInt(arr, size));
    }
    free (arr);
    
    return 0;
}