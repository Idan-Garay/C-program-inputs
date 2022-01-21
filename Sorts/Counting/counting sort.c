#include<stdio.h>
#include<string.h>

void countingSort(int*,int,int);

int main()
{
    int n,i,k=0;
    printf("Enter number of elements:");
    scanf("%d",&n);
    int a[n];
    printf("\nEnter elements:\n");
    
    for(i=0;i<n;++i)
    {
    	scanf("%d",&a[i]);
    	if(a[i]>k)
    	k=a[i];
    }
    
    countingSort(a,n,k);
    
    for(i=0;i<n;i++){
    	printf("%d ",a[i]);
	}
    
    return 0;
}

void countingSort(int a[],int n,int k)
{
	int i;
    int count[k+1];
    memset(count,0,sizeof(count));
    int b[n];
    
    for(i=0;i<n;i++){
     	++count[a[i]]; 
	}//count qty of the same element
	
	for(i=1;i<=k;i++){
	 	count[i] = count[i]+count[i-1]; 
	}//sum
	
	for(i=n-1;i>=0;i--){
	 	b[--count[a[i]]] = a[i]; 
	}//place in correct position
	
	for(i=0;i<n;i++){
		a[i] = b[i];  
	}//transfer
	
}



