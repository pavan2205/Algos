// Sum of digits of a number by recursive method
#include<stdio.h>
 int sumofdigits( long int x);

int main(){
   long int n;
 printf("Enter the number:");
 scanf("%d",&n);
 printf("Sum of digits is:%d",sumofdigits(n));    
    return 0;
}

int sumofdigits( long int x){
    
    if((x/10)==0)            // n is a single digit number
    return x;
    return (x%10)+sumofdigits(x/10);        

 }
 
