#include <stdio.h>
/*Create a macro called MAX_SIZE that has a value of 5*/
#define MAX_SIZE 5

int main()
{
    int size = 0; 
    size += MAX_SIZE;

    #undef MAX_SIZE
    //#define MAX_SIZE 4
    //#undef MAX_SIZE
    printf("\n The value of size is [%d]\n",size);

    /*This line of code will give me an error. Bacially undef (as shown above)
    does exactly what sounds like it un defines the macro MAX_SIZE*/
    printf("\n The value of size is [%d]\n", MAX_SIZE);

   return 0;
}