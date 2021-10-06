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
