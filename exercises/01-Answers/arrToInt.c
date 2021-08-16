#include <stdio.h>
#include <stdlib.h>

int convertArrToInt(int arr[], int arrSize) {
    int retVal = -1;

    if (arrSize > 1) {
        int x = 0;
        retVal = arr[0];

        for (x = 1; x < arrSize; x++) {
            retVal *= 10;
            retVal += arr[x] ;
        }
    }

    return retVal;
}

int main() {
    int arr[5] = {5,2,1,3,0};

    printf("%d", convertArrToInt(arr, 5));

    return 0;
}