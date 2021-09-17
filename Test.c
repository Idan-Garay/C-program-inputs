#include <stdio.h>
#include <math.h>

void reduce(int* whole,int* num, int* denom){
	int num1=*num,num2=*denom;
	
	//Get whole number
	if(num1>num2){
		*whole=num1/num2;
		*num%=num2;
	}
	
	//Get the GCF
	num1=*num;
	while(num1!=num2){
        if(num1 > num2)
            num1 -= num2;
        else
            num2 -= num1;
    }
    
    //Divide numerator and denominator by GCF
    *num/=num1;
    *denom/=num1;
    
}

int main() {
    double number,left;
    int denom = 10000,num,whole;
    
    //Input decimal value to convert
    printf("\nEnter decimal to convert: ");
    scanf("%lf",&number);
    
    //Get the left value of decimal 
    left = (number - floor(number)) * denom;
    
    //Get numerator
    num = (int)floor(number) * denom + (int)(left);
    
    //Get reduce numerator and get equivalent denominator
    for(;num%10==0;num/=10,denom/=10){}
	
	//Reduce to lowest term
	reduce(&whole,&num,&denom);
	
	//Printing Result
    printf("\nFraction : %d %d/%d", whole, num, denom);
    
    return 0;
}