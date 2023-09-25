#include <stdio.h>

/*https://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)Macros.html*/

/*This is an example of a multi expression macro that uses a ternary 
operator
Condition ? expression1 : expression2 - if condition is true execute expression1
otherwise execute expression2*/
#define min(x, y)  ((x) < (y) ? (x) : (y))


/*Referred to as non-syntactic code - meaning it is no syntactically correct C*/
#define UpTo(i,n) for(int i= 0; i < n; i++)


int main()
{
    int num1 = 5;
    int num2 = 10;

    printf("%d\n",  min(num1, num2));

    char a = '5';
    char b = 'd';

    /*This illustrates that min can be used with multiple types of data*/
    printf("a: %c = %d, b: %c = %d, min %c = min %d\n",  a, a, b, b, min(a, b), 
                                                         min(a, b));
    printf("num1: %d, num2: %d, min(num1,num2): %d\n", num1, num2, 
                                                       min(num1, num2));
  
    int m = 5;

    UpTo(i,m)
    {
        printf ("%d", i);
        /*This is just to illustrate this can be treated just like a regular 
         *for loop*/
        printf(" ");
    } 
    printf("\n");
    
    return 0;
    
}