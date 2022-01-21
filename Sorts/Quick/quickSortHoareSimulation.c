#include<stdio.h>
#include<stdbool.h>

void quickSort(int[], int, int);
int partition(int[], int, int);
void printArray(int[], int);

int main(){ 
    int arr[] = {20, 8, 5, 32, 12, 30, 23, 35, 50, 13, 1, 27, 10}; 
	int size = sizeof(arr)/sizeof(arr[0]); 
	printf("INITIAL ARRAY: \n"); 
    printArray(arr, size); 
	quickSort(arr, 0, size - 1);
	 
    printf("FINAL SORTED ARRAY: \n"); 
    printArray(arr, size); 
    
	return 0; 
}  

void quickSort(int arr[], int low, int high){ 
    if (low < high){
        int pi = partition(arr, low, high); 
		printf("pi = %d\n", pi); 
        quickSort(arr, low, pi); 
        quickSort(arr, pi + 1, high); 
    }else{
    	printf("partition sorted\n");
	}
} 

int partition(int arr[], int low, int high){ 
    int pivot = arr[(low + high)/2]; 
    int i = low, j = high, swap; 
   
    printf("i = %d\n", i);
    printf("j = %d\n", j);  
    
	printf("PIVOT = %d\n", pivot);
	
	getch();
    while(true){ 
        while(arr[i] < pivot){ 
            i++;
			printf("i = %d\n", i); 
			getch();
        }
        printf("j = %d\n", j);
        while(arr[j] > pivot){ 
            j--;
			printf("j = %d\n", j);  
			getch();
        }
        if (i >= j ){
        	return j;
		} 
        swap = arr[i];
        arr[i] = arr[j];
        arr[j] = swap;
        printf("CURRENT PIVOT = %d\n", pivot);
        printf("CURRENT ARRAY = ");
        printArray(arr, 13);
		getch(); 
    } 
} 

void printArray(int arr[], int size){ 
	int i;
    for (i = 0; i < size; i++) 
        printf("%d/%d ", arr[i], i); 
    printf("\n"); 
} 
   

