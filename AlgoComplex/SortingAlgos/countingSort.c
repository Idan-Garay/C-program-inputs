#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printArr(int arr[], int size);
void countingSort(int arr[], int size);

int main()
{
        int arr[] = {1, 0, 3, 1, 3, 1};

        countingSort(arr, 6);

        return 0;
}

void countingSort(int arr[], int size)
{
        int x, max;
        int output[size];

        max = arr[0];
        for (x = 1; x < size; x++)
        {
                if (arr[x] > max)
                {
                        max = arr[x];
                }
        }

        int counter[max + 1];
        memset(counter, 0, sizeof(counter));

        for (x = 0; x < size; x++)
        {
                counter[arr[x]]++;
        }

        for (x = 1; x <= max; x++)
        {
                counter[x] += counter[x - 1];
        }

        for (x = size - 1; x >= 0; x--)
        {
                output[--counter[arr[x]]] = arr[x];
        }

        for (x = 0; x < size; x++)
        {
                arr[x] = output[x];
        }
        printArr(arr, size);
}

void printArr(int arr[], int size)
{
        int x;
        printf("\n");
        for (x = 0; x < size; x++)
        {
                printf(" %d,", arr[x]);
        }
}

/* 
    Algorithm: countingSort(array, size)
    step 1: max <- largest element in array
    step 2: countArray <- array of size max+1 where all elements are 0s.
    step 3: for x <- 0 to size
            countArray[array[x]]++;
    step 4: for x <- 1 to max
            countArray[x] <- countArray[x] + countArray[x-1];
    step 5: for j <- size until 1
            sortedArray[--countArray[array[j]]] <-  array[j]
    
    Algorithm: countingSort(array, size)
    step 1: get the max element of array
    step 2: determine the frequencies of each distinct values
            and store it in a count array.
    step 3: modify the count array such that each index stores
            the sum of current index's and its previous index's values.
    step 4: 

    Algorithm: countingSort(array, size)
   step 1: max <- largest element in array
   step 2: countArray <- array of size max+1 where all elements are 0s.
   step 3: for x <- 0 to size
           countArray[array[x]]++;
   step 4: for x <- 1 to max
           countArray[x] <- countArray[x] + countArray[x-1];
   step 5: for j <- size-1 down to 1
           sortedArray[countArray[array[j]]-1] <-  array[j]
         countArray[array[j]]--;

Algorithm: countingSort(arrayA, size)
   step 1: get the max element of array A
   step 2: determine the frequencies of each distinct values
           and store it in a count array C.
   step 3: starting from the 2nd index until size-1, modify the array C such
           that each index stores the sum of current index's and
           its previous index's values.
   step 4: starting at the end of the array A until 0, add the elements 
           to the new array using the frequencies in array C as its index
           which decrements for every addition.
           

starting at the end of the array

*/