#include <stdio.h>  
#include <conio.h>  
void main()  
{  
    int num, i, sum = 0; // declare local variables  
    printf(" Enter a positive number: ");  
    scanf("%d", &num); // take any positive number  
    for (i = 0; i <= num; i++)  
    {  
        sum = sum + i; // at each iteration the value of i is added to the sum variable  
    }  
    // display the sum of natural number  
    printf("\n Sum of the first %d number is: %d", num, sum);   
    getch();  
}  
