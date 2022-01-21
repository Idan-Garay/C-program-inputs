#include<stdio.h> 

void quickSort(int[], int, int);
int partition (int[], int, int);
void printArray(int[], int);

int main(void){ 
    int arr[] = {10, 80, 30, 90, 40, 50, 70};
    int size = sizeof(arr)/sizeof(arr[0]);
	printf("QUICK SORT ALGORITHM\n");
	printf("ORIGINAL ARRAY: ");
	printArray(arr, size);
	printf("\t\t0  1  2  3  4  5  6\n"); 
    quickSort(arr, 0, size-1); 
    printf("\n\nFINAL SORTED ARRAY: \n"); 
    printArray(arr, size); 
    return 0; 
} 

void quickSort(int arr[], int low, int high){ 
    if (low < high){
        int pi = partition(arr, low, high); 
        printf("\nPARTITION INDEX = %d\n", pi);
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 

int partition (int arr[], int low, int high){ 
    int pivot = arr[high];
    int i = (low - 1), j, swap, sortOrder = 1;
  	
    for (j = low; j <= high - 1; j++){
		
		if(sortOrder==1){
			printf("----------------------------------------");
			printf("\n");
		}
		getch();
  		printf("\nSORT ORDER %d\n", sortOrder);
  		sortOrder++;
        if (arr[j] < pivot){ 
            i++;
            swap = arr[i];
            arr[i] = arr[j];
            arr[j] = swap;
            printf("CURRENT PIVOT (arr[%d]) = %d\n", high, pivot);
            printf("i = %d\t j = %d (j must not be greater than %d)\n", i, j, high-1);
            printf("arr[%d] < PIVOT (TRUE)\n", j, pivot);
            printf("arr[%d] AND arr[%d] ARE SWAPPED\n", i, j);
            printf("CURRENT ARRAY: ");
            printArray(arr, 7);
            printf("\t       0  1  2  3  4  5  6\n");
			getch(); 
        }else{
        	printf("CURRENT PIVOT (arr[%d]) = %d\n", high, pivot);
        	printf("i = %d\t j = %d (j must not be greater than %d)\n", i, j, high-1);
			printf("arr[%d] < PIVOT (FALSE) THEREFORE DO NOTHING\n", j, pivot);
			getch(); 
		}
    }
	swap = arr[i + 1];
	arr[i + 1] = arr[high];
	arr[high] = swap;
	printf("\nSORT ORDER %d\n", sortOrder);
	printf("CURRENT PIVOT (arr[%d]) = %d\n", high, pivot);
	printf("i = %d\t j = %d (j must not be greater than %d)\n", i, j, high-1);
	printf("Since j is now greater than %d, we go out of the loop to swap elements further\n", high-1);
	printf("arr[%d+1] AND arr[%d] ARE SWAPPED\n", i, high);
	printf("CURRENT ARRAY: ");
    printArray(arr, 7);
    printf("\t       0  1  2  3  4  5  6\n");
    return (i + 1); 
} 
  
void printArray(int arr[], int size){ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
}

