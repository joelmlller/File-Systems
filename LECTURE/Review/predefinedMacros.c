#include <stdio.h>
//https://www.geeksforgeeks.org/interesting-facts-preprocessors-c/

/*These are all predefined macros provided to us by C*/

int main() 
{ 
    printf("Current File: %s\n", __FILE__ ); 
    /*__DATE__ and __Time__ actually print the time the program was last
     *compiled*/
    printf("Current Date: %s\n", __DATE__ ); 
    printf("Current Time: %s\n", __TIME__ ); 
    printf("Line Number: %d\n",  __LINE__ );
    //__func__ is often referred to predfined identifier rather than a macro
    printf("The current Function: %s\n", __func__);
    
    return 0; 
} 
/*
Current File: predefinedMacros.c
Current Date: Feb  5 2023
Current Time: 09:46:39
Line Number: 11
The current Function: main
*/
